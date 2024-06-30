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

int n;
vector<int> arr(1'000'123);
int count_num(int flag)
{
    int cnt = 0;
    // flag가 1일때 오름 0일때 내림 상태임
    for (int i = 1; i < n; i++)
    {
        if (flag && arr[i] < arr[i - 1])
        {
            cnt++;
            flag = 0;
        }
        else if (!flag && arr[i] > arr[i - 1])
        {
            cnt++;
            flag = 1;
        }
    }

    if (cnt == 0)
        return 1;
    else
        return cnt + 1;
}

void solve()
{
    cin >> n;
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;

    cout << max(count_num(0), count_num(1));
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