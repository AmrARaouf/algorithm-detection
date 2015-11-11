//Language: GNU C++


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long int lint;

int n;
vector<vector<int> > g;
vector<int> distancia;
vector<lint> numcaminos;

vector<double> memcomputa;

int elegido;

double computa(int u)
{
  if (u==0) return 0;
  double &mem=memcomputa[u];
  if (mem>-1) return mem;
  mem=0;
  vector<int> &ar=g[u];
  for (int i=0;i<int(ar.size());i++) {
    int v=ar[i];
    if (distancia[v]==distancia[u]-1) {
      double ev=computa(v);
      if (elegido==u or elegido==v)
	mem+=(double(numcaminos[v])/numcaminos[u])*(1+ev);
      else
	mem+=(double(numcaminos[v])/numcaminos[u])*ev;
    }
  }
  return mem;
}

int main()
{
  cout.setf(ios::fixed);
  cout.precision(12);
  int m;
  cin>>n>>m;
  g=vector<vector<int> > (n);
  for (int i=0;i<m;i++) {
    int u,v;
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  distancia=vector<int> (n,-1);
  distancia[0]=0;
  numcaminos=vector<lint> (n,0);
  numcaminos[0]=1;
  queue<int> q;
  q.push(0);
  while (not q.empty()) {
    int u=q.front();
    q.pop();
    vector<int> &ar=g[u];
    for (int i=0;i<int(ar.size());i++) {
      int v=ar[i];
      if (distancia[v]==-1) {
	distancia[v]=distancia[u]+1;
	q.push(v);
	numcaminos[v]=numcaminos[u];
      } else if (distancia[v]==distancia[u]+1) {
	numcaminos[v]+=numcaminos[u];
      }
    }
  }
  /*
  for (int i=0;i<n;i++)
    cout<<"("<<distancia[i]<<","<<numcaminos[i]<<"),";
  cout<<endl;
  */
  double maximo=0;
  memcomputa=vector<double> (n);
  for (elegido=0;elegido<n;elegido++) {
    for (int i=0;i<n;i++) memcomputa[i]=-2;
    maximo=max(maximo,computa(n-1));
  }
  cout<<maximo<<endl;
}
