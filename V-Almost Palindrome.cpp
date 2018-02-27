#include <iostream>
#include <string.h>

using namespace std;

char str[500005], rev[500005];
int cnt[26], n;

int main(){
  scanf("%s", str);
  n = strlen(str);
  for(int i = 0; str[i]; ++i)
    cnt[str[i] - 'a']++,
    rev[i] = str[n - i - 1];
  int odd = 0, bad = 0;
  for(int i = 0; i < 26; ++i)
    odd += cnt[i] % 2;
  if(odd > 1)
    return cout << "NO\n", 0;
  for(int i = 0; str[i]; ++i)
    bad += str[i] != rev[i];
  if( bad / 2 > 2)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}