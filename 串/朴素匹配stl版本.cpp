#include <bits/stdc++.h>
using namespace std;

int getIndex(string s, string t) {
    int i = 0, j = 0;  //从0开始，i指向s，j指向t
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == t.size())
        return i - t.size();
    else
        return -1;  //匹配失败
}

int main() {
    string s = "helloworld", t = "owo";
    cout << getIndex(s, t) << endl;
    return 0;
}