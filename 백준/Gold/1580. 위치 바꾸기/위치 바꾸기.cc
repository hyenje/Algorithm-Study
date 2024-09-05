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
const int mx[9] = {1, -1, 0, 0, 1, 1, -1, -1, 0};
const int my[9] = {0, 0, -1, 1, 1, -1, 1, -1, 0};
struct node
{
    int a, b, c, d;
    node() {}
    node(int A, int B, int C, int D) : a(A), b(B), c(C), d(D) {}
};

int d[25][25][25][25];
void solve()
{
    int n, m, ax, ay, bx, by;
    int answer = -1;
    string s;
    vector<vector<int>> arr(25, vector<int>(25, 1));

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] != 'X')
                arr[i + 1][j + 1] = 0;

            if (s[j] == 'A')
                ax = i + 1, ay = j + 1;
            if (s[j] == 'B')
                bx = i + 1, by = j + 1;
        }
    }
    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= m + 1; j++)
    //         cout << arr[i][j];
    //     cout << '\n';
    // }
    queue<node> q;
    q.push(node(ax, ay, bx, by));
    memset(d, -1, sizeof(d));
    d[ax][ay][bx][by] = 0;
    while (!q.empty())
    {
        node nd = q.front();
        // cout << nd.a << ' ' << nd.b << ' ' << nd.c << ' ' << nd.d << '\n';
        q.pop();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int nx = nd.a + mx[i], ny = nd.b + my[i];
                int nbx = nd.c + mx[j], nby = nd.d + my[j];
                if (arr[nx][ny] || arr[nbx][nby])
                    continue;
                if (nx == nbx && ny == nby || ~d[nx][ny][nbx][nby])
                    continue;
                if (nx == nd.c && ny == nd.d && nbx == nd.a && nby == nd.b)
                    continue;
                q.push(node(nx, ny, nbx, nby));
                d[nx][ny][nbx][nby] = d[nd.a][nd.b][nd.c][nd.d] + 1;
            }
        }
    }

    cout << d[bx][by][ax][ay] << '\n';
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


        for (int i = 0; i < 22; i++)
        {
            for (int j = 0; j < 22; j++)
            {
                if (nd.va[i] & (1 << j))
                    cout << 'O';
                else
                    cout << '.';
            }
            cout << '\n';
        }

0
XXXXXXXXX
A.......B
XXXX.XXXX
1
XXXXXXXXX
.A.....B.
XXXX.XXXX
2
XXXXXXXXX
..A...B..
XXXX.XXXX
3
XXXXXXXXX
...A.B...
XXXX.XXXX
4
XXXXXXXXX
....B....
XXXXAXXXX
5
XXXXXXXXX
...B.A...
XXXX.XXXX
6
XXXXXXXXX
..B...A..
XXXX.XXXX
7
XXXXXXXXX
.B.....A.
XXXX.XXXX
8
XXXXXXXXX
B.......A
XXXX.XXXX
*/