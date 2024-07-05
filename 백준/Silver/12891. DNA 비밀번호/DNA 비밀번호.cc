#include <iostream>
#include <string>

#define DNA_COMPONENTS_LENGTH 4

using namespace std;

void add(char ch, int * pw_check);
void remove(char ch, int * pw_check);
void check(int * pw_arr, int * pw_check, int & count);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S = 0, P = 0;
    string DNA = "";
    int pw_arr[DNA_COMPONENTS_LENGTH] = {0,};
    int pw_check[DNA_COMPONENTS_LENGTH] = {0,};
    int count = 0;

    cin >> S >> P;
    cin >> DNA;
    for(int i = 0; i < DNA_COMPONENTS_LENGTH; i++)
        cin >> pw_arr[i];

    // 초기 pw_check
    for(int i = 0; i < P; i++)
        add(DNA[i], pw_check);

    // Check
    check(pw_arr, pw_check, count);
    
    // 두 번째 부분 문자열 부터
    for(int i = 1; i + P <= S; i++)
    {
        remove(DNA[i - 1], pw_check);
        add(DNA[i + P - 1], pw_check);
        check(pw_arr, pw_check, count);
    }

    cout << count << "\n";

    return 0;
}

void check(int * pw_arr, int * pw_check, int & count)
{
    for(int i = 0; i < DNA_COMPONENTS_LENGTH; i++)
    {
        if(pw_arr[i] > pw_check[i])
            return;
    }

    count++;
}

void add(char ch, int * pw_check)
{
    switch (ch)
    {
        case 'A':
            pw_check[0]++;
            break;

        case 'C':
            pw_check[1]++;
            break;

        case 'G':
            pw_check[2]++;
            break;

        case 'T':
            pw_check[3]++;
            break;
        
        default:
            break;
    }
}

void remove(char ch, int * pw_check)
{
    switch (ch)
    {
        case 'A':
            pw_check[0]--;
            break;

        case 'C':
            pw_check[1]--;
            break;

        case 'G':
            pw_check[2]--;
            break;

        case 'T':
            pw_check[3]--;
            break;
        
        default:
            break;
    }
}