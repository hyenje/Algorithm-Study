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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int f_count(ll a)
{
    int n = 0;
    while (a)
    {
        if (a % 10 == 5)
            n++;
        a /= 10;
    }
    return n;
}

void solve()
{
    ll n, k, comp = 0;
    cin >> n >> k;
    n++;

    ll num = 1;
    while (true)
    {
        if (f_count(n) >= k)
            break;
        ll tmp = (n / num) % 10ll;
        if (tmp != 5)
            n += num;
        else
            num *= 10ll;
    }

    cout << n << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */