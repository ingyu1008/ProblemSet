if __name__ == "__main__":
    a = [0 for i in range(20000)]  # 마지막에 한양 이용
    b = [0 for i in range(20000)]  # 애국 연속 1칸
    c = [0 for i in range(20000)]  # 애국 연속 2칸
    d = [0 for i in range(20000)]  # 애국에서 3칸 오름
    N = int(input())
    mod = 1000000007

    a[0] = 1
    b[0] = 1

    for i in range(1, N+1):
        a[i] = (a[i] + a[i-2] + a[i-3] + b[i-1] + c[i-1] + d[i-1]) % mod
        b[i] = (b[i] + a[i-1] + b[i-2] + c[i-2]) % mod
        c[i] = (c[i] + b[i-1] + d[i-1]) % mod
        d[i] = (d[i] + b[i-3] + c[i-3]) % mod

    print((a[N] + b[N] + c[N] + d[N]) % mod)

def dfs(n, k, cnt):
    if n < 0 or (k == 0 and cnt == 3): return 0
    if n == 0: return 1
    if k == 0: return (dfs(n - 1, 0, cnt + 1) + dfs(n - 2, 0, 1) + dfs(n - 3, 0, 1) + dfs(n - 1, 1, 1)) % MOD
    else: return (dfs(n - 2, 1, 1) + dfs(n - 3, 1, 1) + dfs(n - 1, 0, 1)) % MOD
    