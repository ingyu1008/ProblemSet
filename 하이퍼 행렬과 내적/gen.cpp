#include "testlib.h"
#include <iostream>

typedef long long ll;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int m = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);
    int o = std::stoi(argv[3]);
    int p = std::stoi(argv[4]);
    int q = std::stoi(argv[5]);
    int r = std::stoi(argv[6]);
    int s = std::stoi(argv[7]);
    int t = std::stoi(argv[8]);
    int u = std::stoi(argv[9]);
    int v = std::stoi(argv[10]);
    int w = std::stoi(argv[11]);

    std::cout << m << " " << n << " " << o << " " << p << " " << q << " " << r << " " << s << " " << t << " " << u << " " << v << " " << w << "\n";

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
                                                std::cout << rnd.next(1, 1000000);
                                                if (iw != w - 1)
                                                    std::cout << " ";
                                            }
                                            std::cout << "\n";
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

    int query = std::stoi(argv[12]);
    std::cout << query << "\n";

    for (int i = 0; i < query; i++)
    {
        int x = rnd.next(1, 11);
        std::cout << x << " ";
        if (x == 1)
        {
            int a1 = rnd.next(1, n);
            int b1 = rnd.next(1, o);
            int c1 = rnd.next(1, p);
            int d1 = rnd.next(1, q);
            int e1 = rnd.next(1, r);
            int f1 = rnd.next(1, s);
            int g1 = rnd.next(1, t);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, n);
            int b2 = rnd.next(1, o);
            int c2 = rnd.next(1, p);
            int d2 = rnd.next(1, q);
            int e2 = rnd.next(1, r);
            int f2 = rnd.next(1, s);
            int g2 = rnd.next(1, t);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 2)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, o);
            int c1 = rnd.next(1, p);
            int d1 = rnd.next(1, q);
            int e1 = rnd.next(1, r);
            int f1 = rnd.next(1, s);
            int g1 = rnd.next(1, t);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, o);
            int c2 = rnd.next(1, p);
            int d2 = rnd.next(1, q);
            int e2 = rnd.next(1, r);
            int f2 = rnd.next(1, s);
            int g2 = rnd.next(1, t);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 3)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, p);
            int d1 = rnd.next(1, q);
            int e1 = rnd.next(1, r);
            int f1 = rnd.next(1, s);
            int g1 = rnd.next(1, t);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, p);
            int d2 = rnd.next(1, q);
            int e2 = rnd.next(1, r);
            int f2 = rnd.next(1, s);
            int g2 = rnd.next(1, t);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 4)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, q);
            int e1 = rnd.next(1, r);
            int f1 = rnd.next(1, s);
            int g1 = rnd.next(1, t);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, q);
            int e2 = rnd.next(1, r);
            int f2 = rnd.next(1, s);
            int g2 = rnd.next(1, t);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 5)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, p);
            int e1 = rnd.next(1, r);
            int f1 = rnd.next(1, s);
            int g1 = rnd.next(1, t);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, p);
            int e2 = rnd.next(1, r);
            int f2 = rnd.next(1, s);
            int g2 = rnd.next(1, t);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 6)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, p);
            int e1 = rnd.next(1, q);
            int f1 = rnd.next(1, s);
            int g1 = rnd.next(1, t);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, p);
            int e2 = rnd.next(1, q);
            int f2 = rnd.next(1, s);
            int g2 = rnd.next(1, t);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 7)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, p);
            int e1 = rnd.next(1, q);
            int f1 = rnd.next(1, r);
            int g1 = rnd.next(1, t);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, p);
            int e2 = rnd.next(1, q);
            int f2 = rnd.next(1, r);
            int g2 = rnd.next(1, t);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 8)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, p);
            int e1 = rnd.next(1, q);
            int f1 = rnd.next(1, r);
            int g1 = rnd.next(1, s);
            int h1 = rnd.next(1, u);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, p);
            int e2 = rnd.next(1, q);
            int f2 = rnd.next(1, r);
            int g2 = rnd.next(1, s);
            int h2 = rnd.next(1, u);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 9)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, p);
            int e1 = rnd.next(1, q);
            int f1 = rnd.next(1, r);
            int g1 = rnd.next(1, s);
            int h1 = rnd.next(1, t);
            int i1 = rnd.next(1, v);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, p);
            int e2 = rnd.next(1, q);
            int f2 = rnd.next(1, r);
            int g2 = rnd.next(1, s);
            int h2 = rnd.next(1, t);
            int i2 = rnd.next(1, v);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 10)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, p);
            int e1 = rnd.next(1, q);
            int f1 = rnd.next(1, r);
            int g1 = rnd.next(1, s);
            int h1 = rnd.next(1, t);
            int i1 = rnd.next(1, u);
            int j1 = rnd.next(1, w);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, p);
            int e2 = rnd.next(1, q);
            int f2 = rnd.next(1, r);
            int g2 = rnd.next(1, s);
            int h2 = rnd.next(1, t);
            int i2 = rnd.next(1, u);
            int j2 = rnd.next(1, w);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
        else if (x == 11)
        {
            int a1 = rnd.next(1, m);
            int b1 = rnd.next(1, n);
            int c1 = rnd.next(1, o);
            int d1 = rnd.next(1, p);
            int e1 = rnd.next(1, q);
            int f1 = rnd.next(1, r);
            int g1 = rnd.next(1, s);
            int h1 = rnd.next(1, t);
            int i1 = rnd.next(1, u);
            int j1 = rnd.next(1, v);

            int a2 = rnd.next(1, m);
            int b2 = rnd.next(1, n);
            int c2 = rnd.next(1, o);
            int d2 = rnd.next(1, p);
            int e2 = rnd.next(1, q);
            int f2 = rnd.next(1, r);
            int g2 = rnd.next(1, s);
            int h2 = rnd.next(1, t);
            int i2 = rnd.next(1, u);
            int j2 = rnd.next(1, v);

            std::cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << " " << f1 << " " << g1 << " " << h1 << " " << i1 << " " << j1 << " " << a2 << " " << b2 << " " << c2 << " " << d2 << " " << e2 << " " << f2 << " " << g2 << " " << h2 << " " << i2 << " " << j2 << "\n";
        }
    }
}