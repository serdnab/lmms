IF(WIN32)
	SET(LMMS_BUILD_WIN32 1)
ELSEIF(APPLE)
	SET(LMMS_BUILD_APPLE 1)
ELSEIF(HAIKU)
	SET(LMMS_BUILD_HAIKU 1)
ELSE()
	SET(LMMS_BUILD_LINUX 1)
ENDIF(WIN32)

IF(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
	SET(LMMS_BUILD_CLANG 1)
ENDIF()

MESSAGE("PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
SET(LMMS_HOST_X86 FALSE)
SET(LMMS_HOST_X86_64 FALSE)

IF(WIN32)
	IF(WIN64)
		SET(IS_X86_64 TRUE)
		SET(LMMS_BUILD_WIN64 TRUE)
	ELSE(WIN64)
		SET(IS_X86 TRUE)
	ENDIF(WIN64)
ELSE(WIN32)
	EXEC_PROGRAM( ${CMAKE_C_COMPILER} ARGS "-dumpmachine ${CMAKE_C_FLAGS}" OUTPUT_VARIABLE Machine )
	MESSAGE("Machine: ${Machine}")
	STRING(REGEX MATCH "i.86" IS_X86 "${Machine}")
	STRING(REGEX MATCH "86_64" IS_X86_64 "${Machine}")
ENDIF(WIN32)

IF(IS_X86)
	MESSAGE("-- Target host is 32 bit")
	SET(LMMS_HOST_X86 TRUE)
ELSEIF(IS_X86_64)
	MESSAGE("-- Target host is 64 bit")
	SET(LMMS_HOST_X86_64 TRUE)
ELSE(IS_X86)
	MESSAGE("Can't identify target host. Assuming 32 bit platform.")
ENDIF(IS_X86)

IF(CMAKE_INSTALL_LIBDIR)
	SET(LIB_DIR "${CMAKE_INSTALL_LIBDIR}")
ELSE(CMAKE_INSTALL_LIBDIR)
	SET(LIB_DIR lib)
ENDIF(CMAKE_INSTALL_LIBDIR)


IF(LMMS_BUILD_WIN32)
	SET(BIN_DIR .)
	SET(PLUGIN_DIR plugins)
	SET(DATA_DIR data)
	SET(LMMS_DATA_DIR data)
ELSE(LMMS_BUILD_WIN32)
	SET(BIN_DIR bin)
	SET(PLUGIN_DIR ${LIB_DIR}/lmms)
	SET(DATA_DIR share)
	SET(LMMS_DATA_DIR ${DATA_DIR}/lmms)
ENDIF(LMMS_BUILD_WIN32)

IF(LMMS_BUILD_APPLE)
	# Detect Homebrew versus Macports environment
	EXECUTE_PROCESS(COMMAND brew --prefix RESULT_VARIABLE DETECT_HOMEBREW OUTPUT_VARIABLE HOMEBREW_PREFIX ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
	EXECUTE_PROCESS(COMMAND which port RESULT_VARIABLE DETECT_MACPORTS OUTPUT_VARIABLE MACPORTS_PREFIX ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
	IF(${DETECT_HOMEBREW} EQUAL 0)
       		SET(HOMEBREW 1)
        	SET(APPLE_PREFIX "${HOMEBREW_PREFIX}")
	ELSEIF(${DETECT_MACPORTS} EQUAL 0)
        	SET(MACPORTS 1)
        	GET_FILENAME_COMPONENT(MACPORTS_PREFIX ${MACPORTS_PREFIX} DIRECTORY)
		GET_FILENAME_COMPONENT(MACPORTS_PREFIX ${MACPORTS_PREFIX} DIRECTORY)
		SET(APPLE_PREFIX "${MACPORTS_PREFIX}")
        	LINK_DIRECTORIES(${LINK_DIRECTORIES} ${APPLE_PREFIX}/lib)
	ENDIF()

	# Detect OS Version
	EXECUTE_PROCESS(COMMAND sw_vers -productVersion OUTPUT_VARIABLE APPLE_OS_VER ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
	STRING(REGEX REPLACE "\\.[0-9]*$" "" APPLE_OS_VER "${APPLE_OS_VER}")
	SET(CMAKE_MACOSX_RPATH 1)	
ENDIF()
