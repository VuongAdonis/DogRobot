// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:srv/GamepadSrv.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/srv/detail/gamepad_srv__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__GamepadSrv__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x16, 0xba, 0xb4, 0x2e, 0x31, 0x06, 0xfd, 0xa6,
      0xa8, 0xf2, 0xe8, 0x48, 0x06, 0xaf, 0x97, 0xb7,
      0x8f, 0xd7, 0x6f, 0x55, 0x79, 0x0f, 0x28, 0x2b,
      0xca, 0xac, 0x9e, 0xf1, 0xc0, 0x95, 0x18, 0xf7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__GamepadSrv_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5e, 0x2f, 0xfc, 0xe9, 0x4c, 0xaa, 0xc8, 0xb1,
      0x07, 0x8d, 0xeb, 0x5d, 0xd1, 0xf7, 0x05, 0x01,
      0xe0, 0x72, 0xc9, 0x6b, 0xcc, 0xd5, 0xd2, 0xfe,
      0x33, 0xf8, 0x6b, 0x80, 0xf5, 0xb2, 0xfd, 0x8c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__GamepadSrv_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x33, 0x48, 0xca, 0x4c, 0xf7, 0xeb, 0x4f, 0xd9,
      0x86, 0x14, 0xd1, 0x05, 0xaa, 0xe6, 0x2e, 0x11,
      0x45, 0x54, 0xf7, 0xb1, 0xbd, 0xde, 0x07, 0x81,
      0xc8, 0x50, 0x69, 0x01, 0x22, 0xda, 0x4b, 0x4b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__GamepadSrv_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0xc1, 0x88, 0x17, 0x93, 0x61, 0xc2, 0xd3,
      0xf3, 0x88, 0x54, 0x29, 0x61, 0x14, 0x32, 0xd5,
      0xf0, 0x18, 0xa1, 0x54, 0x86, 0x74, 0xed, 0x81,
      0xd2, 0xbc, 0xbe, 0x98, 0xa6, 0xaf, 0x52, 0x07,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char custom_interfaces__srv__GamepadSrv__TYPE_NAME[] = "custom_interfaces/srv/GamepadSrv";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char custom_interfaces__srv__GamepadSrv_Event__TYPE_NAME[] = "custom_interfaces/srv/GamepadSrv_Event";
static char custom_interfaces__srv__GamepadSrv_Request__TYPE_NAME[] = "custom_interfaces/srv/GamepadSrv_Request";
static char custom_interfaces__srv__GamepadSrv_Response__TYPE_NAME[] = "custom_interfaces/srv/GamepadSrv_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char custom_interfaces__srv__GamepadSrv__FIELD_NAME__request_message[] = "request_message";
static char custom_interfaces__srv__GamepadSrv__FIELD_NAME__response_message[] = "response_message";
static char custom_interfaces__srv__GamepadSrv__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__GamepadSrv__FIELDS[] = {
  {
    {custom_interfaces__srv__GamepadSrv__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__srv__GamepadSrv_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__srv__GamepadSrv_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__srv__GamepadSrv_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_interfaces__srv__GamepadSrv__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__GamepadSrv__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__GamepadSrv__TYPE_NAME, 32, 32},
      {custom_interfaces__srv__GamepadSrv__FIELDS, 3, 3},
    },
    {custom_interfaces__srv__GamepadSrv__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = custom_interfaces__srv__GamepadSrv_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = custom_interfaces__srv__GamepadSrv_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = custom_interfaces__srv__GamepadSrv_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_interfaces__srv__GamepadSrv_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__GamepadSrv_Request__FIELDS[] = {
  {
    {custom_interfaces__srv__GamepadSrv_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__GamepadSrv_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__GamepadSrv_Request__TYPE_NAME, 40, 40},
      {custom_interfaces__srv__GamepadSrv_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__position[] = "position";
static char custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__button_stand_up[] = "button_stand_up";
static char custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__button_stand_down[] = "button_stand_down";
static char custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__button_stand_normal[] = "button_stand_normal";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__GamepadSrv_Response__FIELDS[] = {
  {
    {custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__button_stand_up, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__button_stand_down, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Response__FIELD_NAME__button_stand_normal, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__GamepadSrv_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__GamepadSrv_Response__TYPE_NAME, 41, 41},
      {custom_interfaces__srv__GamepadSrv_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_interfaces__srv__GamepadSrv_Event__FIELD_NAME__info[] = "info";
static char custom_interfaces__srv__GamepadSrv_Event__FIELD_NAME__request[] = "request";
static char custom_interfaces__srv__GamepadSrv_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__GamepadSrv_Event__FIELDS[] = {
  {
    {custom_interfaces__srv__GamepadSrv_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {custom_interfaces__srv__GamepadSrv_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {custom_interfaces__srv__GamepadSrv_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_interfaces__srv__GamepadSrv_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__GamepadSrv_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__GamepadSrv_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__GamepadSrv_Event__TYPE_NAME, 38, 38},
      {custom_interfaces__srv__GamepadSrv_Event__FIELDS, 3, 3},
    },
    {custom_interfaces__srv__GamepadSrv_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = custom_interfaces__srv__GamepadSrv_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = custom_interfaces__srv__GamepadSrv_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "\n"
  "---\n"
  "float64[]   position\n"
  "int8        button_stand_up\n"
  "int8        button_stand_down\n"
  "int8        button_stand_normal";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__GamepadSrv__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__GamepadSrv__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 115, 115},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__GamepadSrv_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__GamepadSrv_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__GamepadSrv_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__GamepadSrv_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__GamepadSrv_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__GamepadSrv_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__GamepadSrv__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__GamepadSrv__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *custom_interfaces__srv__GamepadSrv_Event__get_individual_type_description_source(NULL);
    sources[3] = *custom_interfaces__srv__GamepadSrv_Request__get_individual_type_description_source(NULL);
    sources[4] = *custom_interfaces__srv__GamepadSrv_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__GamepadSrv_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__GamepadSrv_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__GamepadSrv_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__GamepadSrv_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__GamepadSrv_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__GamepadSrv_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *custom_interfaces__srv__GamepadSrv_Request__get_individual_type_description_source(NULL);
    sources[3] = *custom_interfaces__srv__GamepadSrv_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
