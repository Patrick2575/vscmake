#CMake version:
#--------------
# You can target a minimum version of CMake with the CMakeLists.txt scripts, 
# by using the cmake_minimum_required command (at the beginning of the script).
# If the installed CMake version is lower than the specified version the parsing of the scripts stops with an error

cmake_minimum_required(VERSION 3.8)

# Preprocessor definitions:
#-------------------------
# Preprocessor definitions can be added with the add_definitions command.
# The name must be prefixed with -D.
add_definitions(-DEXPMODULE)


# Add include directories:
#----------------------
# Directories can be added to the list of include directories using the command include_directories
# include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
# di1, dir2 .. are then added to INCLUDE_DIRECTORY property for the current CMakeLists.txt and they are

include_directories(${CMAKE_SOURCE_DIR}/lib_util)
include_directories(${CMAKE_SOURCE_DIR}/global)

# create this target:
#-------------------
# You can add libraries to the build using the add_library  command
# add_library(<name> [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 [source2 ...])
# <name> is the name of the target to be built from the list of specified sources.
# It is a logical target name and must be unique within the project
# Flag
#   - STATIC (archives of object files used for linking other targets),
#   - SHARED (dynamically linked libraries) or 
#   - MODULE (plugins not linked into other targets but loaded dynamically at runtime) 
# can be specified to indicate the type of the library
# If none of these is specified, then STATIC or SHARED are implied, depending whether the variable BUILD_SHARED_LIBS is ON or OFF.
#
# The list of source files may contain both source and header files. 
# Note that only the files listed with the command will show up in the project when you generate one for Visual Studio

file(GLOB headers "*.h") # gather all .h files in directory into  headers variable
file(GLOB sources "*.cpp") # gather all .cpp files in directory into  sources variable
add_library(libshared SHARED ${headers} ${sources}) # add a target with name 'libutil'

# Add linking directories :
#-------------------------
# Directories can be added to the list of linking directories using the command link_directories
# link_directories(directory1 directory2 ...)
# The directories specified with the link_directories are applied only to targets created after the command. 
# Therefore it is important to use this command before add_library or add_executable

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# linking with libraries :
#------------------------
# You can specify library dependencies or linking flags for a target using the command target_link_libraries
# target_link_libraries(<target> ... <item>... ...)
#    <target> must have been previously created with either add_library() or add_executable()
#    <item> can be a library name or a full path to a library file
#
# Keyword
#   - debug : refers to the debug configuration and 
#   - optimized: to all other configurations
# The use of debug and optimized keywords preceding an item is useful for specifying different targets for different configurations

target_link_libraries(libshared debug libutil.lib) #  debug configuration
target_link_libraries(libshared optimized libutil.lib) # release configuration

