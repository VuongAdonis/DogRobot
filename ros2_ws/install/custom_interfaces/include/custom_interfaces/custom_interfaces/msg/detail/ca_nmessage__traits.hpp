// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/CANmessage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/ca_nmessage.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/ca_nmessage__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CANmessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: name1
  {
    out << "name1: ";
    rosidl_generator_traits::value_to_yaml(msg.name1, out);
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

  // member: name2
  {
    out << "name2: ";
    rosidl_generator_traits::value_to_yaml(msg.name2, out);
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

  // member: name3
  {
    out << "name3: ";
    rosidl_generator_traits::value_to_yaml(msg.name3, out);
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

  // member: name4
  {
    out << "name4: ";
    rosidl_generator_traits::value_to_yaml(msg.name4, out);
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
  const CANmessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name1: ";
    rosidl_generator_traits::value_to_yaml(msg.name1, out);
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

  // member: name2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name2: ";
    rosidl_generator_traits::value_to_yaml(msg.name2, out);
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

  // member: name3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name3: ";
    rosidl_generator_traits::value_to_yaml(msg.name3, out);
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

  // member: name4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name4: ";
    rosidl_generator_traits::value_to_yaml(msg.name4, out);
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

inline std::string to_yaml(const CANmessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::CANmessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::CANmessage & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::CANmessage>()
{
  return "custom_interfaces::msg::CANmessage";
}

template<>
inline const char * name<custom_interfaces::msg::CANmessage>()
{
  return "custom_interfaces/msg/CANmessage";
}

template<>
struct has_fixed_size<custom_interfaces::msg::CANmessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::CANmessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::CANmessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CA_NMESSAGE__TRAITS_HPP_
