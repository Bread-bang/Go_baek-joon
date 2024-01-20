#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums(5);
    int square_sum = 0;

    for(int i = 0; i < 5; i++)
    {
        cin >> nums[i];
        square_sum += (nums[i] * nums[i]);
    }

    cout << square_sum % 10 << endl;

    return 0;
}