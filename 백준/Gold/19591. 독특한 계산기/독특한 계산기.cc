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

deque<ll> arr;

ll cal(ll a, ll c)
{
    if (c == -1)
        return arr[a - 1] + arr[a + 1];
    if (c == -2)
        return arr[a - 1] - arr[a + 1];
    if (c == -3)
        return arr[a - 1] * arr[a + 1];
    if (c == -4)
        return arr[a - 1] / arr[a + 1];
}

void solve()
{
    ll val = 0, par = 1;
    string s;
    cin >> s;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            val += par * (ll)(s[i] - '0');
            par *= 10;
        }
        else
        {
            arr.push_front(val);
            if (s[i] == '+')
                arr.push_front(-1);
            else if (s[i] == '-')
                arr.push_front(-2);
            else if (s[i] == '*')
                arr.push_front(-3);
            else if (s[i] == '/')
                arr.push_front(-4);
            par = 1;
            val = 0;
        }
    }
    arr.push_front(val);
    if (arr.front() == 0 && arr.size() > 1)
    {
        arr[2] = cal(1, arr[1]);
        arr.pop_front();
        arr.pop_front();
    }

    while (arr.size() > 1)
    {
        ll f = cal(1, arr[1]), b = cal(arr.size() - 2, arr[arr.size() - 2]);
        if (arr[1] < -2 && arr[arr.size() - 2] > -3)
        {
            arr[2] = f;
            arr.pop_front();
            arr.pop_front();
        }
        else if (arr[1] > -3 && arr[arr.size() - 2] < -2)
        {
            arr[arr.size() - 3] = b;
            arr.pop_back();
            arr.pop_back();
        }
        else if (f >= b)
        {
            arr[2] = f;
            arr.pop_front();
            arr.pop_front();
        }
        else
        {
            arr[arr.size() - 3] = b;
            arr.pop_back();
            arr.pop_back();
        }
    }

    cout << arr.front() << '\n';
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