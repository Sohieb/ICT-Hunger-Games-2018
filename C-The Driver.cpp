#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    string str;
    cin >> str;
    int fCnt = count(str.begin(), str.end(), 'F');
    if(fCnt == 0 || fCnt == 3 || fCnt == 4 || fCnt == 6 || fCnt == 7 || fCnt == 10)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}