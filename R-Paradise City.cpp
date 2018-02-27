#include <iostream> 

using namespace std;

int T, n;
string arr[3];

int main(){
  cin >> T;
  while(T--){
    cin >> n;
    cin >> arr[0] >> arr[1] >> arr[2];
    int res = 0;
    for(int i = 0; i < 3 * n; i += 3){
      int cnt = 0;
      
      cnt += (arr[0][i] == '*');
      cnt += (arr[0][i + 1] == '*');
      cnt += (arr[0][i + 2] == '*');

      cnt += (arr[1][i] == '*');
      cnt += (arr[1][i + 2] == '*');

      cnt += (arr[2][i] == '*');
      cnt += (arr[2][i + 1] == '*');
      cnt += (arr[2][i + 2] == '*');

      res = max(res, cnt);
    }
    cout << (res * 4) << endl;
  }
  return 0;
}