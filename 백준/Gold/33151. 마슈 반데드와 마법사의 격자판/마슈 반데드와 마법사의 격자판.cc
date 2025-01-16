#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define FASTIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define INF 2'147'483'647

vector<vector<int>> arr(1024, vector<int>(1024));
int n, k;

void solve()
{
    int val = n * n / 2, want = 2, value[2] = {n * n / 2, n * n / 2 + 1}, idx = 0, num;
    if (n % 2 == 0)
        value[1] = n * n / 2;

    if (n % 2 && k % 2)
        val = value[++idx];

    if (k < val || (n % 2 == 0 && k % 2))
    {
        cout << -1 << '\n';
        return;
    }

    k -= val, idx++;
    val = value[idx % 2];

    while (k)
    {
        num = k / 2;
        if (num >= val)
            k -= val * 2;
        else
        {
            k -= num * 2;
            if (k)
            {
                cout << -1 << '\n';
                return;
            }
        }

        want++, idx++;
        val = value[idx % 2];
    }
    want--;
    if (idx % 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((i + j) % 2)
                {
                    if (num-- > 0)
                        arr[i][j] = want;
                    else
                        arr[i][j] = want - 2;
                }
                else
                    arr[i][j] = want - 1;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((i + j) % 2)
                    arr[i][j] = want - 1;
                else
                {
                    if (num-- > 0)
                        arr[i][j] = want;
                    else
                        arr[i][j] = want - 2;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    FASTIO;
    cin >> n >> k;

    solve();
    return 0;
}