#include <iostream>
#include <vector>

using namespace std;

int current_people, max_people;

int main()
{
    vector<int> off_people(4);
    vector<int> on_people(4);
    
    for(int i = 0; i < 4; i++)
    {
        cin >> off_people[i];
        cin >> on_people[i];

        current_people = on_people[i] + current_people - off_people[i];
        max_people = max_people > current_people ? max_people : current_people;
    }

    cout << max_people << endl;
    return 0;
}