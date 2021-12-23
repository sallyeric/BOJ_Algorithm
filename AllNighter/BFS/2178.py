# 2. [BOJ 2178] 미로탐색
# 응용1 - 거리 측정

# 왜 이 풀이는 안되지..?

import sys

dx = [-1,1,0,0]
dy = [0,0,-1,1]

n, m = map(int, input().split())
maze = [[int(i) for i in list(input())] for _ in range(n)] #[list(map(int, input().split())) for _ in range(n)]
check = [[0] * m for _ in range(n)]

# print("n: ", n)
# print("m: ", m)
# print(maze)
# print(check)

queue = [(0,0)]
check[0][0] = 1

while queue:
    x, y = queue.pop()
    print(x, y)
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        # print(nx, ny)
        if 0 <= nx < n and 0 <= ny < m and check[nx][ny] == 0 and maze[nx][ny] == 1:
            # print("i: ",i)
            check[nx][ny] = check[x][y] + 1
            queue.append((nx, ny))
    print(check)    

print(check[-1][-1])