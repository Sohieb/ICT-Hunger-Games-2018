#include <iostream> 
#include <algorithm>

using namespace std;

int T, n, x, y, mnX, mxX, mnY, mxY;

int main(){
  cin >> T;
  while(T--){
    cin >> n;
    mnX = mnY = 1000;
    mxX = mxY = -1000;
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < 4; ++j){
        cin >> x >> y;
        mnX = min(mnX, x);
        mxX = max(mxX, x);
        mnY = min(mnY, y);
        mxY = max(mxY, y);
      }
    cout << ((mxX - mnX) * (mxY - mnY)) << endl;
  }
  return 0;
}