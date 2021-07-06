#include <bits/stdc++.h>
using namespace std;

void getNext(string t, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;

    while (i < t.size()) {
        if (j == 0 || t[i] == t[j]) {
            i++;
            j++;
            next[i] = j;
        } else
            j = next[j];
    }
}

int getIndexKmp(string s, string t) {
    int i = 0, j = 0;
    int next[t.size() + 1];
    getNext(t, next);
    while (i < s.size() && j < t.size()) {
        if (j == 0 || s[i] == t[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j == t.size())
        return i - t.size() + 1;
    else
        return -1;
}
int main() {
    string s = "123231434", t = "143";
    cout << getIndexKmp(s, t);
}