#include "testlib.h"
#include <vector>

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);

    int N, Q;
    N = inf.readInt(1, 100000, "N");
    inf.readSpace();
    Q = inf.readInt(1, 100000, "Q");
    inf.readEoln();

    for (int i = 0; i < N; i++)
    {
        inf.readInt(1, 1000000000, "v_i");
        if (i != N - 1)
            inf.readSpace();
    }
    inf.readEoln();

    int q[2] = {0, 0};

    for (int i = 0, x; i < Q; i++)
    {
        x = inf.readInt();
        inf.readSpace();
        q[x - 1]++;
        if (x == 1)
        {
            inf.readInt();
            inf.readSpace();
            inf.readInt();
        }
        else
        {
            inf.readInt();
        }
        inf.readEoln();
    }

    ensuref(q[1] > 0, "Invalid Data: No Query #2 found.\n");

    inf.readEof();

    return 0;
}