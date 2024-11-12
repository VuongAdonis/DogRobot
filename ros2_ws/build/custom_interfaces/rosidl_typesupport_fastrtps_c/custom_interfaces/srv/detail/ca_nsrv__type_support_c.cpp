// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_interfaces:srv/CANsrv.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/srv/detail/ca_nsrv__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_interfaces/srv/detail/ca_nsrv__struct.h"
#include "custom_interfaces/srv/detail/ca_nsrv__functions.h"
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
#include "rosidl_runtime_c/string.h"  // namefl, namefr, namerl, namerr
#include "rosidl_runtime_c/string_functions.h"  // namefl, namefr, namerl, namerr

// forward declare type support functions


using _CANsrv_Request__ros_msg_type = custom_interfaces__srv__CANsrv_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_custom_interfaces__srv__CANsrv_Request(
  const custom_interfaces__srv__CANsrv_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: namerr
  {
    const rosidl_runtime_c__String * str = &ros_message->namerr;
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

  // Field name: namerl
  {
    const rosidl_runtime_c__String * str = &ros_message->namerl;
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

  // Field name: namefr
  {
    const rosidl_runtime_c__String * str = &ros_message->namefr;
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

  // Field name: namefl
  {
    const rosidl_runtime_c__String * str = &ros_message->namefl;
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
bool cdr_deserialize_custom_interfaces__srv__CANsrv_Request(
  eprosima::fastcdr::Cdr & cdr,
  custom_interfaces__srv__CANsrv_Request * ros_message)
{
  // Field name: namerr
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->namerr.data) {
      rosidl_runtime_c__String__init(&ros_message->namerr);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->namerr,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'namerr'\n");
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

  // Field name: namerl
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->namerl.data) {
      rosidl_runtime_c__String__init(&ros_message->namerl);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->namerl,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'namerl'\n");
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

  // Field name: namefr
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->namefr.data) {
      rosidl_runtime_c__String__init(&ros_message->namefr);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->namefr,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'namefr'\n");
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

  // Field name: namefl
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->namefl.data) {
      rosidl_runtime_c__String__init(&ros_message->namefl);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->namefl,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'namefl'\n");
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
size_t get_serialized_size_custom_interfaces__srv__CANsrv_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANsrv_Request__ros_msg_type * ros_message = static_cast<const _CANsrv_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: namerr
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namerr.size + 1);

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

  // Field name: namerl
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namerl.size + 1);

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

  // Field name: namefr
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namefr.size + 1);

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

  // Field name: namefl
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namefl.size + 1);

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
size_t max_serialized_size_custom_interfaces__srv__CANsrv_Request(
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

  // Field name: namerr
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

  // Field name: namerl
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

  // Field name: namefr
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

  // Field name: namefl
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
    using DataType = custom_interfaces__srv__CANsrv_Request;
    is_plain =
      (
      offsetof(DataType, positionfl) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_key_custom_interfaces__srv__CANsrv_Request(
  const custom_interfaces__srv__CANsrv_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: namerr
  {
    const rosidl_runtime_c__String * str = &ros_message->namerr;
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

  // Field name: namerl
  {
    const rosidl_runtime_c__String * str = &ros_message->namerl;
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

  // Field name: namefr
  {
    const rosidl_runtime_c__String * str = &ros_message->namefr;
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

  // Field name: namefl
  {
    const rosidl_runtime_c__String * str = &ros_message->namefl;
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
size_t get_serialized_size_key_custom_interfaces__srv__CANsrv_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANsrv_Request__ros_msg_type * ros_message = static_cast<const _CANsrv_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: namerr
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namerr.size + 1);

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

  // Field name: namerl
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namerl.size + 1);

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

  // Field name: namefr
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namefr.size + 1);

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

  // Field name: namefl
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namefl.size + 1);

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
size_t max_serialized_size_key_custom_interfaces__srv__CANsrv_Request(
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
  // Field name: namerr
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

  // Field name: namerl
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

  // Field name: namefr
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

  // Field name: namefl
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
    using DataType = custom_interfaces__srv__CANsrv_Request;
    is_plain =
      (
      offsetof(DataType, positionfl) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CANsrv_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const custom_interfaces__srv__CANsrv_Request * ros_message = static_cast<const custom_interfaces__srv__CANsrv_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_custom_interfaces__srv__CANsrv_Request(ros_message, cdr);
}

static bool _CANsrv_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  custom_interfaces__srv__CANsrv_Request * ros_message = static_cast<custom_interfaces__srv__CANsrv_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_custom_interfaces__srv__CANsrv_Request(cdr, ros_message);
}

static uint32_t _CANsrv_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_interfaces__srv__CANsrv_Request(
      untyped_ros_message, 0));
}

static size_t _CANsrv_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_interfaces__srv__CANsrv_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CANsrv_Request = {
  "custom_interfaces::srv",
  "CANsrv_Request",
  _CANsrv_Request__cdr_serialize,
  _CANsrv_Request__cdr_deserialize,
  _CANsrv_Request__get_serialized_size,
  _CANsrv_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CANsrv_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CANsrv_Request,
  get_message_typesupport_handle_function,
  &custom_interfaces__srv__CANsrv_Request__get_type_hash,
  &custom_interfaces__srv__CANsrv_Request__get_type_description,
  &custom_interfaces__srv__CANsrv_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Request)() {
  return &_CANsrv_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "custom_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__struct.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


// forward declare type support functions


using _CANsrv_Response__ros_msg_type = custom_interfaces__srv__CANsrv_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_custom_interfaces__srv__CANsrv_Response(
  const custom_interfaces__srv__CANsrv_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: can_done
  {
    cdr << ros_message->can_done;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_deserialize_custom_interfaces__srv__CANsrv_Response(
  eprosima::fastcdr::Cdr & cdr,
  custom_interfaces__srv__CANsrv_Response * ros_message)
{
  // Field name: can_done
  {
    cdr >> ros_message->can_done;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_custom_interfaces__srv__CANsrv_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANsrv_Response__ros_msg_type * ros_message = static_cast<const _CANsrv_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: can_done
  {
    size_t item_size = sizeof(ros_message->can_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_custom_interfaces__srv__CANsrv_Response(
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

  // Field name: can_done
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__srv__CANsrv_Response;
    is_plain =
      (
      offsetof(DataType, can_done) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_key_custom_interfaces__srv__CANsrv_Response(
  const custom_interfaces__srv__CANsrv_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: can_done
  {
    cdr << ros_message->can_done;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_key_custom_interfaces__srv__CANsrv_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANsrv_Response__ros_msg_type * ros_message = static_cast<const _CANsrv_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: can_done
  {
    size_t item_size = sizeof(ros_message->can_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_key_custom_interfaces__srv__CANsrv_Response(
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
  // Field name: can_done
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__srv__CANsrv_Response;
    is_plain =
      (
      offsetof(DataType, can_done) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CANsrv_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const custom_interfaces__srv__CANsrv_Response * ros_message = static_cast<const custom_interfaces__srv__CANsrv_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_custom_interfaces__srv__CANsrv_Response(ros_message, cdr);
}

static bool _CANsrv_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  custom_interfaces__srv__CANsrv_Response * ros_message = static_cast<custom_interfaces__srv__CANsrv_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_custom_interfaces__srv__CANsrv_Response(cdr, ros_message);
}

static uint32_t _CANsrv_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_interfaces__srv__CANsrv_Response(
      untyped_ros_message, 0));
}

static size_t _CANsrv_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_interfaces__srv__CANsrv_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CANsrv_Response = {
  "custom_interfaces::srv",
  "CANsrv_Response",
  _CANsrv_Response__cdr_serialize,
  _CANsrv_Response__cdr_deserialize,
  _CANsrv_Response__get_serialized_size,
  _CANsrv_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CANsrv_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CANsrv_Response,
  get_message_typesupport_handle_function,
  &custom_interfaces__srv__CANsrv_Response__get_type_hash,
  &custom_interfaces__srv__CANsrv_Response__get_type_description,
  &custom_interfaces__srv__CANsrv_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Response)() {
  return &_CANsrv_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "custom_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__struct.h"
// already included above
// #include "custom_interfaces/srv/detail/ca_nsrv__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_custom_interfaces__srv__CANsrv_Request(
  const custom_interfaces__srv__CANsrv_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_custom_interfaces__srv__CANsrv_Request(
  eprosima::fastcdr::Cdr & cdr,
  custom_interfaces__srv__CANsrv_Request * ros_message);

size_t get_serialized_size_custom_interfaces__srv__CANsrv_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_custom_interfaces__srv__CANsrv_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_custom_interfaces__srv__CANsrv_Request(
  const custom_interfaces__srv__CANsrv_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_custom_interfaces__srv__CANsrv_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_custom_interfaces__srv__CANsrv_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Request)();

bool cdr_serialize_custom_interfaces__srv__CANsrv_Response(
  const custom_interfaces__srv__CANsrv_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_custom_interfaces__srv__CANsrv_Response(
  eprosima::fastcdr::Cdr & cdr,
  custom_interfaces__srv__CANsrv_Response * ros_message);

size_t get_serialized_size_custom_interfaces__srv__CANsrv_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_custom_interfaces__srv__CANsrv_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_custom_interfaces__srv__CANsrv_Response(
  const custom_interfaces__srv__CANsrv_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_custom_interfaces__srv__CANsrv_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_custom_interfaces__srv__CANsrv_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Response)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();


using _CANsrv_Event__ros_msg_type = custom_interfaces__srv__CANsrv_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_custom_interfaces__srv__CANsrv_Event(
  const custom_interfaces__srv__CANsrv_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_custom_interfaces__srv__CANsrv_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_custom_interfaces__srv__CANsrv_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_deserialize_custom_interfaces__srv__CANsrv_Event(
  eprosima::fastcdr::Cdr & cdr,
  custom_interfaces__srv__CANsrv_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->request.data) {
      custom_interfaces__srv__CANsrv_Request__Sequence__fini(&ros_message->request);
    }
    if (!custom_interfaces__srv__CANsrv_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_custom_interfaces__srv__CANsrv_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->response.data) {
      custom_interfaces__srv__CANsrv_Response__Sequence__fini(&ros_message->response);
    }
    if (!custom_interfaces__srv__CANsrv_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_custom_interfaces__srv__CANsrv_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_custom_interfaces__srv__CANsrv_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANsrv_Event__ros_msg_type * ros_message = static_cast<const _CANsrv_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_custom_interfaces__srv__CANsrv_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_custom_interfaces__srv__CANsrv_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_custom_interfaces__srv__CANsrv_Event(
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

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_custom_interfaces__srv__CANsrv_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_custom_interfaces__srv__CANsrv_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__srv__CANsrv_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_key_custom_interfaces__srv__CANsrv_Event(
  const custom_interfaces__srv__CANsrv_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_custom_interfaces__srv__CANsrv_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_custom_interfaces__srv__CANsrv_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_key_custom_interfaces__srv__CANsrv_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CANsrv_Event__ros_msg_type * ros_message = static_cast<const _CANsrv_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_custom_interfaces__srv__CANsrv_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_custom_interfaces__srv__CANsrv_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_key_custom_interfaces__srv__CANsrv_Event(
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
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_custom_interfaces__srv__CANsrv_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_custom_interfaces__srv__CANsrv_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__srv__CANsrv_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CANsrv_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const custom_interfaces__srv__CANsrv_Event * ros_message = static_cast<const custom_interfaces__srv__CANsrv_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_custom_interfaces__srv__CANsrv_Event(ros_message, cdr);
}

static bool _CANsrv_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  custom_interfaces__srv__CANsrv_Event * ros_message = static_cast<custom_interfaces__srv__CANsrv_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_custom_interfaces__srv__CANsrv_Event(cdr, ros_message);
}

static uint32_t _CANsrv_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_interfaces__srv__CANsrv_Event(
      untyped_ros_message, 0));
}

static size_t _CANsrv_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_interfaces__srv__CANsrv_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CANsrv_Event = {
  "custom_interfaces::srv",
  "CANsrv_Event",
  _CANsrv_Event__cdr_serialize,
  _CANsrv_Event__cdr_deserialize,
  _CANsrv_Event__get_serialized_size,
  _CANsrv_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CANsrv_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CANsrv_Event,
  get_message_typesupport_handle_function,
  &custom_interfaces__srv__CANsrv_Event__get_type_hash,
  &custom_interfaces__srv__CANsrv_Event__get_type_description,
  &custom_interfaces__srv__CANsrv_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Event)() {
  return &_CANsrv_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "custom_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_interfaces/srv/ca_nsrv.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t CANsrv__callbacks = {
  "custom_interfaces::srv",
  "CANsrv",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv_Response)(),
};

static rosidl_service_type_support_t CANsrv__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &CANsrv__callbacks,
  get_service_typesupport_handle_function,
  &_CANsrv_Request__type_support,
  &_CANsrv_Response__type_support,
  &_CANsrv_Event__type_support,
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

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, srv, CANsrv)() {
  return &CANsrv__handle;
}

#if defined(__cplusplus)
}
#endif
