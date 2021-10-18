# 바킹독 문제 다시 풀기
# 응용1 - 거리 측정
# 응용2 - 시작점이 여러 개일 때
# 응용3 - 시작점이 두 종류일 떄
# 응용4 - 1차원에서의 BFS

# 1. [BOJ 1926] 그림
import sys
input = sys.stdin.readline

n,m = map(int, input().split())
paint = [list(map(int, input().split())) for _ in range(n)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y):
    width = 1
    queue = [(x, y)]
    while queue:
        x,y = queue.pop()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if paint[nx][ny] == 1 and not check[nx][ny]:
                    check[nx][ny] = 1
                    width += 1
                    queue.append((nx, ny))
    return width

count, max_width = 0, 0
check = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if paint[i][j] == 1 and not check[i][j]:
            count += 1
            check[i][j] = 1
            max_width = max(max_width, bfs(i,j))

print(count)
print(max_width)
