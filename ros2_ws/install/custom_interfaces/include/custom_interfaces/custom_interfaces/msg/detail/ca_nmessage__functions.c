// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/ca_nmessage__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


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

bool
custom_interfaces__msg__CANmessage__init(custom_interfaces__msg__CANmessage * msg)
{
  if (!msg) {
    return false;
  }
  // name1
  if (!rosidl_runtime_c__String__init(&msg->name1)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  // positionrr
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionrr, 0)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  // name2
  if (!rosidl_runtime_c__String__init(&msg->name2)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  // positionrl
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionrl, 0)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  // name3
  if (!rosidl_runtime_c__String__init(&msg->name3)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  // positionfr
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionfr, 0)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  // name4
  if (!rosidl_runtime_c__String__init(&msg->name4)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  // positionfl
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionfl, 0)) {
    custom_interfaces__msg__CANmessage__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__CANmessage__fini(custom_interfaces__msg__CANmessage * msg)
{
  if (!msg) {
    return;
  }
  // name1
  rosidl_runtime_c__String__fini(&msg->name1);
  // positionrr
  rosidl_runtime_c__double__Sequence__fini(&msg->positionrr);
  // name2
  rosidl_runtime_c__String__fini(&msg->name2);
  // positionrl
  rosidl_runtime_c__double__Sequence__fini(&msg->positionrl);
  // name3
  rosidl_runtime_c__String__fini(&msg->name3);
  // positionfr
  rosidl_runtime_c__double__Sequence__fini(&msg->positionfr);
  // name4
  rosidl_runtime_c__String__fini(&msg->name4);
  // positionfl
  rosidl_runtime_c__double__Sequence__fini(&msg->positionfl);
}

bool
custom_interfaces__msg__CANmessage__are_equal(const custom_interfaces__msg__CANmessage * lhs, const custom_interfaces__msg__CANmessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name1
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name1), &(rhs->name1)))
  {
    return false;
  }
  // positionrr
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positionrr), &(rhs->positionrr)))
  {
    return false;
  }
  // name2
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name2), &(rhs->name2)))
  {
    return false;
  }
  // positionrl
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positionrl), &(rhs->positionrl)))
  {
    return false;
  }
  // name3
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name3), &(rhs->name3)))
  {
    return false;
  }
  // positionfr
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positionfr), &(rhs->positionfr)))
  {
    return false;
  }
  // name4
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name4), &(rhs->name4)))
  {
    return false;
  }
  // positionfl
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positionfl), &(rhs->positionfl)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__CANmessage__copy(
  const custom_interfaces__msg__CANmessage * input,
  custom_interfaces__msg__CANmessage * output)
{
  if (!input || !output) {
    return false;
  }
  // name1
  if (!rosidl_runtime_c__String__copy(
      &(input->name1), &(output->name1)))
  {
    return false;
  }
  // positionrr
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positionrr), &(output->positionrr)))
  {
    return false;
  }
  // name2
  if (!rosidl_runtime_c__String__copy(
      &(input->name2), &(output->name2)))
  {
    return false;
  }
  // positionrl
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positionrl), &(output->positionrl)))
  {
    return false;
  }
  // name3
  if (!rosidl_runtime_c__String__copy(
      &(input->name3), &(output->name3)))
  {
    return false;
  }
  // positionfr
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positionfr), &(output->positionfr)))
  {
    return false;
  }
  // name4
  if (!rosidl_runtime_c__String__copy(
      &(input->name4), &(output->name4)))
  {
    return false;
  }
  // positionfl
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positionfl), &(output->positionfl)))
  {
    return false;
  }
  return true;
}

custom_interfaces__msg__CANmessage *
custom_interfaces__msg__CANmessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__CANmessage * msg = (custom_interfaces__msg__CANmessage *)allocator.allocate(sizeof(custom_interfaces__msg__CANmessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__CANmessage));
  bool success = custom_interfaces__msg__CANmessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__CANmessage__destroy(custom_interfaces__msg__CANmessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__CANmessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__CANmessage__Sequence__init(custom_interfaces__msg__CANmessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__CANmessage * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__CANmessage *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__CANmessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__CANmessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__CANmessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__msg__CANmessage__Sequence__fini(custom_interfaces__msg__CANmessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__msg__CANmessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__msg__CANmessage__Sequence *
custom_interfaces__msg__CANmessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__CANmessage__Sequence * array = (custom_interfaces__msg__CANmessage__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__CANmessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__CANmessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__CANmessage__Sequence__destroy(custom_interfaces__msg__CANmessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__CANmessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__CANmessage__Sequence__are_equal(const custom_interfaces__msg__CANmessage__Sequence * lhs, const custom_interfaces__msg__CANmessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__CANmessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__CANmessage__Sequence__copy(
  const custom_interfaces__msg__CANmessage__Sequence * input,
  custom_interfaces__msg__CANmessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__CANmessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__CANmessage * data =
      (custom_interfaces__msg__CANmessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__CANmessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__CANmessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__CANmessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
