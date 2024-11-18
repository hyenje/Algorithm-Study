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
#define ll_INF 1'000'000'000'000'000'000
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 998'244'353
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll num[20] = {}, zero[20] = {};

void solve()
{
    string str;
    ll answer[10] = {}, m = 1, remain = 0, cnt = 0, nv = 0;
    cin >> str;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        ll val = str[i] - '0';
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 && j == 0)
                answer[0] += zero[cnt] + num[cnt] * (val - 1);
            else
                answer[j] += num[cnt] * val;
        }

        for (ll j = 0; j < val; j++)
        {
            if (i == 0 && j == 0)
                continue;
            answer[j] += m;
        }
        answer[val] += nv + 1;

        nv += val * m, cnt++, m *= 10;
    }
    int v;

    for (int k = 0; k < 10; k++)
        cout << answer[k] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll val = 1, remain = 1;
    for (int i = 1; i < 14; i++)
    {
        num[i] = val + num[i - 1] * 10ll;
        zero[i] = num[i] - remain;
        val *= 10ll;
        remain += val;
    }
    // for (int i = 1; i <= 10; i++)
    //     cout << zero[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= 10; i++)
    //     cout << num[i] << ' ';
    // cout << '\n';

    solve();
    return 0;
}
/*
 */