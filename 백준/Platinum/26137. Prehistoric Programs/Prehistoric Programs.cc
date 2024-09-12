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
    int n, l_cnt = 0, r_cnt = 0;
    string s;
    cin >> n;
    vector<pair<pair<int, int>, int>> l, r, l_answer, r_answer;
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0;
        cin >> s;
        for (auto j : s)
        {
            if (j == '(')
                left++;
            else if (j == ')' && left)
                left--;
            else
                right++;
        }
        if (right == 0)
        {
            l_answer.push_back({{right, left}, i + 1});
            l_cnt += left;
        }
        else if (left == 0)
        {
            r_answer.push_back({{left, right}, i + 1});
            r_cnt += right;
        }
        else if (left >= right)
            l.push_back({{right, left}, i + 1});
        else
            r.push_back({{left, right}, i + 1});
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int flag = 0;
    for (auto i : l)
    {
        auto right = i.F.F, left = i.F.S, node = i.S;
        if (right > l_cnt)
            flag = 1;
        l_answer.push_back(i);
        l_cnt += -right + left;
    }
    for (auto i : r)
    {
        auto right = i.F.S, left = i.F.F, node = i.S;
        if (left > r_cnt)
            flag = 1;
        r_answer.push_back(i);
        r_cnt += right - left;
    }
    if (flag || l_cnt != r_cnt || l_answer[0].F.F != 0 || (r_answer.size() && r_answer[0].F.F != 0))
        cout << "impossible\n";
    else
    {
        for (int i = 0; i < l_answer.size(); i++)
            cout << l_answer[i].S << '\n';
        for (int i = r_answer.size() - 1; i >= 0; i--)
            cout << r_answer[i].S << '\n';
    }
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