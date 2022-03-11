#include <bits/stdc++.h>
using namespace std;
vector<int> next_Smaller(vector<int> a, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {

        while (st.top() >= a[i])
        {
            st.pop();
        }
        res[i] = st.top();
        st.push(a[i]);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    vector<int> ans;
    ans = next_Smaller(a, n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
