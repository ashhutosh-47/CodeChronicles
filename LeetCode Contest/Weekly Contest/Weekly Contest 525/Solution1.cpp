#include <iostream>
using namespace std;

class Solution
{
public:
    int SetBits(int num)
    {
        int cnt_one = 0;

        while (num > 0)
        {
            int rem = num % 2;

            if (rem == 1)
                cnt_one++;

            num /= 2;
        }

        return cnt_one;
    }

    int calculateScore(int a, int b)
    {
        int s1 = SetBits(a);
        int s2 = SetBits(b);

        if (s1 >= s2)
            return s1 * s2;
        else
            return s2 / s1;
    }
};

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    Solution obj;

    int result = obj.calculateScore(a, b);

    cout << "Score: " << result << endl;

    return 0;
}

// My Approach:-

// Definition of Set Bits: Set bits are the number of bits having value 1 in the binary representation of a number.

// 1. Create a SetBits() function to count the number of set bits (1s) in the binary representation of a number using % 2 and /= 2.
// 2. Count the set bits of a and b and store them in s1 and s2.
// 3. If s1 >= s2, return s1 * s2; otherwise, return s2 / s1 using integer division.

// Time Complexity => O(log₂ a + log₂ b) — The SetBits() function processes each number by repeatedly dividing it by 2.
// Space Complexity => O(1) — Only a constant amount of extra space is used.