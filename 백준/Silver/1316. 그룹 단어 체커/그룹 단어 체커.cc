#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // string 입력 받기
    // for문 돌면서 해당 인덱스의 원소를 find_first와 find_last로 검색하여 인덱스가 서로 같으면 단일 문자
    // 그렇지 않으면, 그 사이의 범위로 for문을 돌면서 다 같은 원소이면 그룹 문자
    // 아니면 그룹 문자가 아님

    int N;
    int i, j;
    int result = 0;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        bool isGroupNum = true;

        if(input.size() <= 2)
        {
            result++;
            continue;
        }
        for(int j = 0; j < input.size(); j++)
        {
            for(int k = input.find(input[j]); k < input.find_last_of(input[j]) + 1; k++)
            {
                if(input[j] != input[k]) 
                {
                    isGroupNum = false;
                    break;
                }
            }
            j = input.find_last_of(input[j]);
        }
        if(isGroupNum)
            result++;
    }

    cout << result;


    return 0;
}