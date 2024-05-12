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

vector<int> arr(100'123);
string answer;

// 0.5, 1.5, 2.5, 3.5, 4.5

void solve()
{
    int n, t = 0, idx = 0, flag = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        t += arr[i];
    }

    //  0일때 R, 1일때 L
    while (t--)
    {
        if (flag == 0 && arr[idx] >= 1 && arr[idx + 1] == 0)
            flag = 1;
        else if (arr[idx + 1] && arr[idx] <= 1) // flag == 1
            flag = 0;

        if (flag)
        {
            cout << 'L';
            arr[idx]--;
            idx--;
        }
        else
        {
            cout << 'R';
            idx++;
            arr[idx]--;
        }
        // cout << ' ' << idx << ' ' << flag << ' ';
    }
    // for (int i = 0; i <= n + 1; i++)
    // {
    //     cout << arr[i] << ' ';
    // }
    // cout << "\n";
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
농부 Nhoj는 어디에도 없는 곳에 Bessie를 내려놓았습니다! t=0 일 때, Bessie는 무한한 수의 선상에서 x=0에 위치해 있습니다.
 그녀는 매 초마다 왼쪽이나 오른쪽으로 1단위씩 이동하여 출구를 절박하게 찾습니다. 그러나 실제로는 출구가 없고 T초 후에 Bessie는 x=0으로 돌아와 피곤하고 포기한 상태입니다.

농부 Nhoj는 Bessie를 추적하려고 하지만 Bessie가 x=.5, 1.5, 2.5, ... (N-1).5를 몇 번이나 가로지르는지만을 알고 있습니다.
 이는 배열 A0, A1, ..., AN−1에 의해 주어지며 (1≤N≤105, 1≤Ai≤106, ∑Ai≤106), T초 후에 Bessie가 x>N 또는 x<0에 도달하지 않음을 보장합니다.

특히, Bessie의 경로는 T=∑i=0N−1Ai개의 L과 R로 표현될 수 있으며, 여기서 i번째 문자는 i번째 초에 Bessie가 이동하는 방향을 나타냅니다.
 방향 전환의 수는 LR과 RL의 발생 수에 정의됩니다.

농부 Nhoj가 A와 일치하고 방향 전환의 수를 최소화하는 Bessie의 가능한 경로를 찾도록 도와주세요.
 적어도 하나의 유효한 경로가 있는 것이 보장됩니다.

입력
첫 번째 줄에는 N이 주어집니다. 두 번째 줄에는 A0,A1,...,AN−1이 주어집니다.

출력
T=∑i=0N−1Ai의 길이를 가진 문자열 S를 출력합니다. 여기서 Si는 L 또는 R이며, i번째 초에 Bessie가 이동하는 방향을 나타냅니다.
 방향 전환의 수를 최소화하는 여러 경로가 있는 경우, 아무 경로나 출력합니다.
 */