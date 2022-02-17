#!/usr/bin/python3
'''Island Perimeter'''


def island_perimeter(grid):
    '''
        island_perimeter - return the perimeter of the island
        described in grid.
        grid - a list of list of ints, 1 represents land, 0 water
    '''
    count = 0
    # iterate throug the grid
    for i, _list in enumerate(grid):
        for j, spot in enumerate(_list):
            # if were at a 1
            if spot == 1:
                # count each edge of the spot
                count += count_edges(grid, i, j)
    return count


def count_edges(grid, i, j):
    '''
        count_edges - counts edges of a sand plot, represented by a 1 in grid
        grid - list of list ints, 1 land, 0 water
        i, j - indexes
    '''
    count = 0
    print("hello:", grid[i - 1][j])
    try:
        if i - 1 == -1 or j - 1 == -1:
            count += 1
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
