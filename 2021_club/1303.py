# 3. [BOJ 1303] 전쟁 - 전투

from collections import deque
 
def BFS():
    q.append((i, j))
    check[i][j] = 1
    temp = 1
    while q:
        x, y = q.popleft()
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < M and 0 <= ny < N and board[nx][ny] == board[x][y] and check[nx][ny] == 0:
                check[nx][ny] = 1
                q.append((nx, ny))
                temp += 1
    return temp
 
# N: 가로 M : 세로
N, M = map(int, input().split())
board = [list(input()) for _ in range(M)]
check = [[0] * N for _ in range(M)]
 
dx,dy=[1,-1,0,0],[0,0,1,-1]
q = deque()
B, W = 0, 0
 
for i in range(M):
    for j in range(N):
        if check[i][j] == 0:
            ans = BFS()
            if board[i][j] == 'W': W += ans ** 2
            else: B += ans ** 2
 
print(W, B)