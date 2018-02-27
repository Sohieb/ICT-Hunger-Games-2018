#include <iostream>
#include <algorithm>

using namespace std;

int T, x, y;

int main(){
  cin >> T;
  while(T--){
    cin >> x >> y;
    cout << (max(x, y) * max(x, y)) << endl;
  }
  return 0;
}