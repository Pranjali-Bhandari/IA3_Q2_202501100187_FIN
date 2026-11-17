
/*
    Data Structures IA-3 - Question 2
    PRN: 202501100187

    Seed S = 187
    Scenario = Cold-Drink Flavours
    Hash Function = Mid-Square
    Collision Handling = Separate Chaining
    Table Size = 17
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int S = 187;
    vector<int> keys;

    for (int i = 0; i < 20; i++)
    {
        int value = (S + 13 * i) % 100;
        keys.push_back(value);
    }

    cout << "Personalized Dataset:" << endl;

    for (int i = 0; i < keys.size(); i++)
    {
        cout << keys[i] << " ";
    }

    cout << endl;

    return 0;
}
