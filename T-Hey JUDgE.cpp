#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int T;
string s;
int arr[6];

int main(){
  cin >>T;
  while(T--){
    cin >> s;
    memset(arr, 0, sizeof arr);
    for(int i = 0; i < 7; ++i){
      if(arr[s[i] - 'A' + 1] == 0){
        arr[s[i] - 'A' + 1] = 1;
        s[i] = 'Z';
      }
    }
    sort(s.begin(), s.end());
    for(int i = 1; i < 6; ++i){
      if(arr[i])
        continue;
      for(int j = 0; j < 7 && !arr[i]; ++j)
        for(int k = j + 1; k < 7 && !arr[i]; ++k)
          if(s[j] - 'A' + 1 + s[k] - 'A' + 1 == i){
            arr[i] = 1;
            s[j] = s[k] = 'Z';
          }
      for(int j = 0; j < 7 && !arr[i]; ++j)
        for(int k = j + 1; k < 7 && !arr[i]; ++k)
          for(int w = k + 1; w < 7 && !arr[i]; ++w)
            if(s[j] + s[k] + s[w] - 'A' - 'A' - 'A' + 3 == i){
              arr[i] = 1;
              s[j] = s[k] = s[w] = 'Z';
            }
    }
    if(count(arr + 1, arr + 6, 1) == 5)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}