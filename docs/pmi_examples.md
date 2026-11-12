# Precision-medicine examples

Tiny Slog programs over an electronic health record (the chart) joined with
a medical knowledge graph (ontologies, drug classes, interaction and
pharmacogenomic tables).  Each example is a few rules; they build on one
another in order, and every block below was run as one program against the
ten-patient sample at the end.  Days are integers from a study epoch.

```slog
;; The chart: one hospital's records (csv2db imports these by the million).
table (patient str int str str)      ;; id, age, sex, zip3
table (dx str str int)               ;; patient, condition, day
table (rx str str int)               ;; patient, drug, day of first fill
table (lab str str int float)        ;; patient, test, day, value
table (genotype str str str str)     ;; patient, gene, allele, allele

;; The knowledge graph: public reference knowledge shared by every site.
table (isa str str)                  ;; condition is-a parent (SNOMED-like)
table (drug_isa str str)             ;; drug or class is-a class (ATC-like)

;; Closures over the graph, computed only above the concepts a rule asks about.
demand (kind_of str) str
rule (kind_of C C)
rule (kind_of C A) <-- (isa C P) (kind_of P A)

demand (drug_class str) str
rule (drug_class D D)
rule (drug_class D C) <-- (drug_isa D P) (drug_class P C)
```










### 1. Query by concept, not by code list

```slog
;; This illustrates how the ontology bridges a coded chart and a clinical question.
table (has str str)
rule (dx P C _) (kind_of C Class) --> (has P Class)

table (diabetic_with_cvd str)
rule (has P "diabetes_mellitus") (has P "cardiovascular_disease") --> (diabetic_with_cvd P)
```










### 2. Drug interaction alerts from class-level knowledge

```slog
;; This illustrates knowledge written once at the class level ("SSRIs with MAOIs")
;; firing for the specific drugs a patient is on.
table (interacts str str str)        ;; drug or class, drug or class, severity
rule (interacts A B S) --> (interacts B A S)

table (ddi_alert str str str str)
rule (rx P A _) (rx P B _) (/= A B) (drug_class A CA) (drug_class B CB) (interacts CA CB S)
  --> (ddi_alert P A B S)
```










### 3. Contraindications

```slog
;; This illustrates matching both sides of a rule up their respective hierarchies.
table (contraindicated str str)      ;; drug or class, condition or class

table (contra_alert str str str)
rule (rx P D _) (drug_class D DC) (dx P C _) (kind_of C CC) (contraindicated DC CC)
  --> (contra_alert P D C)
```










### 4. Pharmacogenomics: genotype to phenotype to guidance

```slog
;; This illustrates demand: a genotype is interpreted only for the patient-gene
;; pairs where a prescribed drug makes it matter.
enum (metabolizer poor intermediate normal ultrarapid)
table (allele_activity str str float);; gene, allele, CPIC activity value
table (drug_gene str str)            ;; drug, gene governing its metabolism
table (cpic str metabolizer str)     ;; drug, phenotype, guidance

demand (activity_score str str) float
rule (activity_score P G (+ S1 S2))
  <-- (genotype P G A1 A2) (allele_activity G A1 S1) (allele_activity G A2 S2)

demand (phenotype str str) metabolizer
rule (phenotype P G (poor))         <-- (= S (activity_score P G)) (< S 0.25)
rule (phenotype P G (intermediate)) <-- (= S (activity_score P G)) (>= S 0.25) (<= S 1.0)
rule (phenotype P G (normal))       <-- (= S (activity_score P G)) (> S 1.0) (<= S 2.25)
rule (phenotype P G (ultrarapid))   <-- (= S (activity_score P G)) (> S 2.25)

table (pgx_alert str str str)
rule (rx P D _) (drug_gene D G) (cpic D (phenotype P G) Advice) --> (pgx_alert P D Advice)
```










### 5. A computable phenotype (type 2 diabetes, after eMERGE)

