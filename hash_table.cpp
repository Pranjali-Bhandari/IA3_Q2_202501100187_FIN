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

    if (length % 2 == 0) {
        string middle = squareString.substr(length / 2 - 1, 2);
        middleValue = stoi(middle);
    } else {
        middleValue = squareString[length / 2] - '0';
    }

    return middleValue % TABLE_SIZE;
}

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int index = midSquareHash(key);

        table[index] = key;

        cout << "Inserted " << key
             << " at index " << index << endl;
    }

    void display() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " -> ";

            if (table[i] == -1) {
                cout << "EMPTY";
            } else {
                cout << table[i];
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    int data[20] = {
        87, 0, 13, 26, 39,
        52, 65, 78, 91, 4,
        17, 30, 43, 56, 69,
        82, 95, 8, 21, 34
    };

    cout << "Inserting 20 personalized values without collision handling:\n\n";

    for (int i = 0; i < 20; i++) {
        hashTable.insert(data[i]);
    }

    hashTable.display();

    return 0;
}