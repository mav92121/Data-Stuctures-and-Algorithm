#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e)
{
    if (s == e)
        return;

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int first[len1];
    int second[len2];

    int mainIndex = s;
    // copy values
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndex++];
    }
    // merge 2 sorted arrays
    int p1 = 0, p2 = 0;
    mainIndex = s;
    while (p1 < len1 && p2 < len2)
    {
        if (first[p1] < second[p2])
        {
            arr[mainIndex++] = first[p1++];
        }
        else
        {
            arr[mainIndex++] = second[p2++];
        }
    }
    while (p1 < len1)
    {
        arr[mainIndex++] = first[p1++];
    }
    while (p2 < len2)
    {
        arr[mainIndex++] = second[p2++];
    }
}
void mergeSort(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    if (s >= e)
        return;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}