#include <iostream>
#include <algorithm>

using namespace std;

int n, a, p, mn, sum;

int main(){
  cin >> n;
  mn = 100;
  for(int i = 0; i < n; ++i){
    cin >> a >> p;
    mn = min(mn, p);
    sum += a * mn;
  }
  cout << sum << endl;
  return 0;
}