```slog
;; This illustrates a published phenotype flowchart as rules: evidence boxes are
;; rules, "but not type 1" is stratified negation, onset is a min lattice.
table (t2dm_evidence str str int)    ;; patient, kind of evidence, day
rule (dx P C D) (kind_of C "type_2_diabetes") --> (t2dm_evidence P "diagnosis" D)
rule (rx P Drug D) (drug_class Drug "antidiabetic") --> (t2dm_evidence P "medication" D)
rule (lab P "hba1c" D1 V1) (lab P "hba1c" D2 V2) (< D1 D2) (>= V1 6.5) (>= V2 6.5)
  --> (t2dm_evidence P "two_hba1c" D2)

table (type1 str)
rule (dx P C _) (kind_of C "type_1_diabetes") --> (type1 P)

lattice (earliest (min int #:floor 0))
table (t2dm_onset str earliest)
rule (t2dm_evidence P _ D) ~(type1 P) --> (t2dm_onset P D)
```










### 6. Trial eligibility, with explanations

```slog
;; This illustrates eligibility criteria as one rule; at the REPL,
;; `whynot (eligible "p4" "NCT0001")` names the first criterion that failed.
table (eligible str str)
rule (patient P Age _ _) (>= Age 40) (<= Age 75)
     (t2dm_onset P _) ~(type1 P) ~(has P "chronic_kidney_disease")
  --> (eligible P "NCT0001")
```










### 7. Medication regimens as values

```slog
;; This illustrates a set-valued column: a patient's regimen is one canonical
;; value, so "same regimen" is a join and polypharmacy is a size.
lattice (drugset (set str))
table (regimen str drugset)
rule (rx P D _) (= One (cins (cmap) D)) --> (regimen P One)

table (polypharmacy str int)
rule (regimen P S) (>= (csize S) 4) --> (polypharmacy P (csize S))

table (same_regimen str str)
rule (regimen P S) (regimen Q S) (/= P Q) --> (same_regimen P Q)
```










### 8. Exposure episodes from refills

```slog
;; This illustrates temporal reasoning: fills within 30 days of a running episode
;; extend it (a max lattice), and only unabsorbed starts survive.
table (fill str str int int)         ;; patient, drug, start, end
lattice (latest (max int))
table (episode str str int latest)   ;; patient, drug, first start, running end
rule (fill P D S E) --> (episode P D S E)
rule (episode P D S E) (fill P D S2 E2) (> S2 S) (<= S2 (+ E 30)) --> (episode P D S E2)

table (absorbed str str int)
rule (episode P D S E) (fill P D S2 _) (> S2 S) (<= S2 (+ E 30)) --> (absorbed P D S2)

table (exposure str str int int)
rule (episode P D S E) ~(absorbed P D S) --> (exposure P D S E)
```










### 9. Who is treating whom, and what is protected

```slog
;; This illustrates relationships that propagate (delegation) and a legal
;; category decided by the ontology rather than by a maintained code list.
table (care_team str str)            ;; clinician, patient
table (delegates str str)            ;; attending, covering clinician
table (treating str str)
rule (care_team U P) --> (treating U P)
rule (delegates U V) (treating U P) --> (treating V P)

table (sensitive_root str)           ;; "mental_disorder", "hiv_infection", ...
table (protected str)
rule (dx _ C _) (kind_of C Root) (sensitive_root Root) --> (protected C)
```










### 10. Access policy: permit minus deny

```slog
;; This illustrates deny-overrides access control: permit rules and deny rules
;; are written independently, and the visible chart is one negation.
table (consent str str)              ;; patient, clinician
table (suspended str)
table (break_glass str str)          ;; clinician, patient (emergency override)

table (permit str str str)           ;; clinician, patient, condition
rule (treating U P) (dx P C _) --> (permit U P C)
rule (break_glass U P) (dx P C _) --> (permit U P C)

table (deny str str str str)
rule (permit U P C) (suspended U) --> (deny U P C "suspended")
rule (permit U P C) (protected C) ~(consent P U) ~(break_glass U P)
  --> (deny U P C "protected category without consent")

table (visible str str str)
rule (permit U P C) ~(deny U P C _) --> (visible U P C)
```










### 11. The audit trail is just more rules

```slog
;; This illustrates that every decision, including a refusal, is a derived fact
;; with a derivation behind it (`why (visible "dr_kim" "p3" C)` at the REPL).
table (request str str)              ;; clinician opens a chart
table (audit str str str)
rule (request U P) (deny U P C Why) --> (audit U P (+ (+ "withheld " C) (+ ": " Why)))
rule (request U P) (break_glass U P) --> (audit U P "emergency override used")
rule (request U P) ~(permit U P _) --> (audit U P "denied: no relationship")
```










