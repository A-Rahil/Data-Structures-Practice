#include <iostream>
using namespace std;

int hashMap[11];
int sent = -999;

int h(int key) {
    int initIndex = key % 11;
    int index = initIndex;
    int i = 1;
    while (hashMap[index] != sent) {
        index = (initIndex + i * i) % 11;
        i++;
    }
    return index;
}

int main() {
    for (int i = 0; i < 11; i++) 
        hashMap[i] = sent;

    hashMap[h(11)] = 11;
    hashMap[h(13)] = 13;
    hashMap[h(22)] = 22;
    hashMap[h(21)] = 21;
    hashMap[h(33)] = 33;
    hashMap[h(44)] = 44;

    for (int i = 0; i < 11; i++) 
        cout << i << ": " << hashMap[i] << endl;
    return 0;
}