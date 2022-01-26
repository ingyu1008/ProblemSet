#include "testlib.h"
#include <iostream>

typedef long long ll;

bool valid(int N, int x)
{
    std::set<int> st;
    for (int i = 0; i < N; i++)
    {
        if (st.find(x % 10) == st.end())
        {
            st.insert(x % 10);
            x /= 10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int pow10(int x)
{
    if (x == 0)
        return 1;
    return 10 * pow10(x - 1);
}

int strike(int N, int x, int predict)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt += (x % 10) == (predict % 10);
        x /= 10;
        predict /= 10;
    }
    return cnt;
}

int ball(int N, int x, int predict, int str = -1)
{
    if (str == -1)
        str = strike(N, x, predict);
    std::set<int> st;
    for (int i = 0; i < N; i++)
    {
        st.insert(x % 10);
        x /= 10;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (st.find(predict % 10) != st.end())
        {
            cnt++;
        }
        predict /= 10;
    }

    return cnt - str;
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    std::cout << "5 10000\n";

    int x = 79214;

    std::vector<std::pair<int, std::pair<int, int>>> v;

    for (int i = 0; i < 100000; i++)
    {
        if (!valid(5, i))
            continue;
        int str = strike(5, x, i);
        v.push_back({i, {str, ball(5, x, i, str)}});
    }

    shuffle(v.begin(), v.end());

    for (int i = 0; i < 9999; i++)
    {
        std::cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << "\n";
    }
    std::cout << v[9999].first << " " << v[9999].second.first << " " << v[9999].second.second + 1 << "\n";
}