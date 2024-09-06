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
    ll answer = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        ll cnt = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (i - j < 0 || i + j + 1 >= s.size() || s[i - j] == s[i + j + 1])
                break;

            if (s[i - j] == ')')
                cnt++;
            else
            {
                if (cnt > 0)
                {
                    cnt--;
                    if (cnt == 0)
                        answer++;
                }
                else
                    answer++;
            }
        }
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