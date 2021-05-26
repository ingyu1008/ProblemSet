#include "testlib.h"
#include <iostream>

typedef long long ll;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);

    int m = inf.readInt(1, 10000, "m");
    inf.readSpace();
    int n = inf.readInt(1, 10000, "n");
    inf.readSpace();
    int o = inf.readInt(1, 10000, "o");
    inf.readSpace();
    int p = inf.readInt(1, 10000, "p");
    inf.readSpace();
    int q = inf.readInt(1, 10000, "q");
    inf.readSpace();
    int r = inf.readInt(1, 10000, "r");
    inf.readSpace();
    int s = inf.readInt(1, 10000, "s");
    inf.readSpace();
    int t = inf.readInt(1, 10000, "t");
    inf.readSpace();
    int u = inf.readInt(1, 10000, "u");
    inf.readSpace();
    int v = inf.readInt(1, 10000, "v");
    inf.readSpace();
    int w = inf.readInt(1, 10000, "w");
    inf.readEoln();

    ensuref(m <= 10000 && m * n <= 10000 && m * n * o <= 10000 && m * n * o * p <= 10000 && m * n * o * p * q <= 10000 && m * n * o * p * q * r <= 10000 && m * n * o * p * q * r * s <= 10000 && m * n * o * p * q * r * s * t <= 10000 && m * n * o * p * q * r * s * t * u <= 10000 && m * n * o * p * q * r * s * t * u * v <= 10000 && m * n * o * p * q * r * s * t * u * v * w <= 10000, "mnopqrstuvw > 10000");

    for (int im = 0; im < m; im++)
    {
        for (int in = 0; in < n; in++)
        {
            for (int io = 0; io < o; io++)
            {
                for (int ip = 0; ip < p; ip++)
                {
                    for (int iq = 0; iq < q; iq++)
                    {
                        for (int ir = 0; ir < r; ir++)
                        {
                            for (int is = 0; is < s; is++)
                            {
                                for (int it = 0; it < t; it++)
                                {
                                    for (int iu = 0; iu < u; iu++)
                                    {
                                        for (int iv = 0; iv < v; iv++)
                                        {
                                            for (int iw = 0; iw < w; iw++)
                                            {
                                                inf.readInt(1, 1000000, "Ai");
                                                if (iw != w - 1)
                                                    inf.readSpace();
                                            }
                                            inf.readEoln();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int query = inf.readInt(1, 10000, "query");
    inf.readEoln();

    for (int i = 0; i < query; i++)
    {
        int x = inf.readInt(1, 11, "x");
        inf.readSpace();
        if (x == 1)
        {
            int a1 = inf.readInt(1, n);
            inf.readSpace();
            int b1 = inf.readInt(1, o);
            inf.readSpace();
            int c1 = inf.readInt(1, p);
            inf.readSpace();
            int d1 = inf.readInt(1, q);
            inf.readSpace();
            int e1 = inf.readInt(1, r);
            inf.readSpace();
            int f1 = inf.readInt(1, s);
            inf.readSpace();
            int g1 = inf.readInt(1, t);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, n);
            inf.readSpace();
            int b2 = inf.readInt(1, o);
            inf.readSpace();
            int c2 = inf.readInt(1, p);
            inf.readSpace();
            int d2 = inf.readInt(1, q);
            inf.readSpace();
            int e2 = inf.readInt(1, r);
            inf.readSpace();
            int f2 = inf.readInt(1, s);
            inf.readSpace();
            int g2 = inf.readInt(1, t);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 2)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, o);
            inf.readSpace();
            int c1 = inf.readInt(1, p);
            inf.readSpace();
            int d1 = inf.readInt(1, q);
            inf.readSpace();
            int e1 = inf.readInt(1, r);
            inf.readSpace();
            int f1 = inf.readInt(1, s);
            inf.readSpace();
            int g1 = inf.readInt(1, t);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, o);
            inf.readSpace();
            int c2 = inf.readInt(1, p);
            inf.readSpace();
            int d2 = inf.readInt(1, q);
            inf.readSpace();
            int e2 = inf.readInt(1, r);
            inf.readSpace();
            int f2 = inf.readInt(1, s);
            inf.readSpace();
            int g2 = inf.readInt(1, t);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 3)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, p);
            inf.readSpace();
            int d1 = inf.readInt(1, q);
            inf.readSpace();
            int e1 = inf.readInt(1, r);
            inf.readSpace();
            int f1 = inf.readInt(1, s);
            inf.readSpace();
            int g1 = inf.readInt(1, t);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, p);
            inf.readSpace();
            int d2 = inf.readInt(1, q);
            inf.readSpace();
            int e2 = inf.readInt(1, r);
            inf.readSpace();
            int f2 = inf.readInt(1, s);
            inf.readSpace();
            int g2 = inf.readInt(1, t);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 4)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, q);
            inf.readSpace();
            int e1 = inf.readInt(1, r);
            inf.readSpace();
            int f1 = inf.readInt(1, s);
            inf.readSpace();
            int g1 = inf.readInt(1, t);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, q);
            inf.readSpace();
            int e2 = inf.readInt(1, r);
            inf.readSpace();
            int f2 = inf.readInt(1, s);
            inf.readSpace();
            int g2 = inf.readInt(1, t);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 5)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, p);
            inf.readSpace();
            int e1 = inf.readInt(1, r);
            inf.readSpace();
            int f1 = inf.readInt(1, s);
            inf.readSpace();
            int g1 = inf.readInt(1, t);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, p);
            inf.readSpace();
            int e2 = inf.readInt(1, r);
            inf.readSpace();
            int f2 = inf.readInt(1, s);
            inf.readSpace();
            int g2 = inf.readInt(1, t);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 6)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, p);
            inf.readSpace();
            int e1 = inf.readInt(1, q);
            inf.readSpace();
            int f1 = inf.readInt(1, s);
            inf.readSpace();
            int g1 = inf.readInt(1, t);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, p);
            inf.readSpace();
            int e2 = inf.readInt(1, q);
            inf.readSpace();
            int f2 = inf.readInt(1, s);
            inf.readSpace();
            int g2 = inf.readInt(1, t);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 7)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, p);
            inf.readSpace();
            int e1 = inf.readInt(1, q);
            inf.readSpace();
            int f1 = inf.readInt(1, r);
            inf.readSpace();
            int g1 = inf.readInt(1, t);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, p);
            inf.readSpace();
            int e2 = inf.readInt(1, q);
            inf.readSpace();
            int f2 = inf.readInt(1, r);
            inf.readSpace();
            int g2 = inf.readInt(1, t);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 8)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, p);
            inf.readSpace();
            int e1 = inf.readInt(1, q);
            inf.readSpace();
            int f1 = inf.readInt(1, r);
            inf.readSpace();
            int g1 = inf.readInt(1, s);
            inf.readSpace();
            int h1 = inf.readInt(1, u);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, p);
            inf.readSpace();
            int e2 = inf.readInt(1, q);
            inf.readSpace();
            int f2 = inf.readInt(1, r);
            inf.readSpace();
            int g2 = inf.readInt(1, s);
            inf.readSpace();
            int h2 = inf.readInt(1, u);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 9)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, p);
            inf.readSpace();
            int e1 = inf.readInt(1, q);
            inf.readSpace();
            int f1 = inf.readInt(1, r);
            inf.readSpace();
            int g1 = inf.readInt(1, s);
            inf.readSpace();
            int h1 = inf.readInt(1, t);
            inf.readSpace();
            int i1 = inf.readInt(1, v);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, p);
            inf.readSpace();
            int e2 = inf.readInt(1, q);
            inf.readSpace();
            int f2 = inf.readInt(1, r);
            inf.readSpace();
            int g2 = inf.readInt(1, s);
            inf.readSpace();
            int h2 = inf.readInt(1, t);
            inf.readSpace();
            int i2 = inf.readInt(1, v);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 10)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, p);
            inf.readSpace();
            int e1 = inf.readInt(1, q);
            inf.readSpace();
            int f1 = inf.readInt(1, r);
            inf.readSpace();
            int g1 = inf.readInt(1, s);
            inf.readSpace();
            int h1 = inf.readInt(1, t);
            inf.readSpace();
            int i1 = inf.readInt(1, u);
            inf.readSpace();
            int j1 = inf.readInt(1, w);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, p);
            inf.readSpace();
            int e2 = inf.readInt(1, q);
            inf.readSpace();
            int f2 = inf.readInt(1, r);
            inf.readSpace();
            int g2 = inf.readInt(1, s);
            inf.readSpace();
            int h2 = inf.readInt(1, t);
            inf.readSpace();
            int i2 = inf.readInt(1, u);
            inf.readSpace();
            int j2 = inf.readInt(1, w);
        }
        else if (x == 11)
        {
            int a1 = inf.readInt(1, m);
            inf.readSpace();
            int b1 = inf.readInt(1, n);
            inf.readSpace();
            int c1 = inf.readInt(1, o);
            inf.readSpace();
            int d1 = inf.readInt(1, p);
            inf.readSpace();
            int e1 = inf.readInt(1, q);
            inf.readSpace();
            int f1 = inf.readInt(1, r);
            inf.readSpace();
            int g1 = inf.readInt(1, s);
            inf.readSpace();
            int h1 = inf.readInt(1, t);
            inf.readSpace();
            int i1 = inf.readInt(1, u);
            inf.readSpace();
            int j1 = inf.readInt(1, v);
            inf.readSpace();

            int a2 = inf.readInt(1, m);
            inf.readSpace();
            int b2 = inf.readInt(1, n);
            inf.readSpace();
            int c2 = inf.readInt(1, o);
            inf.readSpace();
            int d2 = inf.readInt(1, p);
            inf.readSpace();
            int e2 = inf.readInt(1, q);
            inf.readSpace();
            int f2 = inf.readInt(1, r);
            inf.readSpace();
            int g2 = inf.readInt(1, s);
            inf.readSpace();
            int h2 = inf.readInt(1, t);
            inf.readSpace();
            int i2 = inf.readInt(1, u);
            inf.readSpace();
            int j2 = inf.readInt(1, v);
        }
        inf.readEoln();
    }
    inf.readEof();
}