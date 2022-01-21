#include <iostream>
#include <bits.h>
using namespace std;
class Solution
{
public:
    int countsetbits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count++;
            n &= (n - 1);
        }
        return count;
    }
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        return countsetbits(a ^ b);
    }
};
int main()
{
    int a, b;
    cin >> a >> b;
    Solution ob;
    cout << ob.countBitsFlip(a, b) << endl;
}