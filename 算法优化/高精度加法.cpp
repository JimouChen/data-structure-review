#include<bits/stdc++.h>

using namespace std;

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

int main() {
    string sa, sb;
    getline(cin, sa);
    getline(cin, sb);
    cout << addBigNum(sa, sb);
    return 0;
}//
// Created by jmchen on 2021/11/5.
//

