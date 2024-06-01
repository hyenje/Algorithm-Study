#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define F first
#define S second
#define INF 2'147'483'647
#define INF -2'147'483'648

int mx[9] = {1, -1, 0, 0, 1, 1, -1, -1};
int my[9] = {0, 0, 1, -1, 1, -1, 1, -1};

char arr[1000][1000];
char sen[6] = "MOBIS";
int answer = 0;

void go(int x, int y, int num, int mode)
{
    if (sen[num] != arr[x][y])
        return;

    if (num == 4 && sen[num] == arr[x][y])
    {
        answer++;
        return;
    }

    go(x + mx[mode], y + my[mode], num + 1, mode);
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                go(i, j, 0, k);
            }
        }
    }
    cout << answer << '\n';
}

int main()
{

    solve();
    return 0;
}

/*
 */