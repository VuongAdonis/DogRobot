// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/ca_nmessage.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__CANmessage __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__CANmessage __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CANmessage_
{
  using Type = CANmessage_<ContainerAllocator>;

  explicit CANmessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name1 = "";
      this->name2 = "";
      this->name3 = "";
      this->name4 = "";
    }
  }

  explicit CANmessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name1(_alloc),
    name2(_alloc),
    name3(_alloc),
    name4(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name1 = "";
      this->name2 = "";
      this->name3 = "";
      this->name4 = "";
    }
  }

  // field types and members
  using _name1_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name1_type name1;
  using _positionrr_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionrr_type positionrr;
  using _name2_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name2_type name2;
  using _positionrl_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionrl_type positionrl;
  using _name3_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name3_type name3;
  using _positionfr_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionfr_type positionfr;
  using _name4_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name4_type name4;
  using _positionfl_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionfl_type positionfl;

  // setters for named parameter idiom
  Type & set__name1(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name1 = _arg;
    return *this;
  }
  Type & set__positionrr(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionrr = _arg;
    return *this;
  }
  Type & set__name2(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name2 = _arg;
    return *this;
  }
  Type & set__positionrl(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionrl = _arg;
    return *this;
  }
  Type & set__name3(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name3 = _arg;
    return *this;
  }
  Type & set__positionfr(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionfr = _arg;
    return *this;
  }
  Type & set__name4(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name4 = _arg;
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
    custom_interfaces::msg::CANmessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::CANmessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::CANmessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::CANmessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__CANmessage
    std::shared_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__CANmessage
    std::shared_ptr<custom_interfaces::msg::CANmessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CANmessage_ & other) const
  {
    if (this->name1 != other.name1) {
      return false;
    }
    if (this->positionrr != other.positionrr) {
      return false;
    }
    if (this->name2 != other.name2) {
      return false;
    }
    if (this->positionrl != other.positionrl) {
      return false;
    }
    if (this->name3 != other.name3) {
      return false;
    }
    if (this->positionfr != other.positionfr) {
      return false;
    }
    if (this->name4 != other.name4) {
      return false;
    }
    if (this->positionfl != other.positionfl) {
      return false;
    }
    return true;
  }
  bool operator!=(const CANmessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CANmessage_

// alias to use template instance with default allocator
using CANmessage =
  custom_interfaces::msg::CANmessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__STRUCT_HPP_
