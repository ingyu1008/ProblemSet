import sys
sys.setrecursionlimit(10101010)

dp = [[-1 for _ in range(1010101)] for __ in range(6)]
mod = 10**9 + 7


def dfs(lastvisit, days_left):
    if dp[lastvisit][days_left] != -1:
        return dp[lastvisit][days_left]

    if days_left == 0:
        dp[lastvisit][days_left] = 1
        return 1
    
    if lastvisit == 0:
        dp[lastvisit][days_left] = (dfs(1, days_left - 1) + dfs(
            2, days_left - 1) + dfs(3, days_left - 1) + dfs(4, days_left - 1)) % mod
        return dp[lastvisit][days_left]
    elif lastvisit == 1:
        dp[lastvisit][days_left] = (
            dfs(0, days_left - 1) + dfs(3, days_left - 1) + dfs(4, days_left - 1)) % mod
        return dp[lastvisit][days_left]
    elif lastvisit == 2:
        dp[lastvisit][days_left] = (
            dfs(0, days_left - 1) + dfs(4, days_left - 1)) % mod
        return dp[lastvisit][days_left]
    elif lastvisit == 3:
        dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(1, days_left - 1))%mod
        return dp[lastvisit][days_left]
    elif lastvisit == 4:
        dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(1, days_left - 1) + dfs(2, days_left - 1))%mod
        return dp[lastvisit][days_left]
    else:
        dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(1, days_left - 1) + dfs(2, days_left - 1) + dfs(3, days_left - 1) + dfs(4, days_left - 1))%mod
        return dp[lastvisit][days_left]
    
if __name__ == '__main__':
    N = int(input())
    print(dfs(5,N))