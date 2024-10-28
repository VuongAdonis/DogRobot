cmake_minimum_required(VERSION 3.8)
project(wit_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Include cpp "include" directory
include_directories(include)

# Create cpp executable
add_executable(cpp_exe1 src/main.c)
ament_target_dependencies(cpp_exe1 rclcpp)
target_link_libraries(REG serial wit_c_sdk)

add_executable(cpp_exe2 src/serial.c)
ament_target_dependencies(cpp_exe2 rclcpp)

add_executable(cpp_exe3 src/wit_c_sdk.c)
ament_target_dependencies(cpp_exe3 rclcpp)


# Install cpp executables
install(TARGETS 
  cpp_exe1
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
