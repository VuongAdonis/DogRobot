// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/PublishMessage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/publish_message.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__PUBLISH_MESSAGE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__PUBLISH_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/publish_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_PublishMessage_positionfl
{
public:
  explicit Init_PublishMessage_positionfl(::custom_interfaces::msg::PublishMessage & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::PublishMessage positionfl(::custom_interfaces::msg::PublishMessage::_positionfl_type arg)
  {
    msg_.positionfl = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

class Init_PublishMessage_namefl
{
public:
  explicit Init_PublishMessage_namefl(::custom_interfaces::msg::PublishMessage & msg)
  : msg_(msg)
  {}
  Init_PublishMessage_positionfl namefl(::custom_interfaces::msg::PublishMessage::_namefl_type arg)
  {
    msg_.namefl = std::move(arg);
    return Init_PublishMessage_positionfl(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

class Init_PublishMessage_positionfr
{
public:
  explicit Init_PublishMessage_positionfr(::custom_interfaces::msg::PublishMessage & msg)
  : msg_(msg)
  {}
  Init_PublishMessage_namefl positionfr(::custom_interfaces::msg::PublishMessage::_positionfr_type arg)
  {
    msg_.positionfr = std::move(arg);
    return Init_PublishMessage_namefl(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

class Init_PublishMessage_namefr
{
public:
  explicit Init_PublishMessage_namefr(::custom_interfaces::msg::PublishMessage & msg)
  : msg_(msg)
  {}
  Init_PublishMessage_positionfr namefr(::custom_interfaces::msg::PublishMessage::_namefr_type arg)
  {
    msg_.namefr = std::move(arg);
    return Init_PublishMessage_positionfr(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

class Init_PublishMessage_positionrl
{
public:
  explicit Init_PublishMessage_positionrl(::custom_interfaces::msg::PublishMessage & msg)
  : msg_(msg)
  {}
  Init_PublishMessage_namefr positionrl(::custom_interfaces::msg::PublishMessage::_positionrl_type arg)
  {
    msg_.positionrl = std::move(arg);
    return Init_PublishMessage_namefr(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

class Init_PublishMessage_namerl
{
public:
  explicit Init_PublishMessage_namerl(::custom_interfaces::msg::PublishMessage & msg)
  : msg_(msg)
  {}
  Init_PublishMessage_positionrl namerl(::custom_interfaces::msg::PublishMessage::_namerl_type arg)
  {
    msg_.namerl = std::move(arg);
    return Init_PublishMessage_positionrl(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

class Init_PublishMessage_positionrr
{
public:
  explicit Init_PublishMessage_positionrr(::custom_interfaces::msg::PublishMessage & msg)
  : msg_(msg)
  {}
  Init_PublishMessage_namerl positionrr(::custom_interfaces::msg::PublishMessage::_positionrr_type arg)
  {
    msg_.positionrr = std::move(arg);
    return Init_PublishMessage_namerl(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

class Init_PublishMessage_namerr
{
public:
  Init_PublishMessage_namerr()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PublishMessage_positionrr namerr(::custom_interfaces::msg::PublishMessage::_namerr_type arg)
  {
    msg_.namerr = std::move(arg);
    return Init_PublishMessage_positionrr(msg_);
  }

private:
  ::custom_interfaces::msg::PublishMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::PublishMessage>()
{
  return custom_interfaces::msg::builder::Init_PublishMessage_namerr();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__PUBLISH_MESSAGE__BUILDER_HPP_
