# Find the shortest path from 0,0 to n-1,n-1 in a maze where 0=path
# and 1=wall.

def shortest(maze, n):
    cells_to_visit = [(0,0,0)]
    visited = []

    distances = []
    for x in range(0, n-1):
        distances.append([-1 for y in range(0,n-1)])
    distances[0][0] = 0

    while len(cells_to_visit) != 0:
        # prioritize lowest dist
        cells_to_visit = sorted(cells_to_visit)
        print(cells_to_visit)
        prio,x,y = cells_to_visit.pop(0)

        # check up
        if x > 0 and maze[x-1][y] == 0 and (x-1,y) not in visited:
            if distances[x-1][y] == -1 or distances[x-1][y] > distances[x][y]+1:
                distances[x-1][y] = distances[x][y] + 1
                cells_to_visit.append((distances[x][y]+1,x-1,y))

        # check down
        if x < n - 2 and maze[x+1][y] == 0 and (x+1,y) not in visited:
            if distances[x+1][y] == -1 or distances[x+1][y] > distances[x][y]+1:
                distances[x+1][y] = distances[x][y] + 1
                cells_to_visit.append((distances[x][y]+1,x+1,y))

        # check right
        if y > 0 and maze[x][y-1] == 0 and (x,y-1) not in visited:
            if distances[x][y-1] == -1 or distances[x][y-1] > distances[x][y]+1:
                distances[x][y-1] = distances[x][y] + 1
                cells_to_visit.append((distances[x][y]+1,x,y-1))

        # check left
        if y < n - 2 and maze[x][y+1] == 0 and (x,y+1) not in visited:
            if distances[x][y+1] == -1 or distances[x][y+1] > distances[x][y]+1:
                distances[x][y+1] = distances[x][y] + 1
                cells_to_visit.append((distances[x][y]+1,x,y+1))

        visited.append((x,y))
        
    print('\n----------------------------\n')
    for line in distances:
        for v in line:
            print('%3.0f' % v, end=' ')
        print('\n')
    print('----------------------------\n')
    return distances[n-2][n-2]

maze = [
    [0,1,1,1,1,0],
    [0,0,0,1,0,0],
    [0,1,0,0,0,0],
    [0,0,1,0,1,0],
    [1,0,0,0,1,0],
    [0,0,1,1,1,0],
]

print(shortest(maze, 7))
