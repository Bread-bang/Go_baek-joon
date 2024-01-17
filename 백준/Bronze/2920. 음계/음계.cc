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

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int v[8];
//     int asc_cnt = 0;
//     int des_cnt = 0;

//     for(int i = 0; i < 8; i++)
//     {
//         cin >> v[i];

//         if(v[i] == i + 1)
//             asc_cnt++;
//         else if(v[i] == 8 - i)
//             des_cnt++;
//     }

//     if(asc_cnt == 8) cout << "ascending" << endl;
//     else if(des_cnt == 8) cout << "descending" << endl;
//     else cout << "mixed" << endl;

//     return 0;
// }
