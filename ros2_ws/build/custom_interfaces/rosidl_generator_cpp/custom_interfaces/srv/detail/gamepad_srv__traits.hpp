// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/GamepadSrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/gamepad_srv.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/gamepad_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GamepadSrv_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GamepadSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GamepadSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::GamepadSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::GamepadSrv_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::GamepadSrv_Request>()
{
  return "custom_interfaces::srv::GamepadSrv_Request";
}

template<>
inline const char * name<custom_interfaces::srv::GamepadSrv_Request>()
{
  return "custom_interfaces/srv/GamepadSrv_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::GamepadSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::GamepadSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::GamepadSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GamepadSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: button_stand_up
  {
    out << "button_stand_up: ";
    rosidl_generator_traits::value_to_yaml(msg.button_stand_up, out);
    out << ", ";
  }

  // member: button_stand_down
  {
    out << "button_stand_down: ";
    rosidl_generator_traits::value_to_yaml(msg.button_stand_down, out);
    out << ", ";
  }

  // member: button_stand_normal
  {
    out << "button_stand_normal: ";
    rosidl_generator_traits::value_to_yaml(msg.button_stand_normal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GamepadSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: button_stand_up
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "button_stand_up: ";
    rosidl_generator_traits::value_to_yaml(msg.button_stand_up, out);
    out << "\n";
  }

  // member: button_stand_down
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "button_stand_down: ";
    rosidl_generator_traits::value_to_yaml(msg.button_stand_down, out);
    out << "\n";
  }

  // member: button_stand_normal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "button_stand_normal: ";
    rosidl_generator_traits::value_to_yaml(msg.button_stand_normal, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GamepadSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::GamepadSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::GamepadSrv_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::GamepadSrv_Response>()
{
  return "custom_interfaces::srv::GamepadSrv_Response";
}

template<>
inline const char * name<custom_interfaces::srv::GamepadSrv_Response>()
{
  return "custom_interfaces/srv/GamepadSrv_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::GamepadSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::GamepadSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::GamepadSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GamepadSrv_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GamepadSrv_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GamepadSrv_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::GamepadSrv_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::GamepadSrv_Event & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::GamepadSrv_Event>()
{
  return "custom_interfaces::srv::GamepadSrv_Event";
}

template<>
inline const char * name<custom_interfaces::srv::GamepadSrv_Event>()
{
  return "custom_interfaces/srv/GamepadSrv_Event";
}

template<>
struct has_fixed_size<custom_interfaces::srv::GamepadSrv_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::GamepadSrv_Event>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::srv::GamepadSrv_Request>::value && has_bounded_size<custom_interfaces::srv::GamepadSrv_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<custom_interfaces::srv::GamepadSrv_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::GamepadSrv>()
{
  return "custom_interfaces::srv::GamepadSrv";
}

template<>
inline const char * name<custom_interfaces::srv::GamepadSrv>()
{
  return "custom_interfaces/srv/GamepadSrv";
}

template<>
struct has_fixed_size<custom_interfaces::srv::GamepadSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::GamepadSrv_Request>::value &&
    has_fixed_size<custom_interfaces::srv::GamepadSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::GamepadSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::GamepadSrv_Request>::value &&
    has_bounded_size<custom_interfaces::srv::GamepadSrv_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::GamepadSrv>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::GamepadSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::GamepadSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__GAMEPAD_SRV__TRAITS_HPP_
