#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    // Method-01: Brute Force
    int n = nums.size();
    long long cnt_subarray = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (nums[j] >= minK && nums[j] <= maxK)
            {
                cnt_subarray++;
            }
            else
            {
                break;
            }
        }
    }
    return cnt_subarray;


    // Method-02: Observation
    int n = nums.size();
    long long cnt_subarray = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        if (nums[r] >= minK && nums[r] <= maxK)
            cnt_subarray += r - l + 1;
        else
        {
            l = r + 1;
        }
        r++;
    }
    return cnt_subarray;
}

int main()
{
    int n, minK, maxK;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cin >> minK >> maxK;

    cout << countSubarrays(nums, minK, maxK) << endl;
}

//  Approach-01:- Brute Force

// # Intuition-
// We check every possible subarray using two nested loops. For each subarray, we verify whether all its elements lie between minK and maxK. 
// If all elements satisfy the condition, we increase the count.

// Time Complexity => O(n²)  
// Space Complexity => O(1)

// *** //// *** //

// Approach-02:- Observation

// # Intuition-
// We traverse the array and check each element. If the element lies within the given range, we increase the count of valid subarrays. 
// Otherwise, we decrease the count based on the current segment length.

// We use two pointers, l and r, to traverse the array. For every element, we check whether it lies between `minK` and `maxK`.

// If the element is within the range, we add r - l + 1 to the count because it represents the number of subarrays ending at the current index.

// If the element is outside the range, we subtract the same value from the count.

// We continue this process until we reach the end of the array and return the absolute value of the count.

// Complexity Analysis:-
// Time Complexity => O(n) — We traverse the array once.
// Space Complexity => O(1) — We use only a constant amount of extra space.
