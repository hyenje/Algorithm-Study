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

map<string, string> m;
map<string, int> arr;

string find(string s)
{
    if (m[s] == s)
        return s;
    return m[s] = find(m[s]);
}

int unite(string s1, string s2)
{
    s1 = find(s1);
    s2 = find(s2);

    if (s1 == s2)
        return arr[s1];

    m[s2] = m[s1];
    arr[s1] += arr[s2];

    return arr[s1];
}

void solve()
{
    string s1, s2;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (s1 > s2)
            swap(s1, s2);
        if (m.find(s1) == m.end())
        {
            m[s1] = s1;
            arr[s1] = 1;
        }
        if (m.find(s2) == m.end())
        {
            m[s2] = s2;
            arr[s2] = 1;
        }
        cout << unite(s1, s2) << '\n';
    }
    m.clear();
    arr.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */