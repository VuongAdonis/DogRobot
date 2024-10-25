// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/PublishMessage.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/publish_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `namerr`
// Member `namerl`
// Member `namefr`
// Member `namefl`
#include "rosidl_runtime_c/string_functions.h"
// Member `positionrr`
// Member `positionrl`
// Member `positionfr`
// Member `positionfl`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_interfaces__msg__PublishMessage__init(custom_interfaces__msg__PublishMessage * msg)
{
  if (!msg) {
    return false;
  }
  // namerr
  if (!rosidl_runtime_c__String__init(&msg->namerr)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  // positionrr
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionrr, 0)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  // namerl
  if (!rosidl_runtime_c__String__init(&msg->namerl)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  // positionrl
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionrl, 0)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  // namefr
  if (!rosidl_runtime_c__String__init(&msg->namefr)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  // positionfr
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionfr, 0)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  // namefl
  if (!rosidl_runtime_c__String__init(&msg->namefl)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  // positionfl
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positionfl, 0)) {
    custom_interfaces__msg__PublishMessage__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__PublishMessage__fini(custom_interfaces__msg__PublishMessage * msg)
{
  if (!msg) {
    return;
  }
  // namerr
  rosidl_runtime_c__String__fini(&msg->namerr);
  // positionrr
  rosidl_runtime_c__double__Sequence__fini(&msg->positionrr);
  // namerl
  rosidl_runtime_c__String__fini(&msg->namerl);
  // positionrl
  rosidl_runtime_c__double__Sequence__fini(&msg->positionrl);
  // namefr
  rosidl_runtime_c__String__fini(&msg->namefr);
  // positionfr
  rosidl_runtime_c__double__Sequence__fini(&msg->positionfr);
  // namefl
  rosidl_runtime_c__String__fini(&msg->namefl);
  // positionfl
  rosidl_runtime_c__double__Sequence__fini(&msg->positionfl);
}

bool
custom_interfaces__msg__PublishMessage__are_equal(const custom_interfaces__msg__PublishMessage * lhs, const custom_interfaces__msg__PublishMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // namerr
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->namerr), &(rhs->namerr)))
  {
    return false;
  }
  // positionrr
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positionrr), &(rhs->positionrr)))
  {
    return false;
  }
  // namerl
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->namerl), &(rhs->namerl)))
  {
    return false;
  }
  // positionrl
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positionrl), &(rhs->positionrl)))
  {
    return false;
  }
  // namefr
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->namefr), &(rhs->namefr)))
  {
    return false;
  }
  // positionfr
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positionfr), &(rhs->positionfr)))
  {
    return false;
  }
  // namefl
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->namefl), &(rhs->namefl)))
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
custom_interfaces__msg__PublishMessage__copy(
  const custom_interfaces__msg__PublishMessage * input,
  custom_interfaces__msg__PublishMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // namerr
  if (!rosidl_runtime_c__String__copy(
      &(input->namerr), &(output->namerr)))
  {
    return false;
  }
  // positionrr
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positionrr), &(output->positionrr)))
  {
    return false;
  }
  // namerl
  if (!rosidl_runtime_c__String__copy(
      &(input->namerl), &(output->namerl)))
  {
    return false;
  }
  // positionrl
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positionrl), &(output->positionrl)))
  {
    return false;
  }
  // namefr
  if (!rosidl_runtime_c__String__copy(
      &(input->namefr), &(output->namefr)))
  {
    return false;
  }
  // positionfr
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positionfr), &(output->positionfr)))
  {
    return false;
  }
  // namefl
  if (!rosidl_runtime_c__String__copy(
      &(input->namefl), &(output->namefl)))
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

custom_interfaces__msg__PublishMessage *
custom_interfaces__msg__PublishMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__PublishMessage * msg = (custom_interfaces__msg__PublishMessage *)allocator.allocate(sizeof(custom_interfaces__msg__PublishMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__PublishMessage));
  bool success = custom_interfaces__msg__PublishMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__PublishMessage__destroy(custom_interfaces__msg__PublishMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__PublishMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__PublishMessage__Sequence__init(custom_interfaces__msg__PublishMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__PublishMessage * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__PublishMessage *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__PublishMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__PublishMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__PublishMessage__fini(&data[i - 1]);
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
custom_interfaces__msg__PublishMessage__Sequence__fini(custom_interfaces__msg__PublishMessage__Sequence * array)
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
      custom_interfaces__msg__PublishMessage__fini(&array->data[i]);
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

custom_interfaces__msg__PublishMessage__Sequence *
custom_interfaces__msg__PublishMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__PublishMessage__Sequence * array = (custom_interfaces__msg__PublishMessage__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__PublishMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__PublishMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__PublishMessage__Sequence__destroy(custom_interfaces__msg__PublishMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__PublishMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__PublishMessage__Sequence__are_equal(const custom_interfaces__msg__PublishMessage__Sequence * lhs, const custom_interfaces__msg__PublishMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__PublishMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__PublishMessage__Sequence__copy(
  const custom_interfaces__msg__PublishMessage__Sequence * input,
  custom_interfaces__msg__PublishMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__PublishMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__PublishMessage * data =
      (custom_interfaces__msg__PublishMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__PublishMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__PublishMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__PublishMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
