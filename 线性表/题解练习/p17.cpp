#include "p17.h"

int main() {
    int R[] = {1, 2, 3, 4, 5, 6, 7};
    circleLeft(R, 7, 3);
    for (int i = 0; i < 7; i++)cout << R[i] << " ";
    cout << endl;
    return 0;
}