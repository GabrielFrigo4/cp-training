#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll_t = signed long long int;
using sz_t = size_t;

ll_t flor(ll_t i, vector<ll_t> &h)
{
	if ((sz_t)i >= h.size())
	{
		return 0;
	}
	return max(h[(sz_t)i], flor(i + 1, h) + 1);
}

void task()
{
	ll_t n;
	cin >> n;

	vector<ll_t> h((sz_t)n);
	for (auto &_h : h)
	{
		cin >> _h;
	}

	cout << flor(0, h) << endl;
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
