#include <bits/stdc++.h>
using namespace std;
using ll_t = signed long long int;
using sz_t = size_t;

ll_t winner(ll_t a, ll_t b, vector<array<ll_t, 5>> &mat)
{
	ll_t ac = 0, bc = 0;
	for (ll_t i = 0; i < 5; i++)
	{
		ac += mat[(sz_t)a][(sz_t)i] < mat[(sz_t)b][(sz_t)i];
		bc += mat[(sz_t)b][(sz_t)i] < mat[(sz_t)a][(sz_t)i];
	}
	return (ac > bc ? a : b);
}

void task()
{
	ll_t n;
	cin >> n;

	vector<array<ll_t, 5>> mat((sz_t)n);
	for (auto &_mat : mat)
	{
		for (auto &_r : _mat)
		{
			cin >> _r;
		}
	}

	ll_t win = 0;
	for (ll_t i = 1; i < n; i++)
	{
		win = winner(win, i, mat);
	}
	for (ll_t i = 0; i < n; i++)
	{
		if (win != winner(win, i, mat))
		{
			cout << "-1" << endl;
			return;
		}
	}
	cout << (win + 1) << endl;
}

int main()
{
	ll_t t = 1;
	cin >> t;
	while (t--)
	{
		task();
	}

	return 0;
}
