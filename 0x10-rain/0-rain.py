#!/usr/bin/python3
'''
calculate how many square units of water will be retained after it rains
'''


def rain(walls):
    '''calculate how many units of water will be retained after it rains'''

    if walls is []:
        return 0

    for wall in walls:
        if wall < 0:
            return 0

    rain = 0
    # for ever element in the array
    for i, num in enumerate(walls):
        # find max element on left
        lm = max(walls[:i + 1])

        # find max element on right
        rm = max(walls[i:])
        small = min(lm, rm)

        # update max rain water
        rain += max(small - num, 0)

    return rain