### 12. A research release with k-anonymity

```slog
;; This illustrates a de-identified release as a derived relation: generalize,
;; drop opt-outs and protected categories, suppress rare cells.
table (opt_out str)
table (qi str int str str)           ;; patient, age decade, sex, zip3
rule (patient P Age Sex Zip) ~(opt_out P) --> (qi P (* 10 (/ Age 10)) Sex Zip)

lattice (people (set str))
table (cell int str str people)
rule (qi P A S Z) (= One (cins (cmap) P)) --> (cell A S Z One)

table (releasable str)
rule (qi P A S Z) (cell A S Z Set) (>= (csize Set) 2) --> (releasable P)

table (release_dx str str int)
rule (releasable P) (dx P C D) ~(protected C) --> (release_dx P C D)
```










### 13. A new-user cohort: arms and index dates

```slog
;; This illustrates a study design as rules: first fill is a min lattice, and
;; "never used the comparator" is negation over its key.
table (first_fill str str earliest)
rule (rx P D Day) --> (first_fill P D Day)

table (arm str str int)              ;; patient, drug, index day
rule (first_fill P "metformin" Day) ~(first_fill P "glipizide") --> (arm P "metformin" Day)
rule (first_fill P "glipizide" Day) ~(first_fill P "metformin") --> (arm P "glipizide" Day)
```










### 14. Outcomes in a follow-up window, prior events excluded

```slog
table (cv_event str int)
rule (dx P C Day) (kind_of C "cardiovascular_disease") --> (cv_event P Day)

table (prior_event str)
rule (arm P _ I) (cv_event P Day) (<= Day I) --> (prior_event P)

table (outcome str)
rule (arm P _ I) ~(prior_event P) (cv_event P Day) (> Day I) (<= Day (+ I 365)) --> (outcome P)
```










### 15. The 2x2 table and a risk ratio

```slog
;; This illustrates counting: each cell is a set of patients, measured only after
;; the compiler has closed it.
table (cohort str str people)        ;; arm, "event" or "no_event", patients
rule (arm _ A _) (= Empty (cmap)) --> (cohort A "event" Empty) (cohort A "no_event" Empty)
rule (arm P A _) ~(prior_event P)  (outcome P) (= S (cins (cmap) P)) --> (cohort A "event" S)
rule (arm P A _) ~(prior_event P) ~(outcome P) (= S (cins (cmap) P)) --> (cohort A "no_event" S)

table (risk str float)
rule (cohort A "event" E) (cohort A "no_event" N) (> (+ (csize E) (csize N)) 0)
  --> (risk A (/ (tofloat (csize E)) (tofloat (+ (csize E) (csize N)))))

table (risk_ratio float)
rule (risk "metformin" Ra) (risk "glipizide" Rb) (> Rb 0.0) --> (risk_ratio (/ Ra Rb))
```










### 16. Reconciling source systems

```slog
;; This illustrates a flat lattice: one agreed value, or (top) when sources
;; disagree, surfaced for review instead of a silently chosen winner.
table (source_sex str str str)       ;; source system, patient, value
lattice (agreed (flat str))
table (sex_on_file str agreed)
rule (source_sex _ P V) --> (sex_on_file P V)

table (needs_review str)
rule (sex_on_file P V) (= V (top)) --> (needs_review P)
```










### Running

Everything above as one program, with the sample below appended:

```
racket compiler/run.rkt --no-banner --sizes --debug-dir out/pmi pmi.slog
```

For a real chart, import delimited exports with `racket compiler/csv2db.rkt
exports/ ehr` and run the same program with `-d ehr`.  In a live session,
adding or retracting a `consent` or `care_team` row re-derives `visible` and
`audit`; `why` and `whynot` at the REPL explain any derived fact.

### Sample data

