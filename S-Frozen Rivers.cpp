#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int T, n, q;
vector<pair<int,int> > adj[100005];
long long tim[100005];
vector<long long> leaf;

void init(){
  for(int i = 0; i <= n; ++i)
    adj[i].clear();
  memset(tim, 0, sizeof tim);
  leaf.clear();
}

void dfs(int u, int par = -1, long long t = 0){
  tim[u] = t;
  int mnEdg = 100000;
  for(int i = 0; i < (int)adj[u].size(); ++i){
    if(adj[u][i].second == par) continue;
    mnEdg = min(mnEdg, adj[u][i].first);
  }
  for(int i = 0; i < (int)adj[u].size(); ++i){
    if(adj[u][i].second == par) continue;
    if(adj[u][i].first == mnEdg)
      dfs(adj[u][i].second, u, t + adj[u][i].first);
    else
      dfs(adj[u][i].second, u, t + mnEdg + (adj[u][i].first - mnEdg) * 2LL);
  }
  if((int)adj[u].size() == 1 && u != 1)
    leaf.push_back(u);
}

bool cmp(int a,int b){
  return (tim[a] < tim[b]);
}

int main(){
  scanf("%d", &T);
  while(T--){
    init();
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i){
      int p, c;
      scanf("%d %d", &p, &c);
      adj[i].push_back({c, p});
      adj[p].push_back({c, i});
    }
    dfs(1);
    sort(leaf.begin(), leaf.end(), cmp);
    for(int i = 0; i < (int)leaf.size(); ++i)
      leaf[i] = tim[leaf[i]];
    scanf("%d", &q);
    long long t;
    while(q--){
      scanf("%lld", &t);
      printf("%lld\n", (long long)(upper_bound(leaf.begin(), leaf.end(), t) - leaf.begin()));
    }
  }
  return 0;
}