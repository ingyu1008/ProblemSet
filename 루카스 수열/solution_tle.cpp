#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second

const ll mod = 1e9 + 7;

struct matrix
{
	int n, m;
	vector<vector<ll>> a;

	matrix(int r = 1, int c = 1)
	{
		n = r;
		m = c;
		a.resize(n);
		for (auto &x : a)
			x.resize(m);
	}

	vector<ll> &operator[](int x)
	{
		return this->a[x];
	}
};

matrix operator*(matrix A, matrix B)
{
	assert(A.m == B.n);
	int n = A.n,
		m = B.m,
		l = A.m;
	matrix res(n, m);
	for (int k = 0; k < l; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = ((res[i][j] + A[i][k] * B[k][j]) % mod + mod) % mod;
	return res;
}

matrix operator^(matrix A, ll p)
{
	assert(A.n == A.m && p >= 0);
	int n = A.n;
	matrix res(n, n);
	for (int i = 0; i < n; i++)
		res[i][i] = 1;

	while (p)
	{
		if (p & 1)
			res = res * A;
		A = A * A;
		p >>= 1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Q = 1;
	cin >> Q;
	while (Q--)
	{
		ll p = 1, q = -1, x = 3;
		cin >> p >> q >> x;
		if (x < 2)
		{
			cout << x << "\n";
			continue;
		}
		matrix A(2, 2), X(2, 1);
		A[0][0] = p;
		A[0][1] = -q;
		A[1][0] = 1;
		A[1][1] = 0;
		X[0][0] = 1;
		X[1][0] = 0;
		while(x--){
			X = A*X;
		}
		cout << X[1][0] << '\n';
	}

	return 0;
}
