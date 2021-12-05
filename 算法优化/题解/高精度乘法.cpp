#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void mtpBigNum(string num1, string num2) {
    ll len1 = num1.size(), len2 = num2.size(), len3 = len1 + len2;
    ll a[len1], b[len2], c[len3];
    for (int i = 0; i < len1; ++i)
        a[len1 - i] = num1[i] - '0';
    for (int i = 0; i < len2; ++i)
        b[len2 - i] = num2[i] - '0';

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] = c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }

    for (int i = 0; i < len3; ++i) {
        cout<<c[i]<<" ";
    }

}

int main() {

    mtpBigNum("123", "12");
    return 0;
}
