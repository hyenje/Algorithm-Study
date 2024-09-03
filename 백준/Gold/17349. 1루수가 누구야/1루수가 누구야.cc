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

int arr[10][2];

void solve()
{

    int a, b, ans = -1;

    for (int i = 1; i < 10; i++)
        cin >> arr[i][0] >> arr[i][1];

    for (int i = 1; i < 10; i++)
    {
        int visited[10][2] = {}, answer = 0, flag = 0;
        for (int j = 1; j < 10; j++)
        {
            if (j == i)
                visited[arr[j][1]][!arr[j][0]]++;
            else
                visited[arr[j][1]][arr[j][0]]++;
        }

        for (int j = 1; j < 10; j++)
        {
            if (visited[j][1] && visited[j][0])
                flag = 1;
            else if (visited[j][1] && visited[j][0] == 0)
            {
                if (answer)
                    flag = 1;
                else
                    answer = j;
            }
        }
        if (flag)
            continue;

        int cnt = 0, f = 0;
        for (int j = 0; j < 10; j++)
        {
            if (visited[j][0] >= 1 && visited[j][1] == 0)
                cnt++;
            else if (visited[j][0] == 0 && visited[j][1] >= 1)
                f = 1;
        }
        // cout << cnt << '\n';
        if (cnt == 8)
        {
            for (int j = 1; j < 10; j++)
            {
                if (visited[j][0] == 0 && answer == 0)
                    answer = j;
            }
        }
        else if (cnt <= 7 && f == 0)
        {
            cout << -1 << '\n';
            return;
        }

        if (flag == 0 && answer)
        {
            if (ans > 0)
            {
                cout << -1 << '\n';
                return;
            }
            ans = answer;
        }
        // cout << '\n';
        // for (int j = 1; j < 10; j++)
        //     cout << visited[j][0] << ' ' << visited[j][1] << '\n';
        // cout << flag << ' ' << ans << '\n';
    }

    cout << ans << '\n';
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