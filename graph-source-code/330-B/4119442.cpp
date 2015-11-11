//Language: GNU C++


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
//#define LOCAL
#define maxn 1001
#define fin cin
#define fout cout
using namespace std;
int n,m;
int pa[505][2];
int vis[1002];
int main ()
{
#ifdef LOCAL
    ofstream fout ("1.out");
    ifstream fin ("1.in");
#endif

fin>>n>>m;
memset(pa,0,sizeof(pa));
memset(vis,0,sizeof(vis));
int i,j,k,center;

for(i=0;i<m;i++)
{fin>>pa[i][0]>>pa[i][1];
 vis[pa[i][0]]=1;vis[pa[i][1]]=1;

}

for(i=1;i<=n;i++)if(vis[i]!=1)
{	center=i; break;
}

if(center>0)
{
fout<<n-1<<endl;
for(j=1;j<=n;j++)if(j!=center)
fout<<j<<" "<<center<<endl;

}

#ifdef LOCAL
fin.close();
fout.close();
#endif

   return 0;
}
