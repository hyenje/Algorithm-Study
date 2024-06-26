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
    string s;
    set<string> name;
    int n, m;

    getline(cin, s, '\n');

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        name.insert(s);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s == "dongho")
            continue;
        name.erase(s);
    }

    if (name.count("dongho"))
        cout << "dongho" << '\n';
    else if (name.count("bumin"))
        cout << "bumin" << '\n';
    else if (name.count("cake"))
        cout << "cake" << '\n';
    else if (name.count("lawyer"))
        cout << "lawyer" << '\n';
    else if (name.size())
        cout << *(name.begin()) << '\n';
    else
        cout << "swi";
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