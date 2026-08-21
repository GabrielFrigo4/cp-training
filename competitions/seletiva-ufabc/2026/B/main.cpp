#include <bits/stdc++.h>
using namespace std;
using ll_t = signed long long int;
using sz_t = size_t;

void task()
{
	ll_t pessoas = 0;
	ll_t trafego = 0;
	string line;
	while (getline(cin, line))
	{
		ll_t mod = 0;
		mod += line.starts_with('+');
		mod -= line.starts_with('-');
		pessoas += mod;
		if (mod == 0)
		{
			ll_t offset = (ll_t)line.find(':') + 1;
			ll_t len = (ll_t)line.size() - offset;
			trafego += len * pessoas;
		}
	}
	cout << trafego << endl;
}

int main()
{
	ll_t t = 1;
	// cin >> t;
	while (t--)
	{
		task();
	}

	return 0;
}
