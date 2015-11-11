//Language: GNU C++0x


#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <ctime>
#include <map>
#include <queue>
#include <stack>

#define Ari using
#define ganteng namespace
#define banget std

#define ll long long
#define ul unsigned long long
#define pb push_back
#define mp make_pair
#define lcm(a,b) a*b/__gcd(a,b)
#define lsb(a) (a & (-a))

#define STRtoINT(a,b) istringstream(a)>>b
#define INTtoSTR(a,b) b=static_cast<ostringstream*>(&(ostringstream()<<a))->str()

//set -> pair <set<int>::iterator,bool> pa; pa=set.insert(x); pa.second return bool;

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

Ari ganteng banget;

int main()
{	
	bool g=true;
	int vertex=getnum<int>();
	int edge=getnum<int>();
	
	pair<int,int>arr[100005];
	int cek[100005];
	
	for(int x=0;x<vertex;x++)
	{
		arr[x].first=getnum<int>();
		arr[x].second=x+1;	
		cek[x]=arr[x].first;
	}
	sort(cek,cek+vertex);
	sort(arr,arr+vertex);
	
	int ed=0;
	vector<pair<int,int> >ans;
	if(arr[0].first!=0)g=false;
	bool visited[100005];
	memset(visited,false,sizeof visited);
	int sisa[100005];
	for(int x=0;x<vertex;x++)sisa[x]=edge;
	if(arr[1].first==0)g=false;
	int atas=lower_bound(cek,cek+vertex,1)-cek;
	visited[0]=true;
	for(int x=0;x<vertex;x++)
	{
		if(!visited[x])g=false;
		while(sisa[x])
		{
			if(atas>=vertex)break;
			if(arr[atas].first==arr[x].first+1)
			{
				ed++;
				ans.pb(mp(arr[x].second,arr[atas].second));
				sisa[x]--; sisa[atas]--;
				visited[atas]=true;
				atas++;
			}
			else break;
		}
	}

	if(!g)printf("-1\n");
	else
	{
		printf("%d\n",ed);
		for(int x=0;x<ans.size();x++)
		{
			printf("%d %d\n",ans[x].first,ans[x].second);
		}
	}
	
  return 0;
}

