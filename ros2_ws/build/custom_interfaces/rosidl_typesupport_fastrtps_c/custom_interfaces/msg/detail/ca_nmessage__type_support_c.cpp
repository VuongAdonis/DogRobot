// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/ca_nmessage__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_interfaces/msg/detail/ca_nmessage__struct.h"
#include "custom_interfaces/msg/detail/ca_nmessage__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // positionfl, positionfr, positionrl, positionrr
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // positionfl, positionfr, positionrl, positionrr
#include "rosidl_runtime_c/string.h"  // name1, name2, name3, name4
#include "rosidl_runtime_c/string_functions.h"  // name1, name2, name3, name4

// forward declare type support functions


using _CANmessage__ros_msg_type = custom_interfaces__msg__CANmessage;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_custom_interfaces__msg__CANmessage(
  const custom_interfaces__msg__CANmessage * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: name1
  {
    const rosidl_runtime_c__String * str = &ros_message->name1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionrr
  {
    size_t size = ros_message->positionrr.size;
    auto array_ptr = ros_message->positionrr.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: name2
  {
    const rosidl_runtime_c__String * str = &ros_message->name2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionrl
  {
    size_t size = ros_message->positionrl.size;
    auto array_ptr = ros_message->positionrl.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: name3
  {
    const rosidl_runtime_c__String * str = &ros_message->name3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionfr
  {
    size_t size = ros_message->positionfr.size;
    auto array_ptr = ros_message->positionfr.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: name4
  {
    const rosidl_runtime_c__String * str = &ros_message->name4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionfl
  {
    size_t size = ros_message->positionfl.size;
    auto array_ptr = ros_message->positionfl.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_deserialize_custom_interfaces__msg__CANmessage(
  eprosima::fastcdr::Cdr & cdr,
  custom_interfaces__msg__CANmessage * ros_message)
{
  // Field name: name1
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name1.data) {
      rosidl_runtime_c__String__init(&ros_message->name1);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name1,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name1'\n");
      return false;
    }
  }

  // Field name: positionrr
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->positionrr.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->positionrr);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->positionrr, size)) {
      fprintf(stderr, "failed to create array for field 'positionrr'");
      return false;
    }
    auto array_ptr = ros_message->positionrr.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: name2
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name2.data) {
      rosidl_runtime_c__String__init(&ros_message->name2);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name2,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name2'\n");
      return false;
    }
  }

  // Field name: positionrl
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->positionrl.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->positionrl);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->positionrl, size)) {
      fprintf(stderr, "failed to create array for field 'positionrl'");
      return false;
    }
    auto array_ptr = ros_message->positionrl.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: name3
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name3.data) {
      rosidl_runtime_c__String__init(&ros_message->name3);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name3,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name3'\n");
      return false;
    }
  }

  // Field name: positionfr
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->positionfr.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->positionfr);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->positionfr, size)) {
      fprintf(stderr, "failed to create array for field 'positionfr'");
      return false;
    }
    auto array_ptr = ros_message->positionfr.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: name4
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name4.data) {
      rosidl_runtime_c__String__init(&ros_message->name4);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name4,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name4'\n");
      return false;
    }
  }

  // Field name: positionfl
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->positionfl.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->positionfl);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->positionfl, size)) {
      fprintf(stderr, "failed to create array for field 'positionfl'");
      return false;
    }
    auto array_ptr = ros_message->positionfl.data;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_custom_interfaces__msg__CANmessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANmessage__ros_msg_type * ros_message = static_cast<const _CANmessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: name1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name1.size + 1);

  // Field name: positionrr
  {
    size_t array_size = ros_message->positionrr.size;
    auto array_ptr = ros_message->positionrr.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: name2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name2.size + 1);

  // Field name: positionrl
  {
    size_t array_size = ros_message->positionrl.size;
    auto array_ptr = ros_message->positionrl.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: name3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name3.size + 1);

  // Field name: positionfr
  {
    size_t array_size = ros_message->positionfr.size;
    auto array_ptr = ros_message->positionfr.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: name4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name4.size + 1);

  // Field name: positionfl
  {
    size_t array_size = ros_message->positionfl.size;
    auto array_ptr = ros_message->positionfl.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_custom_interfaces__msg__CANmessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: name1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionrr
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: name2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionrl
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: name3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionfr
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: name4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionfl
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__msg__CANmessage;
    is_plain =
      (
      offsetof(DataType, positionfl) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_key_custom_interfaces__msg__CANmessage(
  const custom_interfaces__msg__CANmessage * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: name1
  {
    const rosidl_runtime_c__String * str = &ros_message->name1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionrr
  {
    size_t size = ros_message->positionrr.size;
    auto array_ptr = ros_message->positionrr.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: name2
  {
    const rosidl_runtime_c__String * str = &ros_message->name2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionrl
  {
    size_t size = ros_message->positionrl.size;
    auto array_ptr = ros_message->positionrl.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: name3
  {
    const rosidl_runtime_c__String * str = &ros_message->name3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionfr
  {
    size_t size = ros_message->positionfr.size;
    auto array_ptr = ros_message->positionfr.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: name4
  {
    const rosidl_runtime_c__String * str = &ros_message->name4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: positionfl
  {
    size_t size = ros_message->positionfl.size;
    auto array_ptr = ros_message->positionfl.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_key_custom_interfaces__msg__CANmessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANmessage__ros_msg_type * ros_message = static_cast<const _CANmessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: name1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name1.size + 1);

  // Field name: positionrr
  {
    size_t array_size = ros_message->positionrr.size;
    auto array_ptr = ros_message->positionrr.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: name2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name2.size + 1);

  // Field name: positionrl
  {
    size_t array_size = ros_message->positionrl.size;
    auto array_ptr = ros_message->positionrl.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: name3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name3.size + 1);

  // Field name: positionfr
  {
    size_t array_size = ros_message->positionfr.size;
    auto array_ptr = ros_message->positionfr.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: name4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name4.size + 1);

  // Field name: positionfl
  {
    size_t array_size = ros_message->positionfl.size;
    auto array_ptr = ros_message->positionfl.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_key_custom_interfaces__msg__CANmessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: name1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionrr
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: name2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionrl
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: name3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionfr
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: name4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: positionfl
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__msg__CANmessage;
    is_plain =
      (
      offsetof(DataType, positionfl) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CANmessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const custom_interfaces__msg__CANmessage * ros_message = static_cast<const custom_interfaces__msg__CANmessage *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_custom_interfaces__msg__CANmessage(ros_message, cdr);
}

static bool _CANmessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  custom_interfaces__msg__CANmessage * ros_message = static_cast<custom_interfaces__msg__CANmessage *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_custom_interfaces__msg__CANmessage(cdr, ros_message);
}

static uint32_t _CANmessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_interfaces__msg__CANmessage(
      untyped_ros_message, 0));
}

static size_t _CANmessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_interfaces__msg__CANmessage(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CANmessage = {
  "custom_interfaces::msg",
  "CANmessage",
  _CANmessage__cdr_serialize,
  _CANmessage__cdr_deserialize,
  _CANmessage__get_serialized_size,
  _CANmessage__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CANmessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CANmessage,
  get_message_typesupport_handle_function,
  &custom_interfaces__msg__CANmessage__get_type_hash,
  &custom_interfaces__msg__CANmessage__get_type_description,
  &custom_interfaces__msg__CANmessage__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, msg, CANmessage)() {
  return &_CANmessage__type_support;
}

#if defined(__cplusplus)
}
#endif
