#include <iostream> 

using namespace std;

int cntDivs(int x){
  int cnt = 0;
  for(int i = 1; i <= x; ++i)
    if(x % i == 0)
      cnt++;
  return cnt;
}

int main(){
  int x;
  cin >> x;
  if(cntDivs(x) == 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}