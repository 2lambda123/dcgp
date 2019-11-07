IF(AUDI_INCLUDE_DIRS)
	# Already in cache, be silent
	SET(AUDI_FIND_QUIETLY TRUE)
ENDIF(AUDI_INCLUDE_DIRS)

FIND_PATH(AUDI_INCLUDE_DIRS audi/audi.hpp PATH_SUFFIXES include)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(Audi DEFAULT_MSG AUDI_INCLUDE_DIRS)

MARK_AS_ADVANCED(AUDI_INCLUDE_DIRS)

if(AUDI_INCLUDE_DIRS AND NOT TARGET Audi::audi)
    add_library(Audi::audi INTERFACE IMPORTED)
    set_target_properties(Audi::audi PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${AUDI_INCLUDE_DIRS}")
endif()