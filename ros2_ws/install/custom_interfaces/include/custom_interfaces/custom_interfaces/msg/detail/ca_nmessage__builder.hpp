// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/ca_nmessage.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/ca_nmessage__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_CANmessage_positionfl
{
public:
  explicit Init_CANmessage_positionfl(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::CANmessage positionfl(::custom_interfaces::msg::CANmessage::_positionfl_type arg)
  {
    msg_.positionfl = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_name4
{
public:
  explicit Init_CANmessage_name4(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_positionfl name4(::custom_interfaces::msg::CANmessage::_name4_type arg)
  {
    msg_.name4 = std::move(arg);
    return Init_CANmessage_positionfl(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_positionfr
{
public:
  explicit Init_CANmessage_positionfr(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_name4 positionfr(::custom_interfaces::msg::CANmessage::_positionfr_type arg)
  {
    msg_.positionfr = std::move(arg);
    return Init_CANmessage_name4(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_name3
{
public:
  explicit Init_CANmessage_name3(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_positionfr name3(::custom_interfaces::msg::CANmessage::_name3_type arg)
  {
    msg_.name3 = std::move(arg);
    return Init_CANmessage_positionfr(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_positionrl
{
public:
  explicit Init_CANmessage_positionrl(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_name3 positionrl(::custom_interfaces::msg::CANmessage::_positionrl_type arg)
  {
    msg_.positionrl = std::move(arg);
    return Init_CANmessage_name3(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_name2
{
public:
  explicit Init_CANmessage_name2(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_positionrl name2(::custom_interfaces::msg::CANmessage::_name2_type arg)
  {
    msg_.name2 = std::move(arg);
    return Init_CANmessage_positionrl(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_positionrr
{
public:
  explicit Init_CANmessage_positionrr(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_name2 positionrr(::custom_interfaces::msg::CANmessage::_positionrr_type arg)
  {
    msg_.positionrr = std::move(arg);
    return Init_CANmessage_name2(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_name1
{
public:
  Init_CANmessage_name1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CANmessage_positionrr name1(::custom_interfaces::msg::CANmessage::_name1_type arg)
  {
    msg_.name1 = std::move(arg);
    return Init_CANmessage_positionrr(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::CANmessage>()
{
  return custom_interfaces::msg::builder::Init_CANmessage_name1();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__BUILDER_HPP_
