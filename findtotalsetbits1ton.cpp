#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findlargest(int n)
    {
        int x = 0;
        // (1<<x) means 2 (tothepower) x
        while ((1 << x) <= n)
        {
            // we are incrementing x till less then power of 2 is less than n because we want to find a set of bits
            x++;
        }
        // returning (x-1) because we want the number less than 2 raise to the power x to find next set bits of number
        return x - 1;
    }
    int countsetbits(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        // calling function

        int x = findlargest(n);
        // formula derived to find total set bits from 1 to n
        return (x * pow(2, (x - 1))) + (n - pow(2, x) + 1) + countsetbits(n - pow(2, x));
    }
};
int main()
{
    int n = 11;
    Solution ob;
    cout << "The total set bits in for 1 to 11 are " << ob.countsetbits(n) << endl;
}