#include <bits/stdc++.h>
using namespace std;

//用STL实现
bool bracketCheck(string str) {
    vector<char> stack;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack.push_back(str[i]);
        } else {
            if (stack.size() == 0) return false;
            char temp = stack.back();
            stack.pop_back();
            if ((temp == '(') && (str[i] != ')')) return false;
            if ((temp == '[') && (str[i] != ']')) return false;
            if ((temp == '{') && (str[i] != '}')) return false;
        }
    }
    return stack.empty();
}

int main() {
    string s = "{[(())]}";
    if (bracketCheck(s))
        cout << "匹配成功" << endl;
    else
        cout << "匹配失败" << endl;

    return 0;
}