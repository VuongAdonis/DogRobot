// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/ca_nmessage.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'name1'
// Member 'name2'
// Member 'name3'
// Member 'name4'
#include "rosidl_runtime_c/string.h"
// Member 'positionrr'
// Member 'positionrl'
// Member 'positionfr'
// Member 'positionfl'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/CANmessage in the package custom_interfaces.
/**
  * This contain the position to control the leg of robot
 */
typedef struct custom_interfaces__msg__CANmessage
{
  rosidl_runtime_c__String name1;
  rosidl_runtime_c__double__Sequence positionrr;
  rosidl_runtime_c__String name2;
  rosidl_runtime_c__double__Sequence positionrl;
  rosidl_runtime_c__String name3;
  rosidl_runtime_c__double__Sequence positionfr;
  rosidl_runtime_c__String name4;
  rosidl_runtime_c__double__Sequence positionfl;
} custom_interfaces__msg__CANmessage;

// Struct for a sequence of custom_interfaces__msg__CANmessage.
typedef struct custom_interfaces__msg__CANmessage__Sequence
{
  custom_interfaces__msg__CANmessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__CANmessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__STRUCT_H_
