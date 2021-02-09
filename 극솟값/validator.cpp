#include "testlib.h"
#include <vector>

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 5000, "T");
    inf.readEoln();

    for (int t = 0; t < T; t++)
    {
        int N = inf.readInt(3, 2e6, "N");
        inf.readSpace();
        int M = inf.readInt(1, 100, "M");
        inf.readEoln();
        std::vector<int> v(M + 1);

        for (int i = 0; i <= M; i++)
        {
            v[i] = inf.readInt(-1e5, 1e5);
            if (i < M)
                inf.readSpace();
        }
        inf.readEoln();
    }
    inf.readEof();
}