#include <bits/stdc++.h>
using namespace std;

#define maxsize 50
typedef struct {
    int data[maxsize];
    int length;
} LinearList;
void showList(LinearList l) {
    for (int i = 0; i < l.length; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}

void initList(LinearList &l) { l.length = 0; }

int getLength(LinearList l) { return l.length; }

int main() {
    LinearList l;
    initList(l);
    for (int i = 0; i < 10; i++) {
        l.data[i] = i + 1;
    }

    return 0;
}