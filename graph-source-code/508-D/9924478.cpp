//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
int n;
char chartbl[62];
vector<int> Gl[3900];
int in[3900],out[3900];
int visited[3900];

string t;

int code(char c){
  if('0'<=c && c<='9') return c-'0';
  if('a'<=c && c<='z') return c-'a'+10;
  if('A'<=c && c<='Z') return c-'A'+36;
}

void init(){
  int p = 0;
  for(char c='0';c<='9';++c) chartbl[p++] = c;
  for(char c='a';c<='z';++c) chartbl[p++] = c;
  for(char c='A';c<='Z';++c) chartbl[p++] = c;  
}

int getStart(){
  int startnode = -1;
  for(int i=0;i<62*62;++i){
    out[i] = Gl[i].size();
    for(int j=0;j<(int)Gl[i].size();++j) in[Gl[i][j]]++;
  }
  bool iscycle = true;
  int scnt=0,ecnt=0;
  int tmp = -1;
  for(int i=0;i<62*62;++i){
    if(in[i]!=out[i]) iscycle = false;
    else if(out[i]) tmp = i;
    if(out[i]==in[i]+1){
      ++scnt;
      startnode = i;
    }
    if(in[i]==out[i]+1){
      ++ecnt;
    }
  }

  if(iscycle) return tmp; //オイラー閉路
  if(scnt!=1 || ecnt!=1) return -1;
  return startnode;
}

void output(int node){
  printf("%c%c",chartbl[node/62],chartbl[node%62]);
}

string ans;

void dfs(int node){
  int m = Gl[node].size();
  while(visited[node]<m){
    int tmp = Gl[node][visited[node]++];
    dfs(tmp);
  }
  ans+=chartbl[node%62];
}

int main(){
  init();
  char tmp[5];
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    scanf("%s",tmp);
    int a = code(tmp[0])*62+code(tmp[1]);
    int b = code(tmp[1])*62+code(tmp[2]);
    Gl[a].push_back(b);
  }

  /*
  for(int i=0;i<3900;++i){
    for(int j=0;j<3900;++j){
      for(int k=0;k<G[i][j];++k){
	output(i);printf("-");output(j);printf("\n");
      }
    }
  }
  */
  int s = getStart();
  if(s==-1){ printf("NO\n");}
  else{
    //    ans+=chartbl[s/62];
    //    output(s);printf("\n");
    dfs(s);
    ans+=chartbl[s/62];    
    reverse(ans.begin(),ans.end());
    if(ans.size()==n+2){
      printf("YES\n%s\n",ans.c_str());
    }
    else printf("NO\n");
  }

  return 0;
}
