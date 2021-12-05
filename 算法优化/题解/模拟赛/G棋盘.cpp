#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    if ((n + m) % 2 == 0)cout << n * m / 2 + 1;
    else cout << n * m / 2;

    return 0;
}