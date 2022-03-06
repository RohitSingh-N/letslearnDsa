#include <bits/stdc++.h>
using namespace std;
void func(int n, char src, char helper, char dest)
{
    if (n == 0)
    {
        return;
    }
    func(n - 1, src, helper, dest);
    cout << "Moving from " << src << "to " << helper << endl;
    func(n - 1, helper, dest, src);
}
int main()
{
    func(3, 'A', 'B', 'C');
    return 0;
}
