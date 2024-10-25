// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/PublishMessage.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/publish_message__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__PublishMessage__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3e, 0x3c, 0xcc, 0xa6, 0x10, 0x05, 0xc7, 0xba,
      0x85, 0x7d, 0x65, 0xa4, 0xf3, 0x44, 0x40, 0x0e,
      0x7d, 0xa6, 0x71, 0x8b, 0xa0, 0xc4, 0x4d, 0xdb,
      0x3d, 0x0d, 0x5b, 0x68, 0x20, 0x1a, 0xe7, 0xb3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__PublishMessage__TYPE_NAME[] = "custom_interfaces/msg/PublishMessage";

// Define type names, field names, and default values
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__namerr[] = "namerr";
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__positionrr[] = "positionrr";
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__namerl[] = "namerl";
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__positionrl[] = "positionrl";
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__namefr[] = "namefr";
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__positionfr[] = "positionfr";
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__namefl[] = "namefl";
static char custom_interfaces__msg__PublishMessage__FIELD_NAME__positionfl[] = "positionfl";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__PublishMessage__FIELDS[] = {
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__namerr, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__positionrr, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__namerl, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__positionrl, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__namefr, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__positionfr, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__namefl, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__PublishMessage__FIELD_NAME__positionfl, 10, 10},
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
custom_interfaces__msg__PublishMessage__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__PublishMessage__TYPE_NAME, 36, 36},
      {custom_interfaces__msg__PublishMessage__FIELDS, 8, 8},
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
  "string namerr\n"
  "float64[] positionrr\n"
  "string namerl\n"
  "float64[] positionrl\n"
  "string namefr\n"
  "float64[] positionfr\n"
  "string namefl\n"
  "float64[] positionfl";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__PublishMessage__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__PublishMessage__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 195, 195},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__PublishMessage__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__PublishMessage__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
