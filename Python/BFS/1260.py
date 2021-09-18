# 1. [BOJ 1260] DFS와 BFS
# 참고: https://velog.io/@uoayop/BOJ-1260-DFS%EC%99%80-BFSPython

from collections import deque
import sys

input = sys.stdin.readline

N,M,V = map(int, input().rstrip().rsplit()) #  정점, 간선, 탐색 시작 vertex
nodes = []
graph = {}

def DFS(graph, start_node):
    visit = []
    stack = []

    stack.append(start_node)
    while stack:
        node = stack.pop()
        if node not in visit:
            visit.append(node)
            if node in graph: # node와 연결된 다른 정점들 중 방문 안한 정점들만 temp 리스트에 넣음
                temp = list(set(graph[node])-set(visit))
                # temp를 내림차순으로 정렬
                # stack에서 pop 할 때 가장 앞에 있는 요소를 빼니까
                temp.sort(reverse=True)
                stack += temp
    return " ".join(str(i) for i in visit)



def BFS(graph, start_node):
    visit = []
    queue = deque()

    queue.append(start_node)
    while queue:
        node = queue.popleft()
        if node not in visit:
            visit.append(node)
            if node in graph:
                temp = list(set(graph[node])-set(visit))
                temp.sort()
                queue += temp
    return " ".join(str(i) for i in visit)

for i in range(M):
    x,y = map(int, input().rstrip().rsplit())
    nodes.append([x,y])

    if x not in graph:
        graph[x] = [y]
    else:
        graph[x].append(y)

    if y not in graph:
        graph[y] = [x]
    else:
        graph[y].append(x)

print(DFS(graph,V))
print(BFS(graph,V))