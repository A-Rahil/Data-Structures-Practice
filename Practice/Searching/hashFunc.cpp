//Linear probing
#include <iostream>
using namespace std;

int sent = -999;
int hashMap[11];

int h(int key) {
    int index = key % 11;
    while (hashMap[index] != sent) {
        index = (index + 1) % 11;
    }
    return index;
}

int main() {
    for (int i = 0; i < 11; i++) {
        hashMap[i] = sent;
    }
    hashMap[h(11)] = 11;
    hashMap[h(13)] = 13;
    hashMap[h(22)] = 22;
    hashMap[h(21)] = 21;
    hashMap[h(33)] = 33;
    hashMap[h(44)] = 44;

    for (int i = 0; i < 11; i++) {
        cout << i << ": " << hashMap[i] << endl;
    }
    return 0;
}