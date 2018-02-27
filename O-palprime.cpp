#include <algorithm>
#include <iostream>
#include <iterator>
#include <bitset>
#include <set>

using namespace std;

bitset<5000000> isPrime;
set<pair<int, string> > palPrime;

void palindrom(int x){
  int tmp = x;
  string str = "";
  while(x){
    str += char('0' + x % 2);
    x /= 2;
  }
  string rev = str;
  reverse(rev.begin(), rev.end());
  if(str == rev)
    palPrime.insert({tmp, str});
}

void sieve(){
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for(int i = 2; i < 5000000; i = i + 1 + (i & 1)){
    if(isPrime[i] == 0)
      continue;
    palindrom(i);
    for(int j = i + i; j < 5000000; j+=i)
      isPrime[j] = 0;
  }
}

int BinToDec(string s){
  int res = 0;
  reverse(s.begin(), s.end());
  for(int i = 0; i < (int)s.size(); ++i)
    if(s[i] == '1')
      res += (1 << i);
  return res;
}

int main(){
  sieve();
  string str;
  while(cin >> str){
    int dec = BinToDec(str);
    set<pair<int, string> >::iterator it = palPrime.lower_bound({dec, str});
    if(str == it->second)++it;
    cout << it->second << endl;
  }
  return 0;
}