#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& list, int left, int right);
void merge(vector<int>& list, int left, int mid, int right);

static vector<int> sorted;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> list(N);
    sorted.resize(N);

    for(int i = 0; i < N; i++)
        cin >> list[i];
    
    merge_sort(list, 0, N - 1);

    for(int i = 0; i < N; i++)
        cout << list[i] << "\n";

    return 0;
}

void merge(vector<int>& list, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    while(i <= mid)
    {
        sorted[k++] = list[i++];
    }

    while(j <= right)
    {
        sorted[k++] = list[j++];
    }

    for(int l = left; l <= right; l++)
    {
        list[l] = sorted[l];
    }
}

void merge_sort(vector<int>& list, int left, int right)
{
    int mid = (left + right) / 2;

    if(left < right)
    {
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}