// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

 

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 
// Constraints:

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// arr[i] < arr[j] for 1 <= i < j <= arr.length
 

#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

// So, in the given array, the preceding neighbor of the kth missing number is vec[high]. 
// Now, we know, up to index ‘high’,
// the number of missing numbers = vec[high] - (high+1).
// But we want to go further and find the kth number. To extend our objective, we aim to find the kth number 
// in the sequence. In order to determine the number of additional missing values required to reach the kth position, 
// we can calculate this as
// more_missing_numbers = k - (vec[high] - (high+1)).
// Now, we will simply add more_missing_numbers to the preceding neighbor i.e. vec[high] to get the kth missing number.
// kth missing number = vec[high] + k - (vec[high] - (high+1))
//         =  vec[high] + k - vec[high] + high + 1
//         = k + high + 1.