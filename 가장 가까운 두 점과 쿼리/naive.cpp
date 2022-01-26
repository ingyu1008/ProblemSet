#include <iostream>
#include <vector>

typedef long long ll;

std::vector<std::pair<std::pair<ll, ll>, int>> points;
bool valid[101010];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        ll x, y;
        std::cin >> x >> y;
        points.push_back(std::make_pair(std::make_pair(x, y), i + 1));
    }

    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        ll x, y;
        std::cin >> x >> y;
        ll min_dist = 8e18;
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (!valid[points[j].second]) break;
                if (!valid[points[k].second]) continue;

                ll dist = (points[j].first.first - points[k].first.first) * (points[j].first.first - points[k].first.first) + (points[j].first.second - points[k].first.second) * (points[j].first.second - points[k].first.second);
                if (dist < min_dist) min_dist = dist;
            }
        }
        std::cout << min_dist << '\n';
    }

    return 0;
}