#include <bits/stdc++.h>
#include <algorithm>
#define C2D(x) (x - '0')

struct watch_t {
	int64_t h, m;
};

void print_watch(const watch_t watch) {
	if (watch.h == 0) {
		std::cout << "00";
	}
	else if (watch.h < 10) {
		std::cout << "0" << watch.h;
	}
	else {
		std::cout << watch.h;
	}
	std::cout << ":";
	if (watch.m == 0) {
		std::cout << "00";
	}
	else if (watch.m < 10) {
		std::cout << "0" << watch.m;
	}
	else {
		std::cout << watch.m;
	}
	std::cout << std::endl;
}

watch_t string_to_watch(const std::string &str) {
	watch_t watch = {0, 0};
	watch.h = C2D(str[0])*10 + C2D(str[1]);
	watch.m = C2D(str[3])*10 + C2D(str[4]);
	return watch;
}

int64_t get_minutes(const watch_t watch) {
	return watch.m + watch.h * 60;
}

watch_t get_watch(const int64_t minutes) {
	return {minutes / 60, minutes % 60};
}

void test_case(void) {
	std::string str1, str2;
	std::cin >> str1 >> str2;
	const watch_t watch1 = string_to_watch(str1);
	const watch_t watch2 = string_to_watch(str2);

	const int64_t minutes1 = get_minutes(watch1);
	const int64_t minutes2 = get_minutes(watch2);
	const int64_t minutes_med = (minutes1 + minutes2)/2;
	const watch_t watch_med = get_watch(minutes_med);
	print_watch(watch_med);
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_case();
	return 0;
}
