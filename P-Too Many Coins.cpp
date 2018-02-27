#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int T, c, m;
int a[1000005];
int frq[1000005];

int main(){
  cin >> T;
  while(T--){
    cin >> c >> m;
    long long sum = 0;
    memset(frq, 0 ,sizeof frq);
    for(int i = 0; i < c; ++i){
      cin >> a[i];
      sum += a[i];
      frq[a[i]]++;
    }
    if(sum < m){
      cout << "Impossible" << endl;
      continue;
    }
    vector<pair<long long,int> > v;
    for(int i = 1; i < 1000001; ++i)
      if(frq[i])
        v.push_back({i * 1LL * frq[i], i});
    sort(v.rbegin(), v.rend());
    vector<int> res;
    for(int i = 0; i < (int)v.size(); ++i){
      if(m > 0){
        m -= v[i].first;
        res.push_back(v[i].second);
      }
    }
    sort(res.begin(), res.end());
    for(int i = 0; i < (int)res.size(); ++i)
      printf("%d%c", res[i], " \n"[i == (int)res.size() - 1]);
  }
  return 0;
}