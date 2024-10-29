#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "wit_pkg::serial" for configuration ""
set_property(TARGET wit_pkg::serial APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(wit_pkg::serial PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libserial.so."
  IMPORTED_SONAME_NOCONFIG "libserial.so."
  )

list(APPEND _cmake_import_check_targets wit_pkg::serial )
list(APPEND _cmake_import_check_files_for_wit_pkg::serial "${_IMPORT_PREFIX}/lib/libserial.so." )

# Import target "wit_pkg::wit_c_sdk" for configuration ""
set_property(TARGET wit_pkg::wit_c_sdk APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(wit_pkg::wit_c_sdk PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libwit_c_sdk.so."
  IMPORTED_SONAME_NOCONFIG "libwit_c_sdk.so."
  )

list(APPEND _cmake_import_check_targets wit_pkg::wit_c_sdk )
list(APPEND _cmake_import_check_files_for_wit_pkg::wit_c_sdk "${_IMPORT_PREFIX}/lib/libwit_c_sdk.so." )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
