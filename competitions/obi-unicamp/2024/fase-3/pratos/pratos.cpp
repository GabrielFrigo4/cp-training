#include <bits/stdc++.h>
#define MOD(x) (x % static_cast<uint64_t>(std::pow(10, 9) + 7))

/*
struct ref_t {
	uint64_t a, b;
};

bool ref_cmp(ref_t &r1, ref_t &r2) {
	if (r1.a < r2.a) {
		return true;
	}
	else if (r1.a > r2.a) {
		return false;
	}
	
	if (r1.b > r2.b) {
		return true;
	}
	return false;
}
*/

uint64_t query(const std::vector<uint64_t> &A_F, const std::vector<uint64_t> &B_F,
		const std::vector<uint64_t> &A_R, const std::vector<uint64_t> &B_R, 
		const uint64_t N, const uint64_t M, const uint64_t K, const uint64_t x)
{
	uint64_t ans = x;
	
	// fet
	ans = std::max(ans*A_F[0] + B_F[0], ans*A_F[1] + B_F[1]),
	ans = std::max(ans*A_F[0] + B_F[0], ans*A_F[1] + B_F[1]),

	// ref
	ans = std::max((ans*A_R[0] + B_R[0])*A_R[1] + B_R[1], (ans*A_R[1] + B_R[1])*A_R[0] + B_R[0]);
	
	/*
	for (uint64_t i = 0; i < K; i++) {
		uint64_t tmp = ans;
		for (std::size_t j = 0; j < N; j++) {
			uint64_t _tmp = ans;
			_tmp *= A_F[j];
			_tmp += B_F[j];
			
			if (tmp < _tmp) {
				tmp = _tmp;
			}
		}
		ans = tmp;
	}
	*/

	/*
	std::vector<ref_t> refs(M);
	for (std::size_t i = 0; i < M; i++) {
		refs[i].a = A_R[i];
		refs[i].b = B_R[i];
	}
	std::sort(refs.begin(), refs.end(), ref_cmp);
	
	for (ref_t r : refs) {
		ans = ans * r.a + r.b;
		//std::cout << "ref.a = " << r.a << "; ref.b = " << r.b << std::endl;
	}
	*/
	
	return ans;
}

int main(void) {
	uint64_t N, M, K;
	std::cin >> N >> M >> K;
	
	std::vector<uint64_t> A_F(N);
	for (uint64_t &a_f : A_F) {
		std::cin >> a_f;
	}
	
	std::vector<uint64_t> B_F(N);
	for (uint64_t &b_f : B_F) {
		std::cin >> b_f;
	}

	std::vector<uint64_t> A_R(M);
	for (uint64_t &a_r : A_R) {
		std::cin >> a_r;
	}
	
	std::vector<uint64_t> B_R(M);
	for (uint64_t &b_r : B_R) {
		std::cin >> b_r;
	}
	
	uint64_t Q;
	std::cin >> Q;
	for (uint64_t i = 0; i < Q; i++) {
		uint64_t x;
		std::cin >> x;
		uint64_t ans = query(A_F, B_F, A_R, B_R, N, M, K, x);
		std::cout << MOD(ans) << std::endl;
	}
	
	return 0;
}
