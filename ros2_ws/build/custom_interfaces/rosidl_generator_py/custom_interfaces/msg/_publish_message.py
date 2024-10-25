# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/PublishMessage.idl
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


class Metaclass_PublishMessage(type):
    """Metaclass of message 'PublishMessage'."""

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
                'custom_interfaces.msg.PublishMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__publish_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__publish_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__publish_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__publish_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__publish_message

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PublishMessage(metaclass=Metaclass_PublishMessage):
    """Message class 'PublishMessage'."""

    __slots__ = [
        '_namerr',
        '_positionrr',
        '_namerl',
        '_positionrl',
        '_namefr',
        '_positionfr',
        '_namefl',
        '_positionfl',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'namerr': 'string',
        'positionrr': 'sequence<double>',
        'namerl': 'string',
        'positionrl': 'sequence<double>',
        'namefr': 'string',
        'positionfr': 'sequence<double>',
        'namefl': 'string',
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
        self.namerr = kwargs.get('namerr', str())
        self.positionrr = array.array('d', kwargs.get('positionrr', []))
        self.namerl = kwargs.get('namerl', str())
        self.positionrl = array.array('d', kwargs.get('positionrl', []))
        self.namefr = kwargs.get('namefr', str())
        self.positionfr = array.array('d', kwargs.get('positionfr', []))
        self.namefl = kwargs.get('namefl', str())
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
        if self.namerr != other.namerr:
            return False
        if self.positionrr != other.positionrr:
            return False
        if self.namerl != other.namerl:
            return False
        if self.positionrl != other.positionrl:
            return False
        if self.namefr != other.namefr:
            return False
        if self.positionfr != other.positionfr:
            return False
        if self.namefl != other.namefl:
            return False
        if self.positionfl != other.positionfl:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def namerr(self):
        """Message field 'namerr'."""
        return self._namerr

    @namerr.setter
    def namerr(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'namerr' field must be of type 'str'"
        self._namerr = value

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
    def namerl(self):
        """Message field 'namerl'."""
        return self._namerl

    @namerl.setter
    def namerl(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'namerl' field must be of type 'str'"
        self._namerl = value

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
    def namefr(self):
        """Message field 'namefr'."""
        return self._namefr

    @namefr.setter
    def namefr(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'namefr' field must be of type 'str'"
        self._namefr = value

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
    def namefl(self):
        """Message field 'namefl'."""
        return self._namefl

    @namefl.setter
    def namefl(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'namefl' field must be of type 'str'"
        self._namefl = value

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
