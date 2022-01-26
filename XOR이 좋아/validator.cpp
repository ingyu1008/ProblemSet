#include "testlib.h"
#include <vector>

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);

    int N;
    N = inf.readInt(1, 200000, "N");
    inf.readEoln();

    for (int i = 0; i < N; i++)
    {
        inf.readInt(1, 1000, "v_i");
        if (i != N - 1)
            inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();

    return 0;
}