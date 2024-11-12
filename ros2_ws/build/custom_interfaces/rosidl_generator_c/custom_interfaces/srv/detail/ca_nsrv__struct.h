// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/CANsrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/ca_nsrv.h"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'namerr'
// Member 'namerl'
// Member 'namefr'
// Member 'namefl'
#include "rosidl_runtime_c/string.h"
// Member 'positionrr'
// Member 'positionrl'
// Member 'positionfr'
// Member 'positionfl'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/CANsrv in the package custom_interfaces.
typedef struct custom_interfaces__srv__CANsrv_Request
{
  rosidl_runtime_c__String namerr;
  rosidl_runtime_c__double__Sequence positionrr;
  rosidl_runtime_c__String namerl;
  rosidl_runtime_c__double__Sequence positionrl;
  rosidl_runtime_c__String namefr;
  rosidl_runtime_c__double__Sequence positionfr;
  rosidl_runtime_c__String namefl;
  rosidl_runtime_c__double__Sequence positionfl;
} custom_interfaces__srv__CANsrv_Request;

// Struct for a sequence of custom_interfaces__srv__CANsrv_Request.
typedef struct custom_interfaces__srv__CANsrv_Request__Sequence
{
  custom_interfaces__srv__CANsrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__CANsrv_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/CANsrv in the package custom_interfaces.
typedef struct custom_interfaces__srv__CANsrv_Response
{
  int8_t can_done;
} custom_interfaces__srv__CANsrv_Response;

// Struct for a sequence of custom_interfaces__srv__CANsrv_Response.
typedef struct custom_interfaces__srv__CANsrv_Response__Sequence
{
  custom_interfaces__srv__CANsrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__CANsrv_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_interfaces__srv__CANsrv_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_interfaces__srv__CANsrv_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/CANsrv in the package custom_interfaces.
typedef struct custom_interfaces__srv__CANsrv_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_interfaces__srv__CANsrv_Request__Sequence request;
  custom_interfaces__srv__CANsrv_Response__Sequence response;
} custom_interfaces__srv__CANsrv_Event;

// Struct for a sequence of custom_interfaces__srv__CANsrv_Event.
typedef struct custom_interfaces__srv__CANsrv_Event__Sequence
{
  custom_interfaces__srv__CANsrv_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__CANsrv_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__STRUCT_H_
