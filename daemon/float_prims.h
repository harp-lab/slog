
/** Slog Floating-Point Prims
 *
 * Binary64 (double) kernels.  These take already-decoded doubles; the
 * dispatchers in prims.h promote s32 operands to double as needed and encode
 * the result back into a NaN-boxed float value.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include <cmath>


// ---- arithmetic -----------------------------------------------------------

inline u64 _prim_float__0002b_unsafe(double a, double b) { return float_encode(a + b); } // +
inline u64 _prim_float__0002d_unsafe(double a, double b) { return float_encode(a - b); } // -
inline u64 _prim_float__0002a_unsafe(double a, double b) { return float_encode(a * b); } // *
inline u64 _prim_float__0002f_unsafe(double a, double b) { return float_encode(a / b); } // /
inline u64 _prim_float__00025_unsafe(double a, double b) { return float_encode(std::fmod(a, b)); } // %

inline u64 _prim_float_neg_unsafe(double a) { return float_encode(-a); }
inline u64 _prim_float_abs_unsafe(double a) { return float_encode(std::fabs(a)); }
inline u64 _prim_float_min_unsafe(double a, double b) { return float_encode(a < b ? a : b); }
inline u64 _prim_float_max_unsafe(double a, double b) { return float_encode(a > b ? a : b); }
inline u64 _prim_float_pow_unsafe(double a, double b) { return float_encode(std::pow(a, b)); }


// ---- transcendental / rounding (arg promoted to double) -------------------

inline u64 _prim_float_sqrt_unsafe(double a)  { return float_encode(std::sqrt(a)); }
inline u64 _prim_float_sin_unsafe(double a)   { return float_encode(std::sin(a)); }
inline u64 _prim_float_cos_unsafe(double a)   { return float_encode(std::cos(a)); }
inline u64 _prim_float_tan_unsafe(double a)   { return float_encode(std::tan(a)); }
inline u64 _prim_float_exp_unsafe(double a)   { return float_encode(std::exp(a)); }
inline u64 _prim_float_log_unsafe(double a)   { return float_encode(std::log(a)); }
inline u64 _prim_float_floor_unsafe(double a) { return float_encode(std::floor(a)); }
inline u64 _prim_float_ceil_unsafe(double a)  { return float_encode(std::ceil(a)); }
inline u64 _prim_float_round_unsafe(double a) { return float_encode(std::round(a)); }
