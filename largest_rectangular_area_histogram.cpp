#include <bits/stdc++.h>
using namespace std;
vector<int> next_smaller(vector<int> &a, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {

        while (st.top() != -1 && a[st.top()] >= a[i])
        {
            st.pop();
        }
        res[i] = st.top();
        st.push(i);
    }
    return res;
}
vector<int> prev_smaller(vector<int> &a, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {

        while (st.top() != -1 && a[st.top()] >= a[i])
        {
            st.pop();
        }
        res[i] = st.top();
        st.push(i);
    }
    return res;
}
int Area_of_histogram(vector<int> &heights, int n)
{
    vector<int> next(n);
    next = next_smaller(heights, n);
    vector<int> prev(n);
    prev = prev_smaller(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int length = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int breath = next[i] - prev[i] - 1;
        int newarea = length * breath;
        area = max(area, newarea);
    }
    return area;
}
int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto &i : heights)
    {
        cin >> i;
    }
    int area = Area_of_histogram(heights, n);
    cout << area;
    return 0;
}
