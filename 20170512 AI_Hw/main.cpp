#include <iostream>
#include <stdio.h>
using namespace std;

const int houseLength = 14;

bool relocation(int[], int, int[]);

int main() {
    int n, now[houseLength], next[houseLength], picked;
    bool result;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < houseLength; j++)
            cin >> now[j];
        cin >> picked;

        result = relocation(now, picked, next);

        cout << "[" << next[0];
        for (int j = 1; j < houseLength; j++)
            cout << " " << next[j];
        cout << "]" << endl;

        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

bool relocation(int nowHouse[], int pickedHouse, int nextHouse[]) {
    int houseIndex[] = {houseLength / 2 - 1, houseLength - 1};
    int myHouse = pickedHouse / 7;
    int left = nowHouse[pickedHouse];
    int goHouse = pickedHouse + 1;

    for (int i = 0; i < houseLength; i++) {
        if (i == pickedHouse) {
            nextHouse[i] = 0;
            continue;
        }
        nextHouse[i] = nowHouse[i];
    }

    while (left) {
        goHouse = goHouse % houseLength;
        if (goHouse != houseIndex[!myHouse]) {
            nextHouse[goHouse]++;
            left--;
        }
        goHouse++;
    } goHouse--;

    int oppsite = houseLength - 2 - goHouse;
    if (oppsite != houseIndex[0] && oppsite != houseIndex[1])
        if (goHouse / 7 == myHouse)
        if (nextHouse[goHouse] == 1 && nextHouse[oppsite] > 0) {
            nextHouse[houseIndex[myHouse]] += nextHouse[goHouse] + nextHouse[oppsite];
            nextHouse[goHouse] = nextHouse[oppsite] = 0;
        }

    if (goHouse == houseIndex[myHouse])
        return true;
    return false;
}

