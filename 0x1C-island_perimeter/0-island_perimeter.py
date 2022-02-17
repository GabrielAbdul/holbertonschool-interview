#!/usr/bin/python3
'''Island Perimeter'''


def island_perimeter(grid):
    '''
        island_perimeter - return the perimeter of the island
        described in grid.
        grid - a list of list of ints, 1 represents land, 0 water
    '''
    count = 0
    for i, _list in enumerate(grid):
        for j, spot in enumerate(_list):
            if spot == 1:
                count += count_edges(grid, i, j)
    return count


def count_edges(grid, i, j):
    '''
        count_edges - counts edges of a sand plot, represented by a 1 in grid
        grid - list of list ints, 1 land, 0 water
        i, j - indexes
    '''
    count = 0
    try:
        if grid[i - 1][j] == 0:
            count += 1
        if grid[i + 1][j] == 0:
            count += 1
        if grid[i][j - 1] == 0:
            count += 1
        if grid[i][j + 1] == 0:
            count += 1
    except IndexError:
        count += 1

    return count
