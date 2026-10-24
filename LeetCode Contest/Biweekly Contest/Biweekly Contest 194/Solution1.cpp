#include <iostream>
#include <vector>
using namespace std;

int peakValleyDifference(vector<int> &nums)
{
    int n = nums.size();
    int peak_sum = 0, valley_sum = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            peak_sum += nums[i];
        }
        else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
        {
            valley_sum += nums[i];
        }
    }

    return peak_sum - valley_sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << peakValleyDifference(nums) << endl;
}

// My Approach:-

// 1. Initialize two variables, peak_sum = 0 and valley_sum = 0, to store the sum of peak and valley elements.

// 2. Traverse the array from index 1 to n - 2, because the first and last elements cannot be peaks or valleys.

// 3. For each element, check whether it is greater than both its previous and next elements. If true, add it to peak_sum.
//    Otherwise, check whether it is smaller than both its previous and next elements. If true, add it to valley_sum.

// 5. Finally, return peak_sum - valley_sum as the answer.

// Complexity Analysis
// Time Complexity => O(n), as we traverse the array once.
// Space Complexity => O(1), as we use only a constant number of extra variables.