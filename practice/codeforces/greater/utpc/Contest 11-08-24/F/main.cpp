#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>

bool assert(const int64_t n, const int64_t w, const int64_t b)
{
	if (w + b == 0)
	{
		if (n == 0)
		{
			std::cout << "1" << std::endl;
		}
		else
		{
			std::cout << "0" << std::endl;
		}
		return true;
	}
	if (std::min(w, b) == 0)
	{
		if (n % std::max(w, b) == 0)
		{
			std::cout << "1" << std::endl;
		}
		else
		{
			std::cout << "0" << std::endl;
		}
		return true;
	}
	return false;
}

int64_t gcd_ex(const int64_t a, const int64_t b, int64_t &x, int64_t &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int64_t x1, y1;
	int64_t d = gcd_ex(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void test_run(void)
{
	int64_t n, w, b;
	std::cin >> n >> w >> b;

	if (assert(n, w, b))
	{
		return;
	}

	const int64_t min_x = 0;
	const int64_t max_x = n / w;

	int64_t pos_x, pos_y;
	const int64_t mdc = gcd_ex(w, b, pos_x, pos_y);

	if (n % mdc != 0)
	{
		std::cout << "0" << std::endl;
		return;
	}

	const int64_t delta = b / mdc;
	pos_x *= n / mdc;
	pos_x %= delta;
	if (pos_x < min_x)
	{
		pos_x += delta;
	}
	const int64_t count = (max_x + delta - pos_x) / delta;
	std::cout << count << std::endl;
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
