#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll climbStairs(ll n, ll m) {
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (i - j >= 0) dp[i] += (dp[i - j]) % 20211114;
        }
    }
    return dp[n] % 20211114;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << climbStairs(n, m) << endl;
    return 0;
}