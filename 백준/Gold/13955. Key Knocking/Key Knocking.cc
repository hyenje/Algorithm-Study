#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 1000100;

char s[MAX];

int countGroups(vector<int>& a) {
  int ans = 0;
  for (int i = 0; i + 1 < (int)a.size(); ++i)
    ans += a[i] ^ a[i+1];
  return ans + 1;
}

int main(void) {
  scanf("%s", s);
  int n = strlen(s) / 3;
  for (int i = 0; i < 3*n; ++i)
    s[i] -= '0';
  
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    vector<int> a = {i == 0 ? 0 : s[3*i-1], s[3*i], s[3*i+1], s[3*i+2]};

    if (countGroups(a) >= 3) continue;

    a[1] ^= 1, a[2] ^= 1;
    if (countGroups(a) >= 3) {
      ans.push_back(3*i);
      s[3*i] ^= 1, s[3*i+1] ^= 1;
      continue;
    }
    a[1] ^= 1, a[2] ^= 1;
    
    a[2] ^= 1, a[3] ^= 1;
    assert(countGroups(a) >= 3);
    ans.push_back(3*i+1);
    s[3*i+1] ^= 1, s[3*i+2] ^= 1;
  }

  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d", ans[i] + 1);
    putchar(i+1 < (int)ans.size() ? ' ' : '\n');
  }
  return 0;
}
