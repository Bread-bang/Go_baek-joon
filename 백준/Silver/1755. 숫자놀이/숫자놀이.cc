#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.second < b.second;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<pair<int, string> > v_info;
    string s_num_by_words;
    for(int i = M; i <= N; i++)
    {
        string s_num = to_string(i);
        s_num_by_words = "";
        for(int j = 0; j < s_num.length(); j++)
        {
            switch (s_num[j])
            {
                case '0':
                    s_num_by_words.append("zero ");
                    break;

                case '1':
                    s_num_by_words.append("one ");
                    break;
                
                case '2':
                    s_num_by_words.append("two ");
                    break;
                
                case '3':
                    s_num_by_words.append("three ");
                    break;
                
                case '4':
                    s_num_by_words.append("four ");
                    break;
                
                case '5':
                    s_num_by_words.append("five ");
                    break;
                
                case '6':
                    s_num_by_words.append("six ");
                    break;
                
                case '7':
                    s_num_by_words.append("seven ");
                    break;
                
                case '8':
                    s_num_by_words.append("eight ");
                    break;
                
                case '9':
                    s_num_by_words.append("nine ");
                    break;
                
                default:
                    break;
            }
        }
        s_num_by_words.pop_back();
        v_info.emplace_back(i, s_num_by_words);
    }
    
    sort(v_info.begin(), v_info.end(), compare);

    int line = 1;
    for(auto item : v_info)
    {
        cout << item.first;
        if(line++ == 10)
        {
            cout << "\n";
            line = 1;
        }
        else
            cout << " ";
    }


    return 0;
}