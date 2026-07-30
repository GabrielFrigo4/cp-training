#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;

void task() {
    ll K;
    cin >> K;

    for (ll i = 1; i <= 100; i++) {
        if (to_string(K * i).find("00") != string::npos) {
            cout << (K * i) << endl;
            return;
        }
    }
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
