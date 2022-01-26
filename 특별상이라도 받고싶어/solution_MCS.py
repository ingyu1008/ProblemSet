N = int(input())
v = [list(map(int, input().split())) for _ in range(N)]

def recursive(x, y, n):
    if n == 1:
        return v[x][y]
    else:
        n //= 2
        z = [recursive(x,y,n), recursive(x,y+n,n), recursive(x+n,y,n), recursive(x+n,y+n,n)]
        z.sort()
        return z[1]

print(recursive(0,0,N))