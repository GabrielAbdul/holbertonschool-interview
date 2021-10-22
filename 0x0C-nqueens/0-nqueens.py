#!/usr/bin/python3
''' nQueens '''

from sys import argv


def legit(arr, pos):
    ''' makes sure position is legit '''
    for queen in arr:
        if queen[1] == pos[1]:
            return False
        if (queen[0] + queen[1]) == (pos[0] + pos[1]):
            return False
        if (queen[0] - queen[1]) == (pos[0] - pos[1]):
            return False
    return True


def nQueens(arr, n, row):
    """
    Function that finds the arr recursively, from the root down
    """
    if (row == n):
        print(arr)
    else:
        for col in range(n):
            pos = [row, col]
            if legit(arr, pos):
                arr.append(pos)
                nQueens(arr, n, row + 1)
                arr.remove(pos)


def solveNQueens(n):
    """entry point"""
    arr = []
    nQueens(arr, n, 0)


def printUsageAndExit():
    """prints usage and exits"""
    if len(argv) < 2 or len(argv) > 2:
        print("Usage: nqueens N")
        exit(1)

    if not argv[1].isdigit():
        print("N must be a number")
        exit(1)

    if int(argv[1]) < 4:
        print("N must be at least 4")
        exit(1)


if __name__ == '__main__':
    """ Validate the arguments from OS """
    printUsageAndExit()
    solveNQueens(int(argv[1]))
