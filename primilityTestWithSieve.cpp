#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
const int N = 1e7;
bool mark[N];
int main()
{
    vector<ll> prime;
    prime.pb(2);
    for (ll i = 3; i < N; i++)
    {
        if (mark[i] == false)
        {
            prime.pb(i);

            for (ll j = i * i; j < N; j += (i + i))
            {
                if (j % i == 0)
                {
                    mark[j] = true;
                }
            }
        }
    }

    return 0;
}