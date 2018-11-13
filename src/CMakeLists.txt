#CMake version:
#--------------
# You can target a minimum version of CMake with the CMakeLists.txt scripts, 
# by using the cmake_minimum_required command (at the beginning of the script).
# If the installed CMake version is lower than the specified version the parsing of the scripts stops with an error

cmake_minimum_required(VERSION 3.8)

# Setting variables:
#-------------------
# Build variables, cache and environment variables can all be set with the same command 'set'.
# The variable name comes first, then the value and then additional possible arguments
# To refer to a variable you must enclose it between ${}. In case of environment variables, they must be specified within ENV{}

# There are pre-defined variables that are used for various purposes. In our top-level script, we will use some of these:
#  - CMAKE_CXX_FLAGS: flags to be used when compiling C++ files
#  - CMAKE_SOURCE_DIR: indicates the top level of the source tree
#  - CMAKE_ARCHIVE_OUTPUT_DIRECTORY: where to put the archive file(s) when built ( here archive file means a static library .lib or .a)
#  - CMAKE_LIBRARY_OUTPUT_DIRECTORY: where to put the library file(s) when built ( here library file  means a loaddble module .dll/.so )
#  - CMAKE_RUNTIME_OUTPUT_DIRECTORY: where to put the runtime file(s) when built ( here runtime file  means an exutable file like a  .exe)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} /EHc /std::c++latest)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin") 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY, "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

# Adding subdirectories:
#-----------------------
# When your code is organized in multiple directories, you can add subdirectories to the build with the command add_subdirectory.
# add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
# The only mandatory argument is a directory name or path. This directory must contain a CMakeLists.txt script, 
# which will be processed immediately by the CMake, before it continues with the current input script.

add_subdirectory(app)
add_subdirectory(lib_util)
add_subdirectory(lib_shared)

# Setting build dependencies:
#----------------------------
# The build order of the targets is usually important, as some targets must be built before others.
# Dependencies between targets in terms of build order can be specified with the add_dependencies command
# add_dependencies(<target> [<target-dependency>]...)
# All the targets specified with this command must be top level targets created with add_executable(), add_library() or add_custom_target()

add_dependencies(libshared libutil)
add_dependencies(app libshared)

# Setting Properties:
#--------------------
# You can set values for named properties in a given scope using the set_property command.
# This command takes an optional scope and a mandatory PROPERTY optione followed by the name of the property and its value or values.
# set_property(<GLOBAL                            |
#               DIRECTORY [dir]                   |
#               TARGET    [target1 [target2 ...]] |
#               SOURCE    [src1 [src2 ...]]       |
#               INSTALL   [file1 [file2 ...]]     |
#               TEST      [test1 [test2 ...]]     |
#               CACHE     [entry1 [entry2 ...]]>
#              [APPEND] [APPEND_STRING]
#              PROPERTY <name> [value1 [value2 ...]])

# Here the scope is the top level of the source tree (${CMAKE_CURRENT_SOURCE_DIR})
# the name of the property is VS_STARTUP_PROJECT and the value is app
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT app) # set app target to be the startup project