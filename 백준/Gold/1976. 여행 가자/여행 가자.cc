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

int arr[222][222];
int uni[200];

int find(int a)
{
    if (uni[a] == a)
        return a;
    return uni[a] = find(uni[a]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    uni[a] = b;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        uni[i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j])
                unite(i, j);
        }
    }

    int a, b = 0;
    cin >> a;
    for (int i = 0; i < m - 1; i++)
    {
        cin >> b;
        if (find(a) != find(b))
        {
            cout << "NO\n";
            return;
        }
        a = b;
    }
    cout << "YES\n";
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