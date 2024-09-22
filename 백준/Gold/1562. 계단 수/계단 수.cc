#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <deque>
#include <functional>
#include <cmath>
#include <set>
using namespace std;
#define ll long long int
#define L_INF 1'123'123'123'123'123'123
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 1'000'000'000
const int mx[5] = {1, -1, 0, 0};
const int my[5] = {0, 0, -1, 1};

int arr[100][10][1025];

int main()
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, answer = 0;
    cin >> n;

    for (int i = 1; i < 10; i++)
        arr[0][i][1 << i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                for (int k = 1; k < 1024; k++)
                    arr[i][j][k | (1 << j)] = (arr[i][j][k | (1 << j)] + arr[i - 1][j + 1][k]) % MOD;
            else if (j == 9)
                for (int k = 1; k < 1024; k++)
                    arr[i][j][k | (1 << j)] = (arr[i][j][k | (1 << j)] + arr[i - 1][j - 1][k]) % MOD;
            else
                for (int k = 1; k < 1024; k++)
                    arr[i][j][k | (1 << j)] = (arr[i][j][k | (1 << j)] + arr[i - 1][j - 1][k] + arr[i - 1][j + 1][k]) % MOD;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        answer = (answer + arr[n - 1][i][1023]) % MOD;
    }

    cout << answer << '\n';

    return 0;
}
/*
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N이면서 0부터 9까지 숫자가 모두 등장하는
 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. 0으로 시작하는 수는 계단수가 아니다.
*/