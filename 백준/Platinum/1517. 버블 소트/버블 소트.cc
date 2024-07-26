#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<pair<int, int> >& arr, int left, int right);
void merge(vector<pair<int, int> >& arr, int left, int mid, int right);

long swap_count = 0;
vector<pair<int, int> > sorted;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    sorted.resize(N);

    vector<pair<int, int> > arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    merge_sort(arr, 0, N - 1);

    cout << swap_count << "\n";
    
    return 0;
}

void merge_sort(vector<pair<int, int> >& arr, int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(vector<pair<int, int> >& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(arr[i].first <= arr[j].first)
        {
           sorted[k++] = arr[i++]; 
        }
        else
        {
            sorted[k++] = arr[j++];
            swap_count += (mid - i + 1);
        }
    }

    while(i <= mid)
    {
        sorted[k++] = arr[i++];
    }

    while(j <= right)
    {
        sorted[k++] = arr[j++];
    }

     for(int l = left; l <= right; l++)
        arr[l] = sorted[l];
}