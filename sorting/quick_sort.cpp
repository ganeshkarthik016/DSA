#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(N*logN), where N = size of the array.

// Reason: At each step, we divide the whole array, for that logN and n steps are taken for the partition() function, 
// so overall time complexity will be N*logN.

// The following recurrence relation can be written for Quick sort : 

// F(n) = F(k) + F(n-1-k) 

// Here k is the number of elements smaller or equal to the pivot and n-1-k denotes elements greater than the pivot.

// There can be 2 cases :

// Worst Case – This case occurs when the pivot is the greatest or smallest element of the array.
//  If the partition is done and the last element is the pivot, then the worst case would be either in
//  the increasing order of the array or in the decreasing order of the array. 

// Recurrence:
// F(n) = F(0)+F(n-1)  or  F(n) = F(n-1) + F(0) 

// Worst Case Time complexity: O(n2) 

// Best Case – This case occurs when the pivot is the middle element or near to middle element of the array.
// Recurrence :
// F(n) = 2F(n/2)

// Time Complexity for the best and average case: O(N*logN)

// Space Complexity: O(1) + O(N) auxiliary stack space.