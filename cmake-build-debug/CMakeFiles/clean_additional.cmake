# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SmartPointers_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SmartPointers_autogen.dir\\ParseCache.txt"
  "SmartPointers_autogen"
  )
endif()
