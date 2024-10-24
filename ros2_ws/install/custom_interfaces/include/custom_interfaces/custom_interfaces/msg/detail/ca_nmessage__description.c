// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/ca_nmessage__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__CANmessage__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x86, 0x99, 0xb9, 0x5e, 0xfc, 0xda, 0x10, 0xb7,
      0xa0, 0xc8, 0x3a, 0x79, 0xbc, 0xb6, 0x1c, 0x9e,
      0x52, 0xa1, 0xc0, 0xed, 0x9d, 0x29, 0x4d, 0xad,
      0x2c, 0x32, 0xba, 0x81, 0x7d, 0xd7, 0xd7, 0xe7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__CANmessage__TYPE_NAME[] = "custom_interfaces/msg/CANmessage";

// Define type names, field names, and default values
static char custom_interfaces__msg__CANmessage__FIELD_NAME__name1[] = "name1";
static char custom_interfaces__msg__CANmessage__FIELD_NAME__positionrr[] = "positionrr";
static char custom_interfaces__msg__CANmessage__FIELD_NAME__name2[] = "name2";
static char custom_interfaces__msg__CANmessage__FIELD_NAME__positionrl[] = "positionrl";
static char custom_interfaces__msg__CANmessage__FIELD_NAME__name3[] = "name3";
static char custom_interfaces__msg__CANmessage__FIELD_NAME__positionfr[] = "positionfr";
static char custom_interfaces__msg__CANmessage__FIELD_NAME__name4[] = "name4";
static char custom_interfaces__msg__CANmessage__FIELD_NAME__positionfl[] = "positionfl";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__CANmessage__FIELDS[] = {
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__name1, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__positionrr, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__name2, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__positionrl, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__name3, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__positionfr, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__name4, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__CANmessage__FIELD_NAME__positionfl, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__CANmessage__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__CANmessage__TYPE_NAME, 32, 32},
      {custom_interfaces__msg__CANmessage__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# This contain the position to control the leg of robot\n"
  "string name1\n"
  "float64[] positionrr\n"
  "string name2\n"
  "float64[] positionrl\n"
  "string name3\n"
  "float64[] positionfr\n"
  "string name4\n"
  "float64[] positionfl";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__CANmessage__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__CANmessage__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 191, 191},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__CANmessage__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__CANmessage__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
