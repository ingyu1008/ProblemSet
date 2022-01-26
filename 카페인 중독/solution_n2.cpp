#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using pii = pair<int, int>;
const int N_MAX = 1002;
int N;
pii drink[N_MAX], DP[N_MAX][N_MAX], ans;

bool cmp(pii a, pii b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) cin >> drink[i].first;
    for (int i = 0; i < N; ++i) cin >> drink[i].second;
    sort(drink, drink + N, cmp);

    if (N == 1) {
        std::cout << drink[0].first;
    } else {

        for (int i = N; i >= 0; --i) {
            DP[i][0] = { 0,0 };
            for (int k = 1, cntIn, cntEx, valIn, valEx; k <= N - i; ++k) {
                valIn = max(DP[i + 1][k - 1].second - DP[i + 1][k - 1].first * drink[i].second + drink[i].first, 0);
                valEx = DP[i + 1][k].second;
                cntIn = DP[i + 1][k - 1].first + 1;
                cntEx = DP[i + 1][k].first;

                if (cmp({ cntEx, valEx }, { cntIn, valIn })) DP[i][k] = { cntIn, valIn };
                else DP[i][k] = { cntEx, valEx };
            }
        }

        ans = { 0,0 };
        for (int i = 0; i < N; ++i) {
            if (cmp(ans, DP[0][i])) ans = DP[0][i];
        }

        cout << ans.second << '\n';
    }

    return 0;
}
