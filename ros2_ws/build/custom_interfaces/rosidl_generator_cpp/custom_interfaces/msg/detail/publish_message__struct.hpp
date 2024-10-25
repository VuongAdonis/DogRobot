// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/PublishMessage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/publish_message.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__PUBLISH_MESSAGE__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__PUBLISH_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__PublishMessage __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__PublishMessage __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PublishMessage_
{
  using Type = PublishMessage_<ContainerAllocator>;

  explicit PublishMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->namerr = "";
      this->namerl = "";
      this->namefr = "";
      this->namefl = "";
    }
  }

  explicit PublishMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : namerr(_alloc),
    namerl(_alloc),
    namefr(_alloc),
    namefl(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->namerr = "";
      this->namerl = "";
      this->namefr = "";
      this->namefl = "";
    }
  }

  // field types and members
  using _namerr_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namerr_type namerr;
  using _positionrr_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionrr_type positionrr;
  using _namerl_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namerl_type namerl;
  using _positionrl_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionrl_type positionrl;
  using _namefr_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namefr_type namefr;
  using _positionfr_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionfr_type positionfr;
  using _namefl_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namefl_type namefl;
  using _positionfl_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionfl_type positionfl;

  // setters for named parameter idiom
  Type & set__namerr(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namerr = _arg;
    return *this;
  }
  Type & set__positionrr(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionrr = _arg;
    return *this;
  }
  Type & set__namerl(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namerl = _arg;
    return *this;
  }
  Type & set__positionrl(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionrl = _arg;
    return *this;
  }
  Type & set__namefr(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namefr = _arg;
    return *this;
  }
  Type & set__positionfr(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionfr = _arg;
    return *this;
  }
  Type & set__namefl(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namefl = _arg;
    return *this;
  }
  Type & set__positionfl(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionfl = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::PublishMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::PublishMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::PublishMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::PublishMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__PublishMessage
    std::shared_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__PublishMessage
    std::shared_ptr<custom_interfaces::msg::PublishMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PublishMessage_ & other) const
  {
    if (this->namerr != other.namerr) {
      return false;
    }
    if (this->positionrr != other.positionrr) {
      return false;
    }
    if (this->namerl != other.namerl) {
      return false;
    }
    if (this->positionrl != other.positionrl) {
      return false;
    }
    if (this->namefr != other.namefr) {
      return false;
    }
    if (this->positionfr != other.positionfr) {
      return false;
    }
    if (this->namefl != other.namefl) {
      return false;
    }
    if (this->positionfl != other.positionfl) {
      return false;
    }
    return true;
  }
  bool operator!=(const PublishMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PublishMessage_

// alias to use template instance with default allocator
using PublishMessage =
  custom_interfaces::msg::PublishMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__PUBLISH_MESSAGE__STRUCT_HPP_
