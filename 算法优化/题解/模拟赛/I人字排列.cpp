#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p = 1000000007;

//C(n,m)=C(n-1,m-1)+C(n-1,m)，n<=10,000，dp打表
ll dpCombination(ll n, ll m) {
    vector<vector<ll>> c(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n + 1; ++i)
        c[i][0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            c[i][j] = ((c[i - 1][j - 1]) % p + (c[i - 1][j]) % p) % p;
    return c[n][m];
}

int main() {
    ll n;
    cin >> n;
    n--;
    ll m = n >> 1;
    cout << dpCombination(n, m);

    return 0;
}