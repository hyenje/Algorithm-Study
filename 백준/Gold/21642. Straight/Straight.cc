#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n;               // 카드 최대값 (1 ≤ n ≤ 1e9)
    int m, s;              // m: 커뮤니티 / 스트레이트 길이, s: 홀카드 수
    if (!(cin >> n >> m >> s)) return 0;

    vector<int64> raw(m);
    for (int i = 0; i < m; ++i) cin >> raw[i];

    /* ① 값 중복 제거 (한 값이 여러 장 있어도 “존재 여부”만 중요) */
    sort(raw.begin(), raw.end());
    raw.erase(unique(raw.begin(), raw.end()), raw.end());
    int k = raw.size();                    // k ≤ m ≤ 1e5

    const int need = m - s;                // 최소로 맞춰야 하는 값 개수
    const int64 N = n - m + 1;             // 시작점 i 의 전체 범위 [1, N]

    if (need <= 0) {                       // s ≥ m 인 경우는 없지만, 안전용
        cout << max<int64>(0, N) << '\n';
        return 0;
    }

    /* ② 각 값 v 가 영향을 주는 [L, R] 범위에 차등(+1 / -1) 이벤트 등록 */
    vector<pair<int64, int>> ev;           // {position, delta}
    ev.reserve(2 * k);

    for (int64 v : raw) {
        int64 L = max<int64>(1, v - m + 1);  // i 가 최소한 여기부터
        int64 R = min<int64>(v, N);          // …여기까지 영향을 받음
        if (L > R) continue;                 // (v 가 너무 작거나 커서 영향 無)

        ev.emplace_back(L, +1);
        if (R + 1 <= N) ev.emplace_back(R + 1, -1);  // 구간 끝 다음 지점에 -1
    }

    sort(ev.begin(), ev.end());             // O(k log k)

    /* ③ 스윕하면서 현재 ‘맞은 값 개수’ 유지, 길이 합산 */
    int64 curPos = 1;       // 지금 보고 있는 i
    int curCnt = 0;         // 현재 구간에 포함된 커뮤니티 값 개수
    int64 ans = 0;

    size_t idx = 0;
    while (idx < ev.size()) {
        int64 nextPos = ev[idx].first;

        if (curPos <= nextPos - 1 && curPos <= N) {
            int64 segEnd = min<int64>(nextPos - 1, N);
            if (curCnt >= need) ans += segEnd - curPos + 1;
        }

        /* 같은 위치 이벤트 모두 반영 */
        while (idx < ev.size() && ev[idx].first == nextPos) {
            curCnt += ev[idx].second;
            ++idx;
        }
        curPos = nextPos;
        if (curPos > N) break;              // 이미 범위 밖
    }

    /* ④ 마지막 이벤트 이후 꼬리 구간 처리 */
    if (curPos <= N && curCnt >= need) ans += N - curPos + 1;

    cout << ans << '\n';
    return 0;
}
