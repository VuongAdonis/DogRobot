// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/GamepadSrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/gamepad_srv.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/gamepad_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::GamepadSrv_Request>()
{
  return ::custom_interfaces::srv::GamepadSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_GamepadSrv_Response_button_stand_normal
{
public:
  explicit Init_GamepadSrv_Response_button_stand_normal(::custom_interfaces::srv::GamepadSrv_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::GamepadSrv_Response button_stand_normal(::custom_interfaces::srv::GamepadSrv_Response::_button_stand_normal_type arg)
  {
    msg_.button_stand_normal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::GamepadSrv_Response msg_;
};

class Init_GamepadSrv_Response_button_stand_down
{
public:
  explicit Init_GamepadSrv_Response_button_stand_down(::custom_interfaces::srv::GamepadSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GamepadSrv_Response_button_stand_normal button_stand_down(::custom_interfaces::srv::GamepadSrv_Response::_button_stand_down_type arg)
  {
    msg_.button_stand_down = std::move(arg);
    return Init_GamepadSrv_Response_button_stand_normal(msg_);
  }

private:
  ::custom_interfaces::srv::GamepadSrv_Response msg_;
};

class Init_GamepadSrv_Response_button_stand_up
{
public:
  explicit Init_GamepadSrv_Response_button_stand_up(::custom_interfaces::srv::GamepadSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GamepadSrv_Response_button_stand_down button_stand_up(::custom_interfaces::srv::GamepadSrv_Response::_button_stand_up_type arg)
  {
    msg_.button_stand_up = std::move(arg);
    return Init_GamepadSrv_Response_button_stand_down(msg_);
  }

private:
  ::custom_interfaces::srv::GamepadSrv_Response msg_;
};

class Init_GamepadSrv_Response_position
{
public:
  Init_GamepadSrv_Response_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GamepadSrv_Response_button_stand_up position(::custom_interfaces::srv::GamepadSrv_Response::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_GamepadSrv_Response_button_stand_up(msg_);
  }

private:
  ::custom_interfaces::srv::GamepadSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::GamepadSrv_Response>()
{
  return custom_interfaces::srv::builder::Init_GamepadSrv_Response_position();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_GamepadSrv_Event_response
{
public:
  explicit Init_GamepadSrv_Event_response(::custom_interfaces::srv::GamepadSrv_Event & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::GamepadSrv_Event response(::custom_interfaces::srv::GamepadSrv_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::GamepadSrv_Event msg_;
};

class Init_GamepadSrv_Event_request
{
public:
  explicit Init_GamepadSrv_Event_request(::custom_interfaces::srv::GamepadSrv_Event & msg)
  : msg_(msg)
  {}
  Init_GamepadSrv_Event_response request(::custom_interfaces::srv::GamepadSrv_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GamepadSrv_Event_response(msg_);
  }

private:
  ::custom_interfaces::srv::GamepadSrv_Event msg_;
};

class Init_GamepadSrv_Event_info
{
public:
  Init_GamepadSrv_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GamepadSrv_Event_request info(::custom_interfaces::srv::GamepadSrv_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GamepadSrv_Event_request(msg_);
  }

private:
  ::custom_interfaces::srv::GamepadSrv_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::GamepadSrv_Event>()
{
  return custom_interfaces::srv::builder::Init_GamepadSrv_Event_info();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__BUILDER_HPP_
