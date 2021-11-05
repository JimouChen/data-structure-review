#ifndef DATA_STRUCTURE_REVIEW_TOOL_H
#define DATA_STRUCTURE_REVIEW_TOOL_H

# include <bits/stdc++.h>

using namespace std;
typedef long long ll;


//判断素数
bool isPrime(ll num) {
    if (num < 2) return false;
    int i;
    for (i = 2; i <= int(sqrt(num)); i++) {
        if (num % i == 0) break;
    }
    if (i == int(sqrt(num)) + 1) return true;
    return false;
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

    save(vec, t);

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

//高精度加法

string addBigNum(string &sa, string &sb) {
    if (sa == "0" && sb == "0") return "0";

    int lenA = sa.size(), lenB = sb.size();
    int lenC = max(lenA, lenB) + 1;
    vector<int> a(lenC);
    vector<int> b(lenC);
    vector<int> c(lenC);
    for (int i = 0; i < lenA; i++)
        a[lenA - i - 1] = sa[i] - '0';
    for (int i = 0; i < lenB; ++i)
        b[lenB - i - 1] = sb[i] - '0';

    //核心部分
    for (int i = 0; i < lenC; ++i) {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    string res = "";
    for (int i = 0; i < lenC; ++i)
        res += c[i] + '0';

    //翻转后去掉前导0
    reverse(res.begin(), res.end());
    if (res[0] == '0')
        res = res.substr(1, res.size() - 1);

    return res;
}

#endif //DATA_STRUCTURE_REVIEW_TOOL_H
