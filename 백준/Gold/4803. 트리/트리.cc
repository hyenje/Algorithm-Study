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

ll mst[5000];

int find(int a)
{
    if (mst[a] == a)
        return a;
    return mst[a] = find(mst[a]);
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
    {
        mst[b] = a;
        mst[a] = 0;
    }
    else if (a < b)
        mst[b] = a;
    else
        mst[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r = 1;
    // ll t;
    // cin >> t;
    // while (t--)
    while (1)
    {
        int n, m, a, b;
        set<int> s;
        cin >> n >> m;
        if (n == 0)
            break;
        for (int i = 0; i <= n; i++)
            mst[i] = i;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            unite(a, b);
        }

        for (int i = 1; i <= n; i++)
        {
            int val = find(i);
            if (val > 0)
                s.insert(val);
        }

        // for (auto i : s)
        //     cout << i << ' ';
        // cout << '\n';

        if (s.size() == 0)
            cout << "Case " << r << ": No trees.\n";
        else if (s.size() == 1)
            cout << "Case " << r << ": There is one tree.\n";
        else
            cout << "Case " << r << ": A forest of " << s.size() << " trees.\n";

        r++;
    }

    return 0;
}
/*
 */