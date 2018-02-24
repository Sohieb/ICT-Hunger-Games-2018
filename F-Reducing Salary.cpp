#include <iostream> 

using namespace std;

long long y;

long long getSum(long long x){
  long long sum = 0;
  while(x){
    sum += x;
    x /= 10;
  }
  return sum;
}

int main(){
  cin >> y;
  long long l = 1, r = 1000000000000000000LL, mid;
  while(l < r){
    mid = l + (r - l + 1) / 2;
    if(getSum(mid) <= y)
      l = mid;
    else
      r = mid - 1;
  }
  if(getSum(l) == y)
    cout << l << endl;
  else
    cout << -1 << endl;
  return 0;
}
