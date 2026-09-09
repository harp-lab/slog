# Source from a test harness after changing to the repository root.
# Use the production toolchain, including macOS dependency paths and CXX
# overrides. Arrays preserve argument boundaries without evaluating shell code.
_native_config=$(make --no-print-directory -s -C daemon print-toolchain) || exit 1
{
  IFS= read -r NATIVE_CXX
  read -r -a NATIVE_CPPFLAGS
  read -r -a NATIVE_OMPFLAGS
  read -r -a NATIVE_LDFLAGS
  read -r -a NATIVE_PLUGIN_FLAGS
  read -r -a NATIVE_LIBS
} <<< "$_native_config"
unset _native_config

native_cxx() {
  local arg
  for arg in "$@"; do
    case "$arg" in
      -c|-fsyntax-only|-E)
        "$NATIVE_CXX" "${NATIVE_CPPFLAGS[@]}" "${NATIVE_OMPFLAGS[@]}" "$@"
        return $? ;;
    esac
  done
  "$NATIVE_CXX" "${NATIVE_CPPFLAGS[@]}" "${NATIVE_OMPFLAGS[@]}" \
    "$@" "${NATIVE_LDFLAGS[@]}" "${NATIVE_LIBS[@]}"
}
