#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <queue>

typedef long long ll;

std::vector<std::pair<ll, ll>> v;
std::set<std::pair<ll, ll>> s;

ll dist(std::pair<ll, ll> p1, std::pair<ll, ll> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        v.push_back(std::make_pair(x, y));
    }

    std::sort(v.begin(), v.end());

    std::cin >> Q;

    for (int q = 0; q < Q; q++) {
        s.clear();

        ll l, r;
        std::cin >> l >> r;

        int a = -1, b = -1, c = -1;

        for (int i = 0; i < N; i++) {
            if (v[i].first < l || v[i].first > r) continue;

            if (a < 0) a = i;
            else if (b < 0) b = i;
            else { c = i; break; }
        }

        s.emplace(v[a].second, v[a].first);
        s.emplace(v[b].second, v[b].first);

        ll min = dist(v[a], v[b]);
        std::queue<int> left;
        left.push(a);
        left.push(b);

        if (c < 0) {
            std::cout << min << '\n';
            continue;
        }

        for (int i = c; i < N; i++) {
            if (v[i].first < l || v[i].first > r) continue;
            left.push(i);
            while (!left.empty() && left.front() < i) {
                ll d = v[i].first - v[left.front()].first;
                if (d * d <= min) break;
                else {
                    s.erase({ v[left.front()].second, v[left.front()].first });
                    left.pop();
                }
            }

            auto start = s.lower_bound({ v[i].second - std::sqrt(min), -1e18 });
            auto end = s.upper_bound({ v[i].second + std::sqrt(min), 1e18 });
            for (auto it = start; it != end; it++) {
                ll d = dist({ v[i].second, v[i].first }, *it);
                if (d < min) min = d;
            }
            s.emplace(v[i].second, v[i].first);
        }

        if (b != -1) std::cout << min << '\n';
        else std::cout << (ll)8e18 << "\n";
    }

    return 0;
}