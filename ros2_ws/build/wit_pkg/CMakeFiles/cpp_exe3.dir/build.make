# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/DATA/DogRobot/ros2_ws/src/wit_pkg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/DATA/DogRobot/ros2_ws/build/wit_pkg

# Include any dependencies generated for this target.
include CMakeFiles/cpp_exe3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpp_exe3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp_exe3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp_exe3.dir/flags.make

CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o: CMakeFiles/cpp_exe3.dir/flags.make
CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o: /home/DATA/DogRobot/ros2_ws/src/wit_pkg/src/wit_c_sdk.c
CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o: CMakeFiles/cpp_exe3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/DATA/DogRobot/ros2_ws/build/wit_pkg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o -MF CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o.d -o CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o -c /home/DATA/DogRobot/ros2_ws/src/wit_pkg/src/wit_c_sdk.c

CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/DATA/DogRobot/ros2_ws/src/wit_pkg/src/wit_c_sdk.c > CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.i

CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/DATA/DogRobot/ros2_ws/src/wit_pkg/src/wit_c_sdk.c -o CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.s

# Object files for target cpp_exe3
cpp_exe3_OBJECTS = \
"CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o"

# External object files for target cpp_exe3
cpp_exe3_EXTERNAL_OBJECTS =

cpp_exe3: CMakeFiles/cpp_exe3.dir/src/wit_c_sdk.c.o
cpp_exe3: CMakeFiles/cpp_exe3.dir/build.make
cpp_exe3: /opt/ros/jazzy/lib/librclcpp.so
cpp_exe3: /opt/ros/jazzy/lib/liblibstatistics_collector.so
cpp_exe3: /opt/ros/jazzy/lib/librcl.so
cpp_exe3: /opt/ros/jazzy/lib/librmw_implementation.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_typesupport_fastrtps_c.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_typesupport_introspection_c.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_typesupport_fastrtps_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_typesupport_introspection_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_typesupport_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_generator_py.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_typesupport_c.so
cpp_exe3: /opt/ros/jazzy/lib/libtype_description_interfaces__rosidl_generator_c.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_typesupport_fastrtps_c.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_typesupport_fastrtps_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_typesupport_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_generator_py.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_typesupport_c.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_interfaces__rosidl_generator_c.so
cpp_exe3: /opt/ros/jazzy/lib/libservice_msgs__rosidl_typesupport_fastrtps_c.so
cpp_exe3: /opt/ros/jazzy/lib/libservice_msgs__rosidl_typesupport_introspection_c.so
cpp_exe3: /opt/ros/jazzy/lib/libservice_msgs__rosidl_typesupport_fastrtps_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libservice_msgs__rosidl_typesupport_introspection_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libservice_msgs__rosidl_typesupport_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libservice_msgs__rosidl_typesupport_c.so
cpp_exe3: /opt/ros/jazzy/lib/libservice_msgs__rosidl_generator_c.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_yaml_param_parser.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_c.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_generator_py.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_typesupport_c.so
cpp_exe3: /opt/ros/jazzy/lib/librosgraph_msgs__rosidl_generator_c.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_c.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_generator_py.so
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_typesupport_fastrtps_c.so
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_typesupport_fastrtps_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librmw.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_dynamic_typesupport.so
cpp_exe3: /opt/ros/jazzy/lib/libfastcdr.so.2.2.4
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_typesupport_introspection_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_typesupport_introspection_c.so
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_typesupport_cpp.so
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_generator_py.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_typesupport_c.so
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
cpp_exe3: /opt/ros/jazzy/lib/libstatistics_msgs__rosidl_generator_c.so
cpp_exe3: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_generator_c.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_typesupport_c.so
cpp_exe3: /opt/ros/jazzy/lib/librcpputils.so
cpp_exe3: /opt/ros/jazzy/lib/librosidl_runtime_c.so
cpp_exe3: /opt/ros/jazzy/lib/libtracetools.so
cpp_exe3: /opt/ros/jazzy/lib/librcl_logging_interface.so
cpp_exe3: /opt/ros/jazzy/lib/librcutils.so
cpp_exe3: CMakeFiles/cpp_exe3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/DATA/DogRobot/ros2_ws/build/wit_pkg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cpp_exe3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_exe3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp_exe3.dir/build: cpp_exe3
.PHONY : CMakeFiles/cpp_exe3.dir/build

CMakeFiles/cpp_exe3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp_exe3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp_exe3.dir/clean

CMakeFiles/cpp_exe3.dir/depend:
	cd /home/DATA/DogRobot/ros2_ws/build/wit_pkg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/DATA/DogRobot/ros2_ws/src/wit_pkg /home/DATA/DogRobot/ros2_ws/src/wit_pkg /home/DATA/DogRobot/ros2_ws/build/wit_pkg /home/DATA/DogRobot/ros2_ws/build/wit_pkg /home/DATA/DogRobot/ros2_ws/build/wit_pkg/CMakeFiles/cpp_exe3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cpp_exe3.dir/depend

