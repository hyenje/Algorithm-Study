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

struct node
{
    node() {}
    map<string, node *> child;
    string s;
};

void go(node *nd, int cnt)
{
    for (auto i : nd->child)
    {
        for (int i = 0; i < cnt; i++)
            cout << "--";
        cout << i.F << '\n';
        go(i.S, cnt + 1);
    }
}

void solve()
{
    node root, *tmp;
    int n, val;
    string a, s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        tmp = &root;
        cin >> val;
        for (int j = 0; j < val; j++)
        {
            cin >> a;
            if (tmp->child.count(a) == 0)
                tmp->child[a] = new node();
            tmp = tmp->child[a];
        }
    }
    go(&root, 0);
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