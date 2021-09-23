#!/usr/bin/python3
"""
UTF-8 Validation Module
"""


def validUTF8(data):
    """determines if a given data set represents valid UTF-8 encoding"""

    # byte counter, must be between 1 > 4
    numBytes = 0

    # for each int
    for num in data:

        # get binary representation of least significant 8 bits
        binaryRepr = format(num, '#010b')[-8:]

        # start on a new utf8 char
        if numBytes == 0:

            # get number of 1s
            for bit in binaryRepr:
                if bit == '0':
                    break
                numBytes += 1

            # 1 byte chars start with 0
            if numBytes == 0:
                continue

            # num bytes must be between 1-4
            if numBytes == 1 or numBytes > 4:
                return False

        else:
            # UTF-8 ints must start with 10
            if not (binaryRepr[0] == '1' and binaryRepr[1] == '0'):
                return False

        # decrement number of bytes to process by 1 after each int
        numBytes -= 1

    return numBytes == 0
