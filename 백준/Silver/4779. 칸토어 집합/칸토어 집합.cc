/*
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

string ans;
void go(int s, int e)
{
    if (s + 1 >= e)
        return;

    int dif = (e - s) / 3;
    for (int i = s + dif; i < s + (dif << 1); i++)
        ans[i] = ' ';

    go(s, s + dif);
    go(s + (dif << 1), e);
}

void solve(int t)
{
    ans.clear();
    int val = 1;
    while (t--)
        val *= 3;
    for (int i = 0; i < val; i++)
        ans.push_back('-');
    go(0, val);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    while (scanf("%d", &t) != EOF)
        solve(t);

    return 0;
}
/*
 */