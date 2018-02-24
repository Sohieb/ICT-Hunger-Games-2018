#include <iostream> 

using namespace std;

int main(){
  string str;
  cin >> str;
  if(str.find("game") != -1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}