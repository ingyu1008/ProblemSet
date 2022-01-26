#include <iostream>
#include <map>
#include <vector>

std::vector<int> v(15);

int result()
{
    return (v[0] * v[1] + v[2] * v[3] + v[4] * v[5] + v[6]) * v[7] + (v[8] * v[9] + v[10] * v[11] + v[12] * v[13] + v[14]);
}

int swap(int i, int j)
{
    // i < j
    if (v[i] <= 1 || v[j] <= 1)
        return -1;

    //숫자끼리 바꾸기
    if (v[i] < 10 && v[j] < 10)
    {
        std::swap(v[i], v[j]);
        int res = result();
        std::swap(v[i], v[j]);
        return res;
    }

    if (v[i] >= 10)
    {
        //단위끼리 바꾸기
        if (v[j] >= 10)
        {
            if (i / 8 == j / 8 && j != 7)
                return -1;
            if (j == 7)
            {
                switch (i)
                {
                case 1:
                    if (v[4] == 0 && v[6] == 0 && v[10] == 0)
                    {
                        std::swap(v[2], v[10]);
                        int res = result();
                        std::swap(v[2], v[10]);
                        return res;
                    }
                    else
                        return -1;
                case 3:
                    if (v[6] == 0 && v[10] == 0 && v[12] == 0)
                    {

                        std::swap(v[4], v[12]);
                        int res = result();
                        std::swap(v[4], v[12]);
                        return res;
                    }
                    else
                        return -1;
                case 5:
                    if (v[10] == 0 && v[12] == 0 && v[14] == 0)
                    {
                        std::swap(v[6], v[14]);
                        int res = result();
                        std::swap(v[6], v[14]);
                        return res;
                    }
                    else
                        return -1;
                default:
                    return -1;
                }
            }
            else if (i == 5)
            {
                switch (j)
                {
                case 9:
                    if (v[2] == 0 && v[4] == 0 && v[12] == 0 && v[14] == 0)
                    {
                        std::swap(v[5], v[9]);
                        int res = result();
                        std::swap(v[5], v[9]);
                    }
                    else
                        return -1;
                case 11:
                    if (v[4] == 0 && v[14] == 0)
                    {
                        std::swap(v[5], v[11]);
                        int res = result();
                        std::swap(v[5], v[11]);
                    }
                    else
                        return -1;
                default:
                    return -1;
                }
            }
            else if (i == 3)
            {
                if (j == 9)
                {
                    if (v[2] == 0 && v[12] == 0)
                    {
                        std::swap(v[2], v[12]);
                        int res = result();
                        std::swap(v[2], v[12]);
                        return res;
                    }
                    else
                        return -1;
                }
                else
                    return -1;
            }

            return -1;
        }
        else
        {
            //짜주세요
        }
    }
    return -1;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    while (T--)
    {

        int input;
        std::cin >> input;

        v[0] = (input / 10000000) % 10;
        v[1] = 1000;
        v[2] = (input / 1000000) % 10;
        v[3] = 100;
        v[4] = (input / 100000) % 10;
        v[5] = 10;
        v[6] = (input / 10000) % 10;
        v[7] = 10000;
        v[8] = (input / 1000) % 10;
        v[9] = 1000;
        v[10] = (input / 100) % 10;
        v[11] = 100;
        v[12] = (input / 10) % 10;
        v[13] = 10;
        v[14] = (input / 1) % 10;

        int mx = input;

        for (int i = 0; i < 15; i++)
        {
            for (int j = i + 1; j < 15; j++)
            {
                mx = std::max(mx, swap(i, j));
                mx = std::max(mx, swap(i, j));
            }
        }

        std::cout << mx << "\n";
    }

    return 0;
}