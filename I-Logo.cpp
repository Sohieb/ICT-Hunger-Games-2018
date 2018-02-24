#include <iostream> 

using namespace std;

void sector(int m){
  cout << "*";
  for(int i = 0; i < m - 2; ++i)
    cout << " ";
  cout << "*";
}

int main(){
  int m;
  cin  >> m;
  for(int i = 0; i < m; ++i){
    if(i == 0){
      sector(m);
      cout << " ";
      for(int j = 0; j < m; ++j)
        cout << "*";
      cout << endl;
    }else if(i == m - 1){
      for(int j = 0; j < m; ++j)
        cout << "*";
      cout << " ";
      sector(m);
      cout << endl;
    }else{
      sector(m);
      cout << " ";
      sector(m);
      cout << endl;
    }
  }
  return 0;
}