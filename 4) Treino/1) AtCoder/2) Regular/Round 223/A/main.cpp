#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> pref_w, pref_v;
vector<ll> w_arr, v_arr;

ll solver(int i, ll w) {
    if (i < 0) return 0;
    if (w >= pref_w[i]) {
        return pref_v[i];
    }
    if (w < w_arr[i]) {
        return solver(i - 1, w);
    }
    return max(pref_v[i - 1], solver(i - 1, w - w_arr[i]) + v_arr[i]);
}

void task() {
    int N;
    ll W;
    if (!(cin >> N >> W)) return;
    w_arr.resize(N);
    v_arr.resize(N);
    pref_w.resize(N);
    pref_v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> w_arr[i] >> v_arr[i];
        pref_w[i] = w_arr[i] + (i > 0 ? pref_w[i - 1] : 0);
        pref_v[i] = v_arr[i] + (i > 0 ? pref_v[i - 1] : 0);
    }
    cout << solver(N - 1, W) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            task();
        }
    }
    return 0;
}
