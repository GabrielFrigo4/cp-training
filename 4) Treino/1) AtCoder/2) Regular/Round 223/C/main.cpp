#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
typedef long long ll;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    if (base < 0) base += mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (ll)((__int128)res * base % mod);
        base = (ll)((__int128)base * base % mod);
        exp /= 2;
    }
    return res;
}

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void task() {
    ll N;
    if (!(cin >> N)) return;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<ll> B(N);
    vector<int> freq(N, 0);
    bool has_duplicates = false;

    for (int i = 0; i < N; i++) {
        B[i] = A[i] % N;
        if (freq[(int)B[i]] > 0) {
            has_duplicates = true;
        }
        freq[(int)B[i]]++;
    }

    if (has_duplicates) {
        cout << 0 << "\n";
        return;
    }

    if (!is_prime(N)) {
        cout << 0 << "\n";
        return;
    }

    int cycles = 0;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cycles++;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = (int)B[curr];
            }
        }
    }

    ll sign = ((N - cycles) % 2 == 0) ? 1 : -1;

    ll P = 1;
    for (ll d = 1; d < N; d++) {
        P = (P * power(d, N - d, N)) % N;
    }

    ll ans = (sign * P) % N;
    if (ans < 0) ans += N;
    cout << ans << "\n";
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
