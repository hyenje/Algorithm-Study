/*
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define LL_INF 9'223'372'036'854'775'807
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 998'244'353
#define BIG 4294967295
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll t;
map<ll, int> m;

int solve(ll val)
{
    if (val >= t)
        return m[val] = 0;
    if (m.find(val) != m.end())
        return m[val];

    int flag = 0;
    for (ll i = 2; i < 10; i++)
        flag |= !solve(i * val);

    return m[val] = flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (scanf("%lld", &t) != EOF)
    {
        m.clear();
        if (solve(1))
            cout << "Baekjoon wins.\n";
        else
            cout << "Donghyuk wins.\n";
    }

    return 0;
}
/*
 */