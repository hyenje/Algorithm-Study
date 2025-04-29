#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
static const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 1) M = 1 특수 처리
    if(M == 1){
        // A가 모두 1이므로 최장 연속 1의 길이는 N
        // 최소 L = N+1, 개수 = 1
        cout << (N + 1) << " " << 1 << "\n";
        return 0;
    }

    // 2) L_max 찾기: M^L > N 인 최소 L
    long long pow64 = 1;
    int Lmax = 0;
    for(int L = 1; ; L++){
        pow64 *= M;
        if(pow64 > N){
            Lmax = L;
            break;
        }
    }

    // 3) 롤링 해시 전처리 (base는 적당한 상수)
    const ull BASE = 91138233;
    vector<ull> h(N+1, 0), p(N+1, 1);
    for(int i = 0; i < N; i++){
        h[i+1] = h[i] * BASE + (unsigned)A[i];
        p[i+1] = p[i] * BASE;
    }

    // 4) 각 L마다 D(L) 구해서 최초로 D(L) < M^L 판정
    long long mPow = 1;  // M^L (64비트)
    for(int L = 1; L <= Lmax; L++){
        mPow = mPow * M;  // 이제 mPow = M^L

        // 모든 길이-L 부분수열 해시를 집합에
        unordered_set<ull> st;
        st.reserve(N - L + 1);
        for(int i = 0; i + L <= N; i++){
            // [i, i+L) 구간 해시
            ull cur = h[i+L] - h[i] * p[L];
            st.insert(cur);
        }
        int distinct = (int)st.size();  // D(L)

        if(distinct < mPow){
            // 정답 L, 개수 = M^L - D(L) (mod)
            long long missing = (mPow - distinct) % MOD;
            if(missing < 0) missing += MOD;
            cout << L << " " << missing << "\n";
            return 0;
        }
    }

    // 이 지점에 도달하는 일은 없습니다.
    return 0;
}
