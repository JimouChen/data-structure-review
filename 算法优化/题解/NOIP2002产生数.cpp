#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<vector<ll>> res;

void save(vector<ll> &vec, ll t[]) {
    vector<ll> temp;
    for (ll i = 0; i < vec.size(); i++)
        if (vec[i]) temp.emplace_back(t[i]);
    res.emplace_back(temp);
}

bool compare(ll a, ll b) {
    if (a > b)
        return true;
    else
        return false;
}

void combination(ll t[], ll c, ll total) {
    //初始化组合，如:1,1,0,0,0
    vector<ll> vecll(total);
    for (ll i = 0; i < c; ++i)
        vecll[i] = 1;

    save(vecll, t);

    for (ll i = 0; i < total - 1; ++i) {
        if (vecll[i] == 1 && vecll[i + 1] == 0) {
            //1. 第一次改变1 0 为0 1
            swap(vecll[i], vecll[i + 1]);

            //2.把0,1中0的前面所有1都移到最前面
            sort(vecll.begin(), vecll.begin() + i, compare);

            //1 2步骤之后就得到新的组合
            save(vecll, t);
            i = -1;
        }
    }
}

bool isPrime(ll num) {
    if (num < 2) return false;
    int i;
    for (i = 2; i <= int(sqrt(num)); i++) {
        if (num % i == 0) break;
    }
    if (i == int(sqrt(num)) + 1) return true;
    return false;
}

int main() {
    int n, k, i = 0, count = 0;
    cin >> n >> k;
    ll t[n];
    while (i < n) {
        cin >> t[i++];
    }
    combination(t, k, n);
    for (int i = 0; i < res.size(); i++) {
        ll tempSum = 0;
        for (int j = 0; j < res[i].size(); j++)
            tempSum += res[i][j];
        if (isPrime(tempSum)) count++;
    }
    cout << count << endl;

    return 0;
}
/*
4 3
3 7 12 19
 */