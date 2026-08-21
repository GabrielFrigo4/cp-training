#include <bits/stdc++.h>

struct line_t {
	double a, b;
};

bool cmp (line_t &l1, line_t &l2) {
	return  l1.a < l2.a;
}

int64_t collide(line_t l1, line_t l2) {
	double x = -(l2.b - l1.b) / (l2.a - l1.a);
	return x;
}

int main(void) {
	int64_t N, X1, X2;
	std::cin >> N >> X1 >> X2;
	
	std::vector<line_t> lines(N);
	for (line_t &line : lines) {
		int64_t A, B;
		std::cin >> A >> B;
		line.a = static_cast<double>(A);
		line.b = static_cast<double>(B);
	}
	
	std::sort(lines.begin(), lines.end(), cmp);
	std::map<int64_t, std::size_t> cache;
	for (std::size_t i = 0; i < N; i++) {
		if (cache.find(lines[i].a) == cache.end()) {
			cache[lines[i].a] = i + 1;
		}
		else {
			cache[lines[i].a]++;
		}
	}
	
	int64_t col = 0;
	for (std::size_t i = 0; i < N; i++) {
		for (std::size_t j = cache[lines[i].a]; j < N; j++) {
			double x = collide(lines[i], lines[j]);
			col += ((x >= X1) && (x <= X2));
		}	
	}
	
	std::cout << col << std::endl;
	return 0;
}
