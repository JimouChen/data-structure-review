#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll L, k, n, i = 1, j = 0;
    cin >> L >> k >> n;
    vector<ll> b(n + 1, 0);
    b.push_back(L + 1);
    while (i < n + 1)
        cin >> b[i++];


    vector<ll> cha(n + 1);
    for (i = 1; i <= n + 1; i++)
        cha[j++] = b[i] - b[i - 1] - 1;

    ll ans = 0;
    for (ll i = 0; i < n + 1; i++) {
        if (cha[i] >= k) {
            ans += cha[i] / k;
        }
    }

    cout << ans;

    return 0;
}

/*
100 10 2
25 91

8
 */