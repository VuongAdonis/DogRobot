import struct

num = 2.0
packed = struct.pack('<f', num)  # Pack as a big-endian float
hex_value = packed.hex()
print(hex_value)  # Output will be the hexadecimal representation of the binary data.
byte_array = [hex_value[i:i+2] for i in range(0, len(hex_value), 2)]

print(byte_array)

num2 = 0
packed2 = struct.pack('<f', num2)  # Pack as a big-endian float
hex_value2 = packed2.hex()
print(hex_value2)  # Output will be the hexadecimal representation of the binary data.
byte_array2 = [hex_value2[i:i+2] for i in range(0, len(hex_value2), 2)]
for byte in byte_array2:
    byte_array.append(byte)
print(byte_array)

for index, byte in enumerate(byte_array):
    integer_value = int(byte, 16)
    print("type byte: ", type(integer_value))
    # hex_res = hex(integer_value)
    # print(type(hex_res))
    byte_array[index] = integer_value

print(type(byte_array))
print(type([0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00]))
data = [0x00, 0x00, 0x00, 0x40,
                        0x00, 0x00, 0x00, 0x00]
print("######")
print(type(byte_array[0]))
print(type(data[0]))
print("######")
print(byte_array)
print(data)
print("######")
print(byte_array[3])
print(data[3])