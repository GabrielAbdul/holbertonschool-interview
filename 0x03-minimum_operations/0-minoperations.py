#!/usr/bin/python3
'''
 calculates the fewest number of operations needed to
 result in exactly n H characters in the file.
'''


def minOperations(n):
    '''min Operations'''

    if n <= 1:
        return 0

    # n is 100
    for index in range(2, n):
        if n % index == 0:
            return minOperations(int(n / index)) + index

    return n
