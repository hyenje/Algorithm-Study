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

void solve()
{
    vector<int> answer = {2, 3, 5, 7};
    int n;
    cin >> n;
    for (int m = 0; m < n - 1; m++)
    {
        vector<int> v;
        for (int i = 0; i < answer.size(); i++)
        {
            for (int j = 1; j < 10; j++)
            {
                int val = answer[i] * 10 + j, flag = 0;
                for (int k = 2; k <= (int)sqrt(val); k++)
                {
                    if (val % k == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    v.push_back(val);
            }
        }
        answer = v;
    }
    sort(answer.begin(), answer.end());

    for (auto i : answer)
        cout << i << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */