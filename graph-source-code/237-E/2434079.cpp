//Language: GNU C++


//============================================================================
// Name        : code.cpp
// Author      : Vlade087
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string.h>
#include<algorithm>
#include <complex>
#define maxn 100005
#define mod 1073741824
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
using namespace std;
struct Edge
{
  int u , v , cap , next;
  long long  cost;
  Edge(){}
  Edge(int uu , int vv , int capp , long long costt, int nextt){
	  u = uu;
	  v = vv;
	  cap = capp;
	  cost = costt;
	  next = nextt;
  }
}A[500000];
int total,L[30000],n,m,s,r,x,y;
long long cost;
void ADD(int u,int v,int cap,long long cost)
{
  A[total] = Edge(u,v,cap,cost,L[u]);
  L[u] = total++;

  A[total] = Edge(v,u,0,-cost,L[v]);
  L[v] = total++;
}
int Flow[30000],fl;
long long Dist[30000],Phi[30000],Prev[30000];
bool In[30000];
struct Node{
	int u;
	long long peso;
	Node(){}
	Node(int uu , long long peso1){
		u = uu;
		peso = peso1;
	}
	bool operator <(Node const &l)const{
		return peso > l.peso;
	}
};
priority_queue<Node> cola;
bool Dikjstra()
{
   for(int i = 0 ; i <= 2*n ; i++)
   {
	   Flow[i] = 0;
	   In[i] = 0;
	   Dist[i] = 2*(1e9)*(10005);
   }
   cola.push(Node(s,0));
   In[s] = 0;
   Dist[s] = 0;
   Flow[s] = 100;
   while(cola.size()){
	   x = cola.top().u;
	   cost = cola.top().peso;
	   cola.pop();
	   fl = Flow[x];
	   if(In[x]) continue;
	   In[x] = 1;
	   for(int i = L[x] ; i!= -1 ; i = A[i].next)
	   {
		   y = A[i].v;
		   if(A[i].cap >0 && (Dist[y] > cost+A[i].cost+Phi[x]-Phi[y]))
		   {
			   Dist[y] = cost+A[i].cost+Phi[x]-Phi[y];
			   Flow[y] = min(fl,A[i].cap);
			   cola.push( Node(y,Dist[y]) );
			   Prev[y] = i;
		   }
	   }
   }
   return Flow[r]!=0;
}
long long MAX_FLOW_MIN_COST()
{
	long long cost = 0;
	int fl = 0;
   while(Dikjstra())
   {

	   cost += (Dist[r]+Phi[r])*Flow[r];
	   fl+=Flow[r];
	   x = r;
	   for(int i = 0 ; i <= n ; i++)
		   if(Flow[i])
		      Phi[i]+=Dist[i];
	   while(x != s)
	   {
		   A[Prev[x]].cap-=Flow[r];
		   A[Prev[x]^1].cap+=Flow[r];
		   x = A[Prev[x]].u;
	   }
   }
	return cost;
}
int C[1000];
int main()
{
	 for(int i = 0 ; i <= 300 ; i++)
			 L[i] = -1;
	 string cad;
	 cin>>cad;
	 for(int i=0; i < cad.length();i++)
		 C[cad[i]-'a']++;
	 for(int i = 0; i<26;i++)
	 {
		if(C[i]){ ADD(i+105,300,C[i],0);
		 //cout<<i+105<<" "<<300<<" "<<C[i]<<" "<<0<<endl;
		}
	 }
	 int cads,pe;
	 cin>>cads;
	 for(int i=1; i <= cads;i++)
	 {
		 memset(C,0,sizeof(C));
		 cin>>cad>>pe;
		 ADD(0,i,pe,0);
		 //cout<<0<<" "<<i<<" "<<pe<<" "<<0<<endl;
		 for(int j = 0; j < cad.length(); j++)
			 C[cad[j]-'a']++;
		 for(int j = 0; j<26;j++)
		 {
			if(C[j]){ADD(i,j+105,C[j],i);
			//cout<<i<<" "<<j+105<<" "<<C[j]<<" "<<i<<endl;
			}
		 }


	 }
	//scanf("%d%d%d%d",&n,&m,&s,&r);
	 n = 300;
	 s = 0;
	 r = 300;
	 /*while(m--)
	 {

		 ADD(x,y,1,cost);

	 }*/
	 ll res=MAX_FLOW_MIN_COST();
	 for(int i=0;i<total;i++){
		 if(A[i].cap && A[i].v==r)
			 res=-1;
	 }
	 cout<<res;

	 return 0;
}
