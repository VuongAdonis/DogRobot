// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/IMU.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/imu.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__IMU__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/imu__struct.hpp"
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
auto build<::custom_interfaces::srv::IMU_Request>()
{
  return ::custom_interfaces::srv::IMU_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_IMU_Response_angle
{
public:
  Init_IMU_Response_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::IMU_Response angle(::custom_interfaces::srv::IMU_Response::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::IMU_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::IMU_Response>()
{
  return custom_interfaces::srv::builder::Init_IMU_Response_angle();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_IMU_Event_response
{
public:
  explicit Init_IMU_Event_response(::custom_interfaces::srv::IMU_Event & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::IMU_Event response(::custom_interfaces::srv::IMU_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::IMU_Event msg_;
};

class Init_IMU_Event_request
{
public:
  explicit Init_IMU_Event_request(::custom_interfaces::srv::IMU_Event & msg)
  : msg_(msg)
  {}
  Init_IMU_Event_response request(::custom_interfaces::srv::IMU_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_IMU_Event_response(msg_);
  }

private:
  ::custom_interfaces::srv::IMU_Event msg_;
};

class Init_IMU_Event_info
{
public:
  Init_IMU_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMU_Event_request info(::custom_interfaces::srv::IMU_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_IMU_Event_request(msg_);
  }

private:
  ::custom_interfaces::srv::IMU_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::IMU_Event>()
{
  return custom_interfaces::srv::builder::Init_IMU_Event_info();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__IMU__BUILDER_HPP_
