// Given a positive integer N, print count of set bits in it..
#include <iostream>
#include <bits.h>
class Solution
{
public:
    int setbits(int N)
    {
        int count = 0;
        while (N)
        {
            N = N & (N - 1);
            count++;
        }
        return count;
    }
};
using namespace std;
int main()
{
    int N;
    cin >> N;
    Solution ob;
    int cnt = ob.setbits(N);
    cout << cnt << endl;
    return 0;
}
