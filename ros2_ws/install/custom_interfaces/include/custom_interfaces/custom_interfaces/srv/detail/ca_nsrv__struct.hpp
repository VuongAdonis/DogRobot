// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/CANsrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/ca_nsrv.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__CANsrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__CANsrv_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CANsrv_Request_
{
  using Type = CANsrv_Request_<ContainerAllocator>;

  explicit CANsrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->namerr = "";
      this->namerl = "";
      this->namefr = "";
      this->namefl = "";
    }
  }

  explicit CANsrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : namerr(_alloc),
    namerl(_alloc),
    namefr(_alloc),
    namefl(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->namerr = "";
      this->namerl = "";
      this->namefr = "";
      this->namefl = "";
    }
  }

  // field types and members
  using _namerr_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namerr_type namerr;
  using _positionrr_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionrr_type positionrr;
  using _namerl_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namerl_type namerl;
  using _positionrl_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionrl_type positionrl;
  using _namefr_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namefr_type namefr;
  using _positionfr_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionfr_type positionfr;
  using _namefl_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namefl_type namefl;
  using _positionfl_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positionfl_type positionfl;

  // setters for named parameter idiom
  Type & set__namerr(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namerr = _arg;
    return *this;
  }
  Type & set__positionrr(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionrr = _arg;
    return *this;
  }
  Type & set__namerl(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namerl = _arg;
    return *this;
  }
  Type & set__positionrl(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionrl = _arg;
    return *this;
  }
  Type & set__namefr(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namefr = _arg;
    return *this;
  }
  Type & set__positionfr(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positionfr = _arg;
    return *this;
  }
  Type & set__namefl(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namefl = _arg;
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
    custom_interfaces::srv::CANsrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::CANsrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__CANsrv_Request
    std::shared_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__CANsrv_Request
    std::shared_ptr<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CANsrv_Request_ & other) const
  {
    if (this->namerr != other.namerr) {
      return false;
    }
    if (this->positionrr != other.positionrr) {
      return false;
    }
    if (this->namerl != other.namerl) {
      return false;
    }
    if (this->positionrl != other.positionrl) {
      return false;
    }
    if (this->namefr != other.namefr) {
      return false;
    }
    if (this->positionfr != other.positionfr) {
      return false;
    }
    if (this->namefl != other.namefl) {
      return false;
    }
    if (this->positionfl != other.positionfl) {
      return false;
    }
    return true;
  }
  bool operator!=(const CANsrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CANsrv_Request_

// alias to use template instance with default allocator
using CANsrv_Request =
  custom_interfaces::srv::CANsrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__CANsrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__CANsrv_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CANsrv_Response_
{
  using Type = CANsrv_Response_<ContainerAllocator>;

  explicit CANsrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->can_done = 0;
    }
  }

  explicit CANsrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->can_done = 0;
    }
  }

  // field types and members
  using _can_done_type =
    int8_t;
  _can_done_type can_done;

  // setters for named parameter idiom
  Type & set__can_done(
    const int8_t & _arg)
  {
    this->can_done = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::CANsrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::CANsrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__CANsrv_Response
    std::shared_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__CANsrv_Response
    std::shared_ptr<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CANsrv_Response_ & other) const
  {
    if (this->can_done != other.can_done) {
      return false;
    }
    return true;
  }
  bool operator!=(const CANsrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CANsrv_Response_

// alias to use template instance with default allocator
using CANsrv_Response =
  custom_interfaces::srv::CANsrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__CANsrv_Event __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__CANsrv_Event __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CANsrv_Event_
{
  using Type = CANsrv_Event_<ContainerAllocator>;

  explicit CANsrv_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit CANsrv_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::CANsrv_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::CANsrv_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::CANsrv_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::CANsrv_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::CANsrv_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::CANsrv_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__CANsrv_Event
    std::shared_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__CANsrv_Event
    std::shared_ptr<custom_interfaces::srv::CANsrv_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CANsrv_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const CANsrv_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CANsrv_Event_

// alias to use template instance with default allocator
using CANsrv_Event =
  custom_interfaces::srv::CANsrv_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct CANsrv
{
  using Request = custom_interfaces::srv::CANsrv_Request;
  using Response = custom_interfaces::srv::CANsrv_Response;
  using Event = custom_interfaces::srv::CANsrv_Event;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__CA_NSRV__STRUCT_HPP_
