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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    queue<int> c;
    stack<int> p;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'C')
            c.push(i);
        else
            p.push(i);
    }

    while (k-- && c.size() && p.size())
    {
        int a = c.front(), b = p.top();
        c.pop();
        p.pop();
        if (a > b)
            break;
        swap(s[a], s[b]);
    }

    ll cnt = 0, answer = 0;
    for (auto i : s)
    {
        if (i == 'P')
            cnt++;
        else if (cnt > 1ll)
            answer += cnt * (cnt - 1ll) >> 1ll;
    }

    cout << answer << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */