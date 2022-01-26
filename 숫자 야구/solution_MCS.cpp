#include <iostream>
#include <iomanip>
#include <set>

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

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::set<int> st;

    int mx = pow10(N);

    for (int i = 0; i < mx; i++)
    {
        if (valid(N, i))
            st.insert(i);
    }

    for (int i = 0, x, y, z; i < M; i++)
    {
        std::cin >> x >> y >> z;
        auto it = st.begin();
        while (it != st.end())
        {
            int s = strike(N, x, *it);
            int b = ball(N, x, *it, s);

            if (s != y || b != z)
            {
                st.erase(it++);
            }
            else
            {
                it++;
            }
        }
    }

    if (st.size() == 1)
    {
        std::cout << std::setfill('0') << std::setw(N);
        std::cout << *st.begin() << "\n";
    }
    else if (st.size() > 1)
    {
        std::cout << st.size() << "\n";
    }
    else
    {
        std::cout << "dksu is wrong\n";
    }

    return 0;
}