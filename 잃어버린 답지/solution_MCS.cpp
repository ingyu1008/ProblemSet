#include <iostream>
#include <vector>
#include <map>
#include <set>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;

    while (Q--)
    {
        int N, M;
        std::cin >> N >> M;
        std::map<int, int> mp;
        int mx = 0;

        for (int i = 0, a, b; i < N; i++)
        {
            std::cin >> a >> b;
            mp[b] = a;
            mx = std::max(mx, std::abs(b));
        }
        for (int i = N, a, b; i < N + M; i++)
        {
            std::cin >> a >> b;
            mp[b] = -a;
            mx = std::max(mx, std::abs(b));
        }

        std::set<int> ans;

        int offset = 0;
        while (mp[offset] == 0)
        {
            offset++;
            ans.insert(0);
        }

        for (int i = 1; i <= std::abs(mp[offset]) / std::abs(mp[mx]); i++)
        {
            ll x = 0;
            for(auto p : mp){
                ll y = 1;
                for(int j = 0; j < p.first; j++){
                    y *= i;
                }
                x += p.second*y;
            }
            if(x == 0)ans.insert(i);

            x = 0;
            for(auto p : mp){
                ll y = 1;
                for(int j = 0; j < p.first; j++){
                    y *= -i;
                }
                x += p.second*y;
            }
            if(x == 0)ans.insert(-i);
        }
        std::cout << ans.size() << "\n";
        for(auto x : ans){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    return 0;
}