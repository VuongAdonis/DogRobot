cmake_minimum_required(VERSION 3.8)

project(wit_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()



# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_interfaces REQUIRED)

# let the compiler search for headers in the include folder
include_directories(include/wit_pkg)

# Define the serial library
add_library(serial SHARED src/serial.c)
set_target_properties(serial PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")

# Define the wit_c_sdk library
add_library(wit_c_sdk SHARED src/wit_c_sdk.c)
set_target_properties(wit_c_sdk PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")

# Set ament dependencies for libraries (sau khi định nghĩa chúng)
ament_target_dependencies(
    serial 
    rclcpp 
)
ament_target_dependencies(wit_c_sdk rclcpp)

# Install the libraries
install(
    TARGETS serial wit_c_sdk
    EXPORT export_${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Định nghĩa executable
add_executable(readIMU src/readIMU.cpp)
ament_target_dependencies(readIMU 
    rclcpp 
    custom_interfaces
)

# Link hệ thống thư viện với executable
target_link_libraries(readIMU serial wit_c_sdk)

# Cài đặt các header
install(TARGETS readIMU DESTINATION lib/${PROJECT_NAME})

ament_export_targets(export_${PROJECT_NAME})

# Khai báo gói
ament_package()
