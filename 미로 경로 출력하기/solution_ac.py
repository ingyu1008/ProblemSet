import sys
sys.setrecursionlimit(4040404)

def init():
    global N, M, maze, visited, dx, dy
    N, M = map(int, input().split())
    maze = [list(input().replace('.','@')) for _ in range(N)]
    visited = [[False] * M for _ in range(N)]
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]


def dfs(si, sj):
    if si == ei and sj == ej:
        maze[si][sj] = '.'
        return True

    res = False

    for i in range(4):
        nx = si + dx[i]
        ny = sj + dy[i]

        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if maze[nx][ny] == '+':
            continue
        if visited[nx][ny]:
            continue

        visited[nx][ny] = True
        res = dfs(nx, ny)
        if res:
            maze[si][sj] = '.'
            return True

    return False


def solve():
    global ei,ej
    si, sj, ei, ej = -1, -1, -1, -1
    for i in range(M):
        if maze[0][i] == '@':
            if si == -1:
                si, sj = 0, i
            else:
                ei, ej = 0, i
        if maze[N - 1][i] == '@':
            if si == -1:
                si, sj = N - 1, i
            else:
                ei, ej = N - 1, i
    for i in range(N):
        if maze[i][0] == '@':
            if si == -1:
                si, sj = i, 0
            else:
                ei, ej = i, 0
        if maze[i][M - 1] == '@':
            if si == -1:
                si, sj = i, M - 1
            else:
                ei, ej = i, M - 1
    
    dfs(si, sj)

def _print():
    t = []
    for i in range(N):
        t.append(''.join(maze[i]))
    print('\n'.join(t))

if __name__ == '__main__':
    init()
    solve()
    _print()
