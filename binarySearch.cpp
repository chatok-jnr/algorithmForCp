#include <bits/stdc++.h>
using namespace std;

void bry(vector<int> v, int y);
int main()
{
    cout << "Enter the size of the vector = ";
    int x;
    cin >> x;
    vector<int> v;
    for (int i = 0; i < x; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << "Enter the number you want to find = ";
    int y;
    cin >> y;
    bry(v, y);
}
void bry(vector<int> v, int y)
{
    int first = 0;
    int last = v.size();
    int mid = (first + last) / 2;
    if (v[mid] == y)
    {
        cout << mid << endl;
    }
    else
    {
        while (v[mid] != y)
        {
            if (v[mid] > y)
            {
                last = mid;
                mid = (first + last) / 2;
            }
            else if (v[mid] < y)
            {
                first = mid;
                mid = (first + last) / 2;
            }
            if (mid == v.size() - 1 && y != v[mid])
            {
                cout << "Y is not availabl in the vector" << endl;
                break;
            }
            else if (v[mid] == y)
            {
                cout << "Y is foundded on the index = " << mid << endl;
            }
        }
    }
}