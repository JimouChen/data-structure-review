#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
    if (x < 0) return false;
    string temp = to_string(x);
    int len = temp.size();
    int i = 0;
    while (i <= int(len / 2)) {
        if (temp[i] != temp[len - i - 1]) return false;
        i++;
    }
    return true;
}
int main() {
    int a = 233;
    string aa = to_string(a);
    cout<<isPalindrome(123);
  
    return 0;
}