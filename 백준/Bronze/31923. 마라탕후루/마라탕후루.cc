#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define F first
#define S second
#define INF 2'147'483'647
#define INF -2'147'483'648

vector<vector<ll>> arr(1000, vector<ll>(2, 0));
vector<ll> answer(1000);

void solve()
{
    int n, st, sh, cnt = 0, flag = 0;
    cin >> n >> st >> sh;
    answer.resize(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i][0];
    for (int i = 0; i < n; i++)
        cin >> arr[i][1];

    for (int i = 0; i < n; i++)
    {
        while (arr[i][0] != arr[i][1])
        {
            arr[i][0] += st;
            arr[i][1] += sh;
            answer[i]++;
            cnt++;
            if (cnt > 10000)
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (auto i : answer)
            cout << i << ' ';
    }
}

int main()
{

    solve();
    return 0;
}

/*
첫 번째 줄에 탕후루 꼬치의 개수
$N$, 로봇이
$1$분마다 꽂는 딸기의 개수
$P$, 샤인머스캣의 개수
$Q$가 공백으로 구분되어 주어진다.
$(1\leq N, P, Q \leq 100)$ 

두 번째 줄에 꼬치마다 꽂혀있는 딸기의 개수
$A_{1}, A_{2}, \ldots, A_{N}$이 공백으로 구분되어 주어진다.
$(1\leq A_{i} \leq 100)$ 

세 번째 줄에 꼬치마다 꽂혀있는 샤인머스캣의 개수
$B_{1}, B_{2}, \ldots, B_{N}$이 공백으로 구분되어 주어진다.
$(1\leq B_{i} \leq 100)$ 

입력으로 주어지는 모든 수는 정수이다.
*/