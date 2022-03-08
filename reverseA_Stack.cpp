#include <bits/stdc++.h>
using namespace std;
void func2(stack<int> &st, int elem)
{
    if (st.empty())
    {
        st.push(elem);
        return;
    }

    int element = st.top();
    st.pop();
    func2(st, elem);
    st.push(element);
}
void func(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int elem = st.top();
    st.pop();
    func(st);
    func2(st, elem);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    func(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
