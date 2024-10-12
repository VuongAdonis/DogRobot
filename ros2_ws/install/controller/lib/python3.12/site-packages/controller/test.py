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
