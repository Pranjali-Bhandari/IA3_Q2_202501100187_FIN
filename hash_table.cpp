/*
    PRN: 202501100187
    Seed S: 187
    Domain scenario: Cold-drink flavours
    Hash function: Mid-square method
    Collision strategy: Separate chaining
    Table size: 10
*/


#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

int midSquareHash(int key) {
    long long square = (long long)key * key;

    string squareString = to_string(square);
    int length = squareString.length();

    int middleValue;

    // For a 4-digit square, take the middle two digits.
    // Example: 87 * 87 = 7569, middle digits = 56
    if (length % 2 == 0) {
        string middle = squareString.substr(length / 2 - 1, 2);
        middleValue = stoi(middle);
    }
    // For a 3-digit square, take the middle digit.
    // Example: 13 * 13 = 169, middle digit = 6
    else {
        middleValue = squareString[length / 2] - '0';
    }

    return middleValue % TABLE_SIZE;
}

int main() {
    cout << "PRN: 202501100187" << endl;
    cout << "Seed S: 187" << endl;
    cout << "Scenario: Cold-drink flavours" << endl;
    cout << "Hash function: Mid-square method" << endl;
    cout << "Collision strategy: Separate chaining" << endl;
    cout << "Table size: " << TABLE_SIZE << endl;

    cout << "\nTesting mid-square hash function:\n";

    int testKeys[] = {87, 0, 13, 26, 39};

    for (int i = 0; i < 5; i++) {
        int key = testKeys[i];
        int index = midSquareHash(key);

        cout << "Key: " << key
             << " | Square: " << (long long)key * key
             << " | Hash index: " << index << endl;
    }

    return 0;
}