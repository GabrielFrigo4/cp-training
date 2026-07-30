#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;

ll op(ll &N, ll c) {
    if (N == 0) return 0;
    ll s = 0;
    N--; s++;
    if (N < c) {
        s += 2 * N;
        N = 0;
    } else {
        s += 2 * c;
        N -= c;
    }
    return s;
}

ll i_n(ll n) {
    return (n - 3) / 2;
}

ll n_i(ll i) {
    if (i < 0) return 0;
    return 2 * i + 3;
}

ll a_i(ll i) {
    if (i < 0) return 0;
    return 4 + 8 * (2 * i + 1);
}

ll pa_sum(ll i) {
    if (i < 0) return 0;
    ll a0 = a_i(0);
    ll ai = a_i(i);
    return ((a0 + ai) * (i + 1)) / 2;
}

void task() {
    ll N;
    cin >> N;

    ll sqrtN = static_cast<ll>(sqrt(N));
    if (sqrtN * sqrtN > N) {
        sqrtN--;
    }
    if ((sqrtN & 1) == 0) {
        sqrtN--;
    }

    ll csum = pa_sum(i_n(sqrtN));
    N -= sqrtN * sqrtN;
    csum += op(N, sqrtN - 1);
    csum += op(N, sqrtN);
    csum += op(N, sqrtN);
    csum += op(N, sqrtN + 1);
    cout << csum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T = 1;
    if (cin >> T) {
        while (T--) {
            task();
        }
    }
    return 0;
}
