// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from custom_interfaces:srv/CANsrv.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_interfaces/srv/detail/ca_nsrv__struct.h"
#include "custom_interfaces/srv/detail/ca_nsrv__type_support.h"
#include "custom_interfaces/srv/detail/ca_nsrv__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _CANsrv_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CANsrv_Request_type_support_ids_t;

static const _CANsrv_Request_type_support_ids_t _CANsrv_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CANsrv_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CANsrv_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CANsrv_Request_type_support_symbol_names_t _CANsrv_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, CANsrv_Request)),
  }
};

typedef struct _CANsrv_Request_type_support_data_t
{
  void * data[2];
} _CANsrv_Request_type_support_data_t;

static _CANsrv_Request_type_support_data_t _CANsrv_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CANsrv_Request_message_typesupport_map = {
  2,
  "custom_interfaces",
  &_CANsrv_Request_message_typesupport_ids.typesupport_identifier[0],
  &_CANsrv_Request_message_typesupport_symbol_names.symbol_name[0],
  &_CANsrv_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CANsrv_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CANsrv_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &custom_interfaces__srv__CANsrv_Request__get_type_hash,
  &custom_interfaces__srv__CANsrv_Request__get_type_description,
  &custom_interfaces__srv__CANsrv_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_interfaces, srv, CANsrv_Request)() {
  return &::custom_interfaces::srv::rosidl_typesupport_c::CANsrv_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__struct.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__type_support.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _CANsrv_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CANsrv_Response_type_support_ids_t;

static const _CANsrv_Response_type_support_ids_t _CANsrv_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CANsrv_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CANsrv_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CANsrv_Response_type_support_symbol_names_t _CANsrv_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, CANsrv_Response)),
  }
};

typedef struct _CANsrv_Response_type_support_data_t
{
  void * data[2];
} _CANsrv_Response_type_support_data_t;

static _CANsrv_Response_type_support_data_t _CANsrv_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CANsrv_Response_message_typesupport_map = {
  2,
  "custom_interfaces",
  &_CANsrv_Response_message_typesupport_ids.typesupport_identifier[0],
  &_CANsrv_Response_message_typesupport_symbol_names.symbol_name[0],
  &_CANsrv_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CANsrv_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CANsrv_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &custom_interfaces__srv__CANsrv_Response__get_type_hash,
  &custom_interfaces__srv__CANsrv_Response__get_type_description,
  &custom_interfaces__srv__CANsrv_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_interfaces, srv, CANsrv_Response)() {
  return &::custom_interfaces::srv::rosidl_typesupport_c::CANsrv_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__struct.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__type_support.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _CANsrv_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CANsrv_Event_type_support_ids_t;

static const _CANsrv_Event_type_support_ids_t _CANsrv_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CANsrv_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CANsrv_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CANsrv_Event_type_support_symbol_names_t _CANsrv_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, CANsrv_Event)),
  }
};

typedef struct _CANsrv_Event_type_support_data_t
{
  void * data[2];
} _CANsrv_Event_type_support_data_t;

static _CANsrv_Event_type_support_data_t _CANsrv_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CANsrv_Event_message_typesupport_map = {
  2,
  "custom_interfaces",
  &_CANsrv_Event_message_typesupport_ids.typesupport_identifier[0],
  &_CANsrv_Event_message_typesupport_symbol_names.symbol_name[0],
  &_CANsrv_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CANsrv_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CANsrv_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &custom_interfaces__srv__CANsrv_Event__get_type_hash,
  &custom_interfaces__srv__CANsrv_Event__get_type_description,
  &custom_interfaces__srv__CANsrv_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_interfaces, srv, CANsrv_Event)() {
  return &::custom_interfaces::srv::rosidl_typesupport_c::CANsrv_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _CANsrv_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CANsrv_type_support_ids_t;

static const _CANsrv_type_support_ids_t _CANsrv_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CANsrv_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CANsrv_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CANsrv_type_support_symbol_names_t _CANsrv_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, CANsrv)),
  }
};

typedef struct _CANsrv_type_support_data_t
{
  void * data[2];
} _CANsrv_type_support_data_t;

static _CANsrv_type_support_data_t _CANsrv_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CANsrv_service_typesupport_map = {
  2,
  "custom_interfaces",
  &_CANsrv_service_typesupport_ids.typesupport_identifier[0],
  &_CANsrv_service_typesupport_symbol_names.symbol_name[0],
  &_CANsrv_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t CANsrv_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CANsrv_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &CANsrv_Request_message_type_support_handle,
  &CANsrv_Response_message_type_support_handle,
  &CANsrv_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_interfaces,
    srv,
    CANsrv
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_interfaces,
    srv,
    CANsrv
  ),
  &custom_interfaces__srv__CANsrv__get_type_hash,
  &custom_interfaces__srv__CANsrv__get_type_description,
  &custom_interfaces__srv__CANsrv__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, custom_interfaces, srv, CANsrv)() {
  return &::custom_interfaces::srv::rosidl_typesupport_c::CANsrv_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
