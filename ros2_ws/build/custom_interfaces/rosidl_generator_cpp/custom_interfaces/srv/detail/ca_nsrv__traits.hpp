// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/CANsrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/ca_nsrv.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/ca_nsrv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CANsrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: namerr
  {
    out << "namerr: ";
    rosidl_generator_traits::value_to_yaml(msg.namerr, out);
    out << ", ";
  }

  // member: positionrr
  {
    if (msg.positionrr.size() == 0) {
      out << "positionrr: []";
    } else {
      out << "positionrr: [";
      size_t pending_items = msg.positionrr.size();
      for (auto item : msg.positionrr) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: namerl
  {
    out << "namerl: ";
    rosidl_generator_traits::value_to_yaml(msg.namerl, out);
    out << ", ";
  }

  // member: positionrl
  {
    if (msg.positionrl.size() == 0) {
      out << "positionrl: []";
    } else {
      out << "positionrl: [";
      size_t pending_items = msg.positionrl.size();
      for (auto item : msg.positionrl) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: namefr
  {
    out << "namefr: ";
    rosidl_generator_traits::value_to_yaml(msg.namefr, out);
    out << ", ";
  }

  // member: positionfr
  {
    if (msg.positionfr.size() == 0) {
      out << "positionfr: []";
    } else {
      out << "positionfr: [";
      size_t pending_items = msg.positionfr.size();
      for (auto item : msg.positionfr) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: namefl
  {
    out << "namefl: ";
    rosidl_generator_traits::value_to_yaml(msg.namefl, out);
    out << ", ";
  }

  // member: positionfl
  {
    if (msg.positionfl.size() == 0) {
      out << "positionfl: []";
    } else {
      out << "positionfl: [";
      size_t pending_items = msg.positionfl.size();
      for (auto item : msg.positionfl) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const CANsrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: namerr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "namerr: ";
    rosidl_generator_traits::value_to_yaml(msg.namerr, out);
    out << "\n";
  }

  // member: positionrr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positionrr.size() == 0) {
      out << "positionrr: []\n";
    } else {
      out << "positionrr:\n";
      for (auto item : msg.positionrr) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: namerl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "namerl: ";
    rosidl_generator_traits::value_to_yaml(msg.namerl, out);
    out << "\n";
  }

  // member: positionrl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positionrl.size() == 0) {
      out << "positionrl: []\n";
    } else {
      out << "positionrl:\n";
      for (auto item : msg.positionrl) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: namefr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "namefr: ";
    rosidl_generator_traits::value_to_yaml(msg.namefr, out);
    out << "\n";
  }

  // member: positionfr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positionfr.size() == 0) {
      out << "positionfr: []\n";
    } else {
      out << "positionfr:\n";
      for (auto item : msg.positionfr) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: namefl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "namefl: ";
    rosidl_generator_traits::value_to_yaml(msg.namefl, out);
    out << "\n";
  }

  // member: positionfl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positionfl.size() == 0) {
      out << "positionfl: []\n";
    } else {
      out << "positionfl:\n";
      for (auto item : msg.positionfl) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CANsrv_Request & msg, bool use_flow_style = false)
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
  const custom_interfaces::srv::CANsrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::CANsrv_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::CANsrv_Request>()
{
  return "custom_interfaces::srv::CANsrv_Request";
}

template<>
inline const char * name<custom_interfaces::srv::CANsrv_Request>()
{
  return "custom_interfaces/srv/CANsrv_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::CANsrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::CANsrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::CANsrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CANsrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: can_done
  {
    out << "can_done: ";
    rosidl_generator_traits::value_to_yaml(msg.can_done, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CANsrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: can_done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_done: ";
    rosidl_generator_traits::value_to_yaml(msg.can_done, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CANsrv_Response & msg, bool use_flow_style = false)
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
  const custom_interfaces::srv::CANsrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::CANsrv_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::CANsrv_Response>()
{
  return "custom_interfaces::srv::CANsrv_Response";
}

template<>
inline const char * name<custom_interfaces::srv::CANsrv_Response>()
{
  return "custom_interfaces/srv/CANsrv_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::CANsrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::CANsrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::CANsrv_Response>
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
  const CANsrv_Event & msg,
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
  const CANsrv_Event & msg,
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

inline std::string to_yaml(const CANsrv_Event & msg, bool use_flow_style = false)
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
  const custom_interfaces::srv::CANsrv_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::CANsrv_Event & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::CANsrv_Event>()
{
  return "custom_interfaces::srv::CANsrv_Event";
}

template<>
inline const char * name<custom_interfaces::srv::CANsrv_Event>()
{
  return "custom_interfaces/srv/CANsrv_Event";
}

template<>
struct has_fixed_size<custom_interfaces::srv::CANsrv_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::CANsrv_Event>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::srv::CANsrv_Request>::value && has_bounded_size<custom_interfaces::srv::CANsrv_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<custom_interfaces::srv::CANsrv_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::CANsrv>()
{
  return "custom_interfaces::srv::CANsrv";
}

template<>
inline const char * name<custom_interfaces::srv::CANsrv>()
{
  return "custom_interfaces/srv/CANsrv";
}

template<>
struct has_fixed_size<custom_interfaces::srv::CANsrv>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::CANsrv_Request>::value &&
    has_fixed_size<custom_interfaces::srv::CANsrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::CANsrv>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::CANsrv_Request>::value &&
    has_bounded_size<custom_interfaces::srv::CANsrv_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::CANsrv>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::CANsrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::CANsrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__TRAITS_HPP_
