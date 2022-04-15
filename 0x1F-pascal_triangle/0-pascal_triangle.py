#!/usr/bin/python3
'''0-pascal_triangle module'''


def pascal_triangle(n):
    '''retuns a result of integers representing the Pascal triangle'''

    result = []

    if n <= 0:
        return result

    for i in range(n):
        result.append([1])
        for m in range(1, i):
            result[i].append(result[i - 1][m - 1] + result[i - 1][m])
        if n != 0 and i != 0:
            result[i].append(1)
    return result
