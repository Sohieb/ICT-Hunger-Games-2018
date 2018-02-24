#include <iostream> 

using namespace std;

int T;
long long a, sum;

int main(){
  cin >> T;
  while(T--){
    cin >> a;
    long long l = 0, r = 1000000000, mid;
    while(l < r){
      mid = l + (r - l + 1) / 2;
      if(mid + mid * mid <= a)
        l = mid;
      else
        r = mid - 1;
    }
    sum += l;
    cout << sum << endl;
  }
  return 0;
}