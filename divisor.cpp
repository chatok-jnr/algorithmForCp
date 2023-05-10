#include <bits/stdc++.h>
using namespace std;
int main()
{

    set<int> s;
    cout << "Enter a number = ";
    int x;
    cin >> x;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            s.insert(i);
            s.insert(x / i);
        }
    }
    for (auto u : s)
    {
        cout << u << " ";
    }

    return 0;
}