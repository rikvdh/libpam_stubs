cmake_minimum_required(VERSION 2.8.7)

project(pam_stubs C)
set(PROJECT_VERSION 0.1.0)

option(ENABLE_CODECOVERAGE "ENABLE_CODECOVERAGE" OFF)

include(CTest)
include(CheckIncludeFiles)
include("cmake/add_cflag_if_supported.cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if(${ENABLE_CODECOVERAGE} MATCHES "ON")
	message(STATUS "Code-coverage enabled")
	set(CMAKE_C_FLAGS "--coverage -fprofile-arcs -ftest-coverage")
	set(CMAKE_CXX_FLAGS "--coverage -fprofile-arcs -ftest-coverage")
endif()

add_cflag_if_supported("-std=gnu99")
add_cflag_if_supported("-Wall")
add_cflag_if_supported("-Wextra")
add_cflag_if_supported("-Wshadow")
add_cflag_if_supported("-D_FORTIFY_SOURCE=2")
add_cflag_if_supported("-fstrict-aliasing=1")
add_cflag_if_supported("-Wformat")
add_cflag_if_supported("-Wformat-security")
#add_cflag_if_supported("-Wno-sign-conversion")
#add_cflag_if_supported("-Wconversion")
#add_cflag_if_supported("-Wcast-qual")
#add_cflag_if_supported("-Wmisleading-indentation")
#add_cflag_if_supported("-Wno-float-conversion")
add_cflag_if_supported("-Wmaybe-uninitialized")
add_cflag_if_supported("-Wmissing-variable-declarations")
add_cflag_if_supported("-Wshorten-64-to-32")
add_cflag_if_supported("-Wimplicit-function-declaration")
add_cflag_if_supported("-Wredundant-decls")
add_cflag_if_supported("-Wundef")
#add_cflag_if_supported("-Werror")
add_cflag_if_supported("-Wl,-z,relro")
add_cflag_if_supported("-Wl,-z,now")
add_cflag_if_supported("-fPIC")

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    include(CTest)
    add_cflag_if_supported("-ggdb")
    add_cflag_if_supported("-O0")
elseif()
    add_cflag_if_supported("-O2")
endif()

check_include_files(pam_appl.h HAVE_PAM_APPL_H)
check_include_files(security/pam_appl.h HAVE_SECURITY_PAM_APPL_H)
check_include_files(pam_modules.h HAVE_PAM_MODULES_H)
check_include_files(security/pam_modules.h HAVE_SECURITY_PAM_MODULES_H)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include )

set(CFILES 
	src/pam_strerror.c
	src/pam_get_data.c
	src/pam_set_data.c
	src/pam_get_item.c
	src/pam_set_item.c
	src/pam_get_user.c)

add_library(${PROJECT_NAME} SHARED ${CFILES})
