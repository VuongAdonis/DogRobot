# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/CANmessage.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'positionrr'
# Member 'positionrl'
# Member 'positionfr'
# Member 'positionfl'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CANmessage(type):
    """Metaclass of message 'CANmessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.msg.CANmessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ca_nmessage
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ca_nmessage
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ca_nmessage
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ca_nmessage
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ca_nmessage

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CANmessage(metaclass=Metaclass_CANmessage):
    """Message class 'CANmessage'."""

    __slots__ = [
        '_name1',
        '_positionrr',
        '_name2',
        '_positionrl',
        '_name3',
        '_positionfr',
        '_name4',
        '_positionfl',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'name1': 'string',
        'positionrr': 'sequence<double>',
        'name2': 'string',
        'positionrl': 'sequence<double>',
        'name3': 'string',
        'positionfr': 'sequence<double>',
        'name4': 'string',
        'positionfl': 'sequence<double>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name1 = kwargs.get('name1', str())
        self.positionrr = array.array('d', kwargs.get('positionrr', []))
        self.name2 = kwargs.get('name2', str())
        self.positionrl = array.array('d', kwargs.get('positionrl', []))
        self.name3 = kwargs.get('name3', str())
        self.positionfr = array.array('d', kwargs.get('positionfr', []))
        self.name4 = kwargs.get('name4', str())
        self.positionfl = array.array('d', kwargs.get('positionfl', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.name1 != other.name1:
            return False
        if self.positionrr != other.positionrr:
            return False
        if self.name2 != other.name2:
            return False
        if self.positionrl != other.positionrl:
            return False
        if self.name3 != other.name3:
            return False
        if self.positionfr != other.positionfr:
            return False
        if self.name4 != other.name4:
            return False
        if self.positionfl != other.positionfl:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name1(self):
        """Message field 'name1'."""
        return self._name1

    @name1.setter
    def name1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'name1' field must be of type 'str'"
        self._name1 = value

    @builtins.property
    def positionrr(self):
        """Message field 'positionrr'."""
        return self._positionrr

    @positionrr.setter
    def positionrr(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'positionrr' array.array() must have the type code of 'd'"
                self._positionrr = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'positionrr' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._positionrr = array.array('d', value)

    @builtins.property
    def name2(self):
        """Message field 'name2'."""
        return self._name2

    @name2.setter
    def name2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'name2' field must be of type 'str'"
        self._name2 = value

    @builtins.property
    def positionrl(self):
        """Message field 'positionrl'."""
        return self._positionrl

    @positionrl.setter
    def positionrl(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'positionrl' array.array() must have the type code of 'd'"
                self._positionrl = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'positionrl' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._positionrl = array.array('d', value)

    @builtins.property
    def name3(self):
        """Message field 'name3'."""
        return self._name3

    @name3.setter
    def name3(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'name3' field must be of type 'str'"
        self._name3 = value

    @builtins.property
    def positionfr(self):
        """Message field 'positionfr'."""
        return self._positionfr

    @positionfr.setter
    def positionfr(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'positionfr' array.array() must have the type code of 'd'"
                self._positionfr = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'positionfr' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._positionfr = array.array('d', value)

    @builtins.property
    def name4(self):
        """Message field 'name4'."""
        return self._name4

    @name4.setter
    def name4(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'name4' field must be of type 'str'"
        self._name4 = value

    @builtins.property
    def positionfl(self):
        """Message field 'positionfl'."""
        return self._positionfl

    @positionfl.setter
    def positionfl(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'positionfl' array.array() must have the type code of 'd'"
                self._positionfl = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'positionfl' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._positionfl = array.array('d', value)
