#include <iostream>
#include <algorithm>

using namespace std;

int T, n;
int a[111];

int popCnt(int x){
  int ones = 0;
  while(x){
    ones += x % 2;
    x /= 2;
  }
  return ones;
}

int main(){
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; ++i)
      for(int j = i + 1; j < n; ++j){
        ans = max(ans, popCnt(a[i] ^ a[j]));
      }
    cout << ans << endl;
  }
  return 0;
}