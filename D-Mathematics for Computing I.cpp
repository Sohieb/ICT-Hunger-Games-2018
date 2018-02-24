#include <iostream> 

using namespace std;

int main(){
  int n;
  cin >> n;
  int zeros = n / 5 + n / 25 + n / 125 + n / 625;
  cout << zeros << endl;
  return 0;
}