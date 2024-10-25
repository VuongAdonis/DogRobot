// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/GamepadSrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/gamepad_srv.h"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GamepadSrv in the package custom_interfaces.
typedef struct custom_interfaces__srv__GamepadSrv_Request
{
  uint8_t structure_needs_at_least_one_member;
} custom_interfaces__srv__GamepadSrv_Request;

// Struct for a sequence of custom_interfaces__srv__GamepadSrv_Request.
typedef struct custom_interfaces__srv__GamepadSrv_Request__Sequence
{
  custom_interfaces__srv__GamepadSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__GamepadSrv_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GamepadSrv in the package custom_interfaces.
typedef struct custom_interfaces__srv__GamepadSrv_Response
{
  rosidl_runtime_c__double__Sequence position;
} custom_interfaces__srv__GamepadSrv_Response;

// Struct for a sequence of custom_interfaces__srv__GamepadSrv_Response.
typedef struct custom_interfaces__srv__GamepadSrv_Response__Sequence
{
  custom_interfaces__srv__GamepadSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__GamepadSrv_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_interfaces__srv__GamepadSrv_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_interfaces__srv__GamepadSrv_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GamepadSrv in the package custom_interfaces.
typedef struct custom_interfaces__srv__GamepadSrv_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_interfaces__srv__GamepadSrv_Request__Sequence request;
  custom_interfaces__srv__GamepadSrv_Response__Sequence response;
} custom_interfaces__srv__GamepadSrv_Event;

// Struct for a sequence of custom_interfaces__srv__GamepadSrv_Event.
typedef struct custom_interfaces__srv__GamepadSrv_Event__Sequence
{
  custom_interfaces__srv__GamepadSrv_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__GamepadSrv_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__STRUCT_H_
