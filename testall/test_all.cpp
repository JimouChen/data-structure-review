#include <bits/stdc++.h>
using namespace std;

int getIndexBL(string s, string t) {
    int i = 0, j = 0;

    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;  // back
            j = 0;
        }
    }
    if (j == t.size())
        return (i - t.size() + 1);
    else
        return -1;
}

void getNext(string t, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < t.size()) {
        if (j == 0 || t[i] == t[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int getKmp(string s, string t) {
    int i = 0, j = 0;
    int next[t.size()];
    getNext(t, next);
    while (i < s.size() && j < t.size()) {
        if (j == 0 || s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }

    if (j == t.size())
        return i - t.size() + 1;
    else
        return -1;
}

int main() {
    string s = "123231434", t = "143";

    //cout << getKmp(s, t) << endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout<<q.back()<<" "<<q.front();

}