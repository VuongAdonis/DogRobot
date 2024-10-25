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

class Init_CANmessage_namefl
{
public:
  explicit Init_CANmessage_namefl(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_positionfl namefl(::custom_interfaces::msg::CANmessage::_namefl_type arg)
  {
    msg_.namefl = std::move(arg);
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
  Init_CANmessage_namefl positionfr(::custom_interfaces::msg::CANmessage::_positionfr_type arg)
  {
    msg_.positionfr = std::move(arg);
    return Init_CANmessage_namefl(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_namefr
{
public:
  explicit Init_CANmessage_namefr(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_positionfr namefr(::custom_interfaces::msg::CANmessage::_namefr_type arg)
  {
    msg_.namefr = std::move(arg);
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
  Init_CANmessage_namefr positionrl(::custom_interfaces::msg::CANmessage::_positionrl_type arg)
  {
    msg_.positionrl = std::move(arg);
    return Init_CANmessage_namefr(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_namerl
{
public:
  explicit Init_CANmessage_namerl(::custom_interfaces::msg::CANmessage & msg)
  : msg_(msg)
  {}
  Init_CANmessage_positionrl namerl(::custom_interfaces::msg::CANmessage::_namerl_type arg)
  {
    msg_.namerl = std::move(arg);
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
  Init_CANmessage_namerl positionrr(::custom_interfaces::msg::CANmessage::_positionrr_type arg)
  {
    msg_.positionrr = std::move(arg);
    return Init_CANmessage_namerl(msg_);
  }

private:
  ::custom_interfaces::msg::CANmessage msg_;
};

class Init_CANmessage_namerr
{
public:
  Init_CANmessage_namerr()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CANmessage_positionrr namerr(::custom_interfaces::msg::CANmessage::_namerr_type arg)
  {
    msg_.namerr = std::move(arg);
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
  return custom_interfaces::msg::builder::Init_CANmessage_namerr();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__BUILDER_HPP_
