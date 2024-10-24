// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/msg/detail/ca_nmessage__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/msg/detail/ca_nmessage__functions.h"
#include "custom_interfaces/msg/detail/ca_nmessage__struct.h"


// Include directives for member types
// Member `name1`
// Member `name2`
// Member `name3`
// Member `name4`
#include "rosidl_runtime_c/string_functions.h"
// Member `positionrr`
// Member `positionrl`
// Member `positionfr`
// Member `positionfl`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__msg__CANmessage__init(message_memory);
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_fini_function(void * message_memory)
{
  custom_interfaces__msg__CANmessage__fini(message_memory);
}

size_t custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionrr(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionrr(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionrr(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionrr(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionrr(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionrr(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionrr(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionrr(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionrl(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionrl(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionrl(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionrl(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionrl(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionrl(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionrl(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionrl(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionfr(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionfr(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionfr(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionfr(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionfr(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionfr(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionfr(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionfr(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionfl(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionfl(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionfl(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionfl(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionfl(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionfl(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionfl(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionfl(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_member_array[8] = {
  {
    "name1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, name1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "positionrr",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, positionrr),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionrr,  // size() function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionrr,  // get_const(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionrr,  // get(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionrr,  // fetch(index, &value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionrr,  // assign(index, value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionrr  // resize(index) function pointer
  },
  {
    "name2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, name2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "positionrl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, positionrl),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionrl,  // size() function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionrl,  // get_const(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionrl,  // get(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionrl,  // fetch(index, &value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionrl,  // assign(index, value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionrl  // resize(index) function pointer
  },
  {
    "name3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, name3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "positionfr",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, positionfr),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionfr,  // size() function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionfr,  // get_const(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionfr,  // get(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionfr,  // fetch(index, &value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionfr,  // assign(index, value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionfr  // resize(index) function pointer
  },
  {
    "name4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, name4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "positionfl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__CANmessage, positionfl),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__size_function__CANmessage__positionfl,  // size() function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_const_function__CANmessage__positionfl,  // get_const(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__get_function__CANmessage__positionfl,  // get(index) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__fetch_function__CANmessage__positionfl,  // fetch(index, &value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__assign_function__CANmessage__positionfl,  // assign(index, value) function pointer
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__resize_function__CANmessage__positionfl  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_members = {
  "custom_interfaces__msg",  // message namespace
  "CANmessage",  // message name
  8,  // number of fields
  sizeof(custom_interfaces__msg__CANmessage),
  false,  // has_any_key_member_
  custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_member_array,  // message members
  custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_type_support_handle = {
  0,
  &custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_members,
  get_message_typesupport_handle_function,
  &custom_interfaces__msg__CANmessage__get_type_hash,
  &custom_interfaces__msg__CANmessage__get_type_description,
  &custom_interfaces__msg__CANmessage__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, CANmessage)() {
  if (!custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__msg__CANmessage__rosidl_typesupport_introspection_c__CANmessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif