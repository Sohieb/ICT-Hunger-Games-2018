#include <iostream>
#include <memory.h>

using namespace std;

int T, cntB[26];
char a[100005], b[100005];

int main(){
  cin >> T;
  while(T--){
    scanf("%s%s", a, b);
    memset(cntB, 0, sizeof cntB);
    for(int i = 0; b[i]; ++i)
      cntB[b[i] - 'a']++;
    int res = 0;
    for(int i = 0; a[i]; ++i)
      if(cntB[a[i] - 'a']){
        cntB[a[i] - 'a']--;
        res++;
      }else break;
    cout << res << endl;
  }
  return 0;
}