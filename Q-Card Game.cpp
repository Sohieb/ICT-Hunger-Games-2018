#include <iostream> 

using namespace std;

int T, n, k;
int p[1000005];

bool can(long long mxPwr){
  int cnt = 1;
  int lst = 0, mx = 0;
  for(int i = 0; i < n; ++i){
    if((i - lst + 1) * 1LL * max(mx, p[i]) <= mxPwr){
      mx = max(mx, p[i]);
    }else{
      lst = i;
      mx = p[i];
      ++cnt;
    }
  }
  return (cnt <= k);
}

int main(){
  cin >> T;
  while(T--){
    cin >> n >> k;
    int mx = 0;
    for(int i = 0; i < n; ++i){
      cin >> p[i];
      mx = max(mx, p[i]);
    }
    long long l = mx, r = 1000000000000LL, mid;
    while(l < r){
      mid = l + (r - l) / 2;
      if(can(mid))
        r = mid;
      else
        l = mid + 1;
    }
    cout << l << endl;
  }
  return 0;
}