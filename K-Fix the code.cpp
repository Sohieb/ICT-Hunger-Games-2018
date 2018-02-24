#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

string str;
int memo[455][455];

int cost(int i, int j){
  if(str[i] == '(' && str[j] == ')') return 0;
  if(str[i] == '[' && str[j] == ']') return 0;
  if(str[i] == '(' || str[i] == '[') return 1;
  if(str[j] == ')' || str[j] == ']') return 1;
  return 2;
}

int solve(int i, int j){
  if(i == j) return 444444; // value for INF
  if(i > j) return 0;
  int &ret = memo[i][j];
  if(~ret) return ret;
  ret = solve(i + 1, j - 1) + cost(i, j);
  for(int k = i; k < j; ++k)
    ret = min(ret, solve(i, k) + solve(k + 1, j));
  return ret;
}

vector<pair<int, char> > getChange(int i, int j){
  vector<pair<int, char> > v;
  if(str[i] == '(')
    v.push_back({j, ')'});
  else if(str[i] == '[')
    v.push_back({j, ']'});
  else if(str[j] == ')')
    v.push_back({i, '('});
  else if(str[j] == ']')
    v.push_back({i, '['});
  else{
    v.push_back({i, '('});
    v.push_back({j, ')'});
  }
  return v;
}

void printOperatoins(int i, int j){
  if( i >= j) return;
  int &ret = memo[i][j];
  if(ret == solve(i + 1, j - 1) + cost(i, j)){
    if(cost(i, j) > 0){
      vector<pair<int, char> > v = getChange(i, j);
      for(int k = 0; k < (int)v.size(); ++k)
        printf("%d %c\n", v[k].first + 1, v[k].second);
    }
    printOperatoins(i + 1, j - 1);
    return;
  }
  for(int k = i; k < j; ++k){
    if(ret == solve(i, k) + solve(k + 1, j)){
      printOperatoins(i, k);
      printOperatoins(k + 1, j);
      return;
    }
  }
}

int main(){
  cin >> str;
  memset(memo, -1, sizeof memo);
  int res = solve(0, (int)str.size() - 1);
  if(res > 444)
    printf("-1\n");
  else{
    printf("%d\n", res);
    printOperatoins(0, (int)str.size() - 1);
  }
  return 0;
}