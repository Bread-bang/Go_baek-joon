#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 끊어진 기타줄의 개수
    int M; // 기타줄 브랜드의 개수
    vector<pair<int, int> > each_brand_price; // first : package 가격, second : each 가격

    cin >> N >> M;
    while(M--)
    {
        int first, second;
        cin >> first >> second;
        each_brand_price.emplace_back(make_pair(first, second));
    }
    int total = 0;
    int min = each_brand_price[0].first;
    while(N)
    {
        if(N >= 6)
        {
            for(int i = 0; i < each_brand_price.size(); i++)
            {
                min = min > each_brand_price[i].first ? each_brand_price[i].first : min;
                min = min > (each_brand_price[i].second * 6) ? (each_brand_price[i].second * 6) : min;
            }
            total += min;
            N -= 6;
        }
        else
        {
            for(int i = 0; i < each_brand_price.size(); i++)
            {
                min = min > each_brand_price[i].first ? each_brand_price[i].first : min;
                min = min > (each_brand_price[i].second * N) ? (each_brand_price[i].second * N) : min;
            }
            total += min;
            N = 0;
        }
    }
    cout << total << "\n";
    return 0;
}