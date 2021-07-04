#include <bits/stdc++.h>
using namespace std;

int getValue(string s) {
    vector<char> stack;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {  //表达式是数字就入栈
            stack.push_back(s[i]);
        } else {  //操作数就出栈上面2个数
            int right = stack.back() - '0';
            stack.pop_back();
            int left = stack.back() - '0';
            stack.pop_back();

            if (s[i] == '+') stack.push_back(left + right + '0');
            if (s[i] == '-') stack.push_back(left - right + '0');
            if (s[i] == '*') stack.push_back(left * right + '0');
            if (s[i] == '/') stack.push_back(left / right + '0');
        }
    }
    return stack.back() - '0';
}

int main() {
    // string test = "23+5*1-";
    string test = "671-*82/+";
    cout << getValue(test) << endl;
    return 0;
}