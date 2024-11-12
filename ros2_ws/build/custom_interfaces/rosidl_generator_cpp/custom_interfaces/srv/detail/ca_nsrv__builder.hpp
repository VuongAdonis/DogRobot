// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/CANsrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/ca_nsrv.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/ca_nsrv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_CANsrv_Request_positionfl
{
public:
  explicit Init_CANsrv_Request_positionfl(::custom_interfaces::srv::CANsrv_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::CANsrv_Request positionfl(::custom_interfaces::srv::CANsrv_Request::_positionfl_type arg)
  {
    msg_.positionfl = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

class Init_CANsrv_Request_namefl
{
public:
  explicit Init_CANsrv_Request_namefl(::custom_interfaces::srv::CANsrv_Request & msg)
  : msg_(msg)
  {}
  Init_CANsrv_Request_positionfl namefl(::custom_interfaces::srv::CANsrv_Request::_namefl_type arg)
  {
    msg_.namefl = std::move(arg);
    return Init_CANsrv_Request_positionfl(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

class Init_CANsrv_Request_positionfr
{
public:
  explicit Init_CANsrv_Request_positionfr(::custom_interfaces::srv::CANsrv_Request & msg)
  : msg_(msg)
  {}
  Init_CANsrv_Request_namefl positionfr(::custom_interfaces::srv::CANsrv_Request::_positionfr_type arg)
  {
    msg_.positionfr = std::move(arg);
    return Init_CANsrv_Request_namefl(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

class Init_CANsrv_Request_namefr
{
public:
  explicit Init_CANsrv_Request_namefr(::custom_interfaces::srv::CANsrv_Request & msg)
  : msg_(msg)
  {}
  Init_CANsrv_Request_positionfr namefr(::custom_interfaces::srv::CANsrv_Request::_namefr_type arg)
  {
    msg_.namefr = std::move(arg);
    return Init_CANsrv_Request_positionfr(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

class Init_CANsrv_Request_positionrl
{
public:
  explicit Init_CANsrv_Request_positionrl(::custom_interfaces::srv::CANsrv_Request & msg)
  : msg_(msg)
  {}
  Init_CANsrv_Request_namefr positionrl(::custom_interfaces::srv::CANsrv_Request::_positionrl_type arg)
  {
    msg_.positionrl = std::move(arg);
    return Init_CANsrv_Request_namefr(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

class Init_CANsrv_Request_namerl
{
public:
  explicit Init_CANsrv_Request_namerl(::custom_interfaces::srv::CANsrv_Request & msg)
  : msg_(msg)
  {}
  Init_CANsrv_Request_positionrl namerl(::custom_interfaces::srv::CANsrv_Request::_namerl_type arg)
  {
    msg_.namerl = std::move(arg);
    return Init_CANsrv_Request_positionrl(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

class Init_CANsrv_Request_positionrr
{
public:
  explicit Init_CANsrv_Request_positionrr(::custom_interfaces::srv::CANsrv_Request & msg)
  : msg_(msg)
  {}
  Init_CANsrv_Request_namerl positionrr(::custom_interfaces::srv::CANsrv_Request::_positionrr_type arg)
  {
    msg_.positionrr = std::move(arg);
    return Init_CANsrv_Request_namerl(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

class Init_CANsrv_Request_namerr
{
public:
  Init_CANsrv_Request_namerr()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CANsrv_Request_positionrr namerr(::custom_interfaces::srv::CANsrv_Request::_namerr_type arg)
  {
    msg_.namerr = std::move(arg);
    return Init_CANsrv_Request_positionrr(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::CANsrv_Request>()
{
  return custom_interfaces::srv::builder::Init_CANsrv_Request_namerr();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_CANsrv_Response_can_done
{
public:
  Init_CANsrv_Response_can_done()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::CANsrv_Response can_done(::custom_interfaces::srv::CANsrv_Response::_can_done_type arg)
  {
    msg_.can_done = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::CANsrv_Response>()
{
  return custom_interfaces::srv::builder::Init_CANsrv_Response_can_done();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_CANsrv_Event_response
{
public:
  explicit Init_CANsrv_Event_response(::custom_interfaces::srv::CANsrv_Event & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::CANsrv_Event response(::custom_interfaces::srv::CANsrv_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Event msg_;
};

class Init_CANsrv_Event_request
{
public:
  explicit Init_CANsrv_Event_request(::custom_interfaces::srv::CANsrv_Event & msg)
  : msg_(msg)
  {}
  Init_CANsrv_Event_response request(::custom_interfaces::srv::CANsrv_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_CANsrv_Event_response(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Event msg_;
};

class Init_CANsrv_Event_info
{
public:
  Init_CANsrv_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CANsrv_Event_request info(::custom_interfaces::srv::CANsrv_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_CANsrv_Event_request(msg_);
  }

private:
  ::custom_interfaces::srv::CANsrv_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::CANsrv_Event>()
{
  return custom_interfaces::srv::builder::Init_CANsrv_Event_info();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__BUILDER_HPP_