```slog
rule
(patient "p1" 67 "F" "991") (patient "p2" 72 "M" "991") (patient "p3" 45 "F" "980")
(patient "p4" 58 "M" "980") (patient "p5" 30 "F" "972") (patient "p6" 67 "M" "991")
(patient "p7" 71 "M" "991") (patient "p8" 66 "M" "991") (patient "p9" 69 "M" "991")
(dx "p1" "type_2_diabetes" 100) (dx "p1" "myocardial_infarction" 400)
(dx "p2" "chronic_kidney_disease" 10) (dx "p2" "stroke" 300) (dx "p3" "major_depression" 20)
(dx "p4" "type_1_diabetes" 5) (dx "p5" "hiv_infection" 15) (dx "p7" "myocardial_infarction" 20)
(dx "p8" "type_2_diabetes" 85) (dx "p9" "stroke" 200)
(rx "p1" "metformin" 120) (rx "p1" "atorvastatin" 130) (rx "p2" "glipizide" 50) (rx "p2" "metformin" 60)
(rx "p3" "sertraline" 30) (rx "p3" "tramadol" 200) (rx "p4" "insulin_glargine" 6) (rx "p6" "glipizide" 80)
(rx "p7" "glipizide" 40) (rx "p7" "warfarin" 25) (rx "p7" "aspirin" 26) (rx "p8" "metformin" 90)
(rx "p8" "phenelzine" 100) (rx "p8" "fluoxetine" 110) (rx "p8" "codeine" 150) (rx "p9" "glipizide" 30)
(lab "p1" "hba1c" 95 7.4) (lab "p1" "hba1c" 200 7.9) (lab "p4" "hba1c" 10 8.1) (lab "p4" "hba1c" 100 8.4)
(lab "p5" "hba1c" 40 5.4) (lab "p6" "hba1c" 70 6.9) (lab "p6" "hba1c" 150 7.1)
(genotype "p1" "CYP2D6" "*1" "*4") (genotype "p3" "CYP2D6" "*1xN" "*2") (genotype "p8" "CYP2D6" "*4" "*4")
(fill "p1" "metformin" 120 150) (fill "p1" "metformin" 160 190) (fill "p1" "metformin" 300 330)

rule
(isa "type_2_diabetes" "diabetes_mellitus") (isa "type_1_diabetes" "diabetes_mellitus")
(isa "diabetes_mellitus" "endocrine_disorder") (isa "myocardial_infarction" "ischemic_heart_disease")
(isa "ischemic_heart_disease" "cardiovascular_disease") (isa "stroke" "cardiovascular_disease")
(isa "major_depression" "mood_disorder") (isa "mood_disorder" "mental_disorder")
(isa "hiv_infection" "infectious_disease") (isa "chronic_kidney_disease" "renal_disorder")
(drug_isa "metformin" "biguanide") (drug_isa "biguanide" "antidiabetic")
(drug_isa "glipizide" "sulfonylurea") (drug_isa "sulfonylurea" "antidiabetic")
(drug_isa "insulin_glargine" "antidiabetic") (drug_isa "sertraline" "ssri") (drug_isa "fluoxetine" "ssri")
(drug_isa "phenelzine" "maoi") (drug_isa "codeine" "opioid") (drug_isa "tramadol" "opioid")
(interacts "ssri" "maoi" "contraindicated") (interacts "ssri" "tramadol" "major") (interacts "warfarin" "aspirin" "major")
(contraindicated "metformin" "chronic_kidney_disease")
(sensitive_root "mental_disorder") (sensitive_root "hiv_infection")
(allele_activity "CYP2D6" "*1" 1.0) (allele_activity "CYP2D6" "*2" 1.0) (allele_activity "CYP2D6" "*4" 0.0)
(allele_activity "CYP2D6" "*1xN" 2.0) (drug_gene "codeine" "CYP2D6") (drug_gene "tramadol" "CYP2D6")
(cpic "codeine" (poor) "avoid codeine: no analgesic effect") (cpic "tramadol" (ultrarapid) "avoid tramadol: toxicity risk")
(care_team "dr_kim" "p1") (care_team "dr_kim" "p3") (care_team "dr_lee" "p2") (care_team "nurse_bo" "p1")
(delegates "dr_kim" "res_ana") (consent "p3" "dr_kim") (suspended "nurse_bo") (break_glass "dr_ed" "p5")
(request "dr_kim" "p3") (request "res_ana" "p3") (request "nurse_bo" "p1") (request "dr_ed" "p5") (request "dr_lee" "p1")
(opt_out "p6")
(source_sex "registration" "p1" "F") (source_sex "lab_feed" "p1" "F")
(source_sex "registration" "p2" "M") (source_sex "lab_feed" "p2" "F")
```
