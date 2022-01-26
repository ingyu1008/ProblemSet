#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v[101010];
int depth[101010];

int dfs(int node = 1, int par = 0)
{
    int mx = 0;

    for (auto x : v[node])
    {
        if (x == par)
            continue;
        mx = std::max(mx, dfs(x, node));
    }

    return depth[node] = mx + 1;
}

bool dfs2(int node = 1, int par = 0)
{
    bool flag = true;
    int mx = 0;
    int mn = 101010;
    int cnt = 0;

    for (auto x : v[node])
    {
        if (x == par)
            continue;
        cnt++;
        mx = std::max(mx, depth[x]);
        mn = std::min(mn, depth[x]);
        flag &= dfs2(x, node);
    }

    return flag & ((cnt == 1 && mx <= 1) || cnt == 0 || (cnt == 2 && (mx - mn) <= 1));
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 1, x, y; i < N; i++)
    {
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs();

    std::cout << ((dfs2()) ? "YES\n" : "NO\n");

    return 0;
}