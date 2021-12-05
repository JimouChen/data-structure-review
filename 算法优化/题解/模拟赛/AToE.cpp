#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void a() {
    int c;
    for (int i = 10000; i <= 90000; i++)
        if (i % 128 == 0) c++;
    cout << c << endl;
}

void b() {//2021
    int c = 0;
    for (int i = 1000; i <= 9999; ++i) {
        int one = i / 1000;
        int two = i / 100 % 10;
        int three = i / 10 % 10;
        int four = i % 10;
        if (one == three && four == two + 1) c++;
    }
    cout << c << endl;
}

// 组合优化，时间复杂度从n! 优化到n的平方logN
vector<vector<ll>> res;

bool compare(ll a, ll b) {
    if (a > b)
        return true;
    else
        return false;
}

void saveRes(vector<ll> &vec, vector<ll> &t) {
    vector<ll> temp;
    for (ll i = 0; i < vec.size(); i++)
        if (vec[i]) temp.emplace_back(t[i]);
    res.emplace_back(temp);
}

//获取从t.size()里面选出k个数的所有组合
void combination(vector<ll> &t, ll k) {
    ll total = t.size();
    //初始化组合，如:1,1,0,0,0
    vector<ll> vec(total);
    for (ll i = 0; i < k; ++i)
        vec[i] = 1;

    saveRes(vec, t);

    for (ll i = 0; i < total - 1; ++i) {
        if (vec[i] == 1 && vec[i + 1] == 0) {
            //1. 第一次改变1 0 为0 1
            swap(vec[i], vec[i + 1]);
            //2.把0,1中0的前面所有1都移到最前面
            sort(vec.begin(), vec.begin() + i, compare);
            //1 2步骤之后就得到新的组合
            saveRes(vec, t);
            i = -1;
        }
    }
}

void c() {
    vector<ll> num(999);
    for (int i = 0; i < num.size(); i++)num[i] = i + 1;
    combination(num, 998/2);
    cout << res.size() << endl;
}

int main() {
//    a();
//    b();
    c();


    return 0;
}