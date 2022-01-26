#include <iostream>
#include <vector>
#include <tuple>
#include <random>
#include <algorithm>

typedef long long ll;

ll dp[6][1010101];

ll mod = 1e9+7;

ll dfs(int lastvisit, int days_left) {
    if (days_left == 0) return dp[lastvisit][days_left] = 1;

    if (lastvisit == 0) return dp[lastvisit][days_left] = (dfs(1, days_left - 1) + dfs(2, days_left - 1) + dfs(3, days_left - 1) + dfs(4, days_left - 1))%mod;
    else if (lastvisit == 1) return dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(3, days_left - 1) + dfs(4, days_left - 1))%mod;
    else if (lastvisit == 2) return dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(4, days_left - 1))%mod;
    else if (lastvisit == 3) return dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(1, days_left - 1))%mod;
    else if (lastvisit == 4) return dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(1, days_left - 1) + dfs(2, days_left - 1))%mod;
    else return dp[lastvisit][days_left] = (dfs(0, days_left - 1) + dfs(1, days_left - 1) + dfs(2, days_left - 1) + dfs(3, days_left - 1) + dfs(4, days_left - 1))%mod;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 1010101; j++){
            dp[i][j] = -1;
        }
    }

    std::cout << dfs(5, N) << "\n";

    return 0;
}