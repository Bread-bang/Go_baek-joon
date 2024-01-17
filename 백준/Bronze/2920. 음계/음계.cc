#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(8);
    for(size_t i = 0; i < v.size(); i++)
        cin >> v[i];

    if(v == vector<int>{1, 2, 3, 4, 5, 6, 7, 8})
        cout << "ascending" << endl;
    else if(v == vector<int>{8, 7, 6, 5, 4, 3, 2, 1})
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;

    return 0;
}