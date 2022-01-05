#!/usr/bin/python3
''' rotate 2D matrix module '''


def rotate_2d_matrix(matrix):
        '''function that rotates a 2D matrix 90 degrees clockwise'''

        ''' [::-1] will reverse the list, the zip operater returns an
            iterator of tuples, and list() converts it back.... python'''
        rotated = list(zip(*matrix[::-1]))
        for rows in range(len(matrix)):
            for cols in range(len(matrix)):
                matrix[rows][cols] = rotated[rows][cols]
