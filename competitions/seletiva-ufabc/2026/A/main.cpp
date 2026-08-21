#include <bits/stdc++.h>
using namespace std;
using ll_t = signed long long int;
using sz_t = size_t;

void task()
{
	ll_t N;
	cin >> N;

	ll_t sum = 0, tmp = 0;
	while (N--)
	{
		cin >> tmp;
		sum += abs(tmp);
	}
	cout << sum << endl;
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
