//Language: GNU C++


#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 210
#define db double
#define mk(x,y) make_pair(x,y)
#define fi first
#define se second
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,x,y,z,num;
int f[N][N],d[N][N];
pair<int,int> a[N];
inline db work(int x,int y) {
	int i;
	For(i,1,n) a[i]=mk(f[x][i],f[y][i]);
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	pair<int,int> c=a[1];
	db len=a[1].fi;
	For(i,2,n) if (a[i].fi<c.fi&&a[i].se>c.se) {
		len=min(len,0.5*(a[i].fi+c.se+d[x][y]));
		c=a[i];
	}
	len=min(len,0.+c.se);
	return len;
}
int main() {
	scanf("%d%d",&n,&m);
	memset(f,60,sizeof(f));
	For(i,1,n) f[i][i]=0;
	For(i,1,m) scanf("%d%d%d",&x,&y,&z),f[x][y]=f[y][x]=d[x][y]=d[y][x]=z;
	For(k,1,n)For(i,1,n)For(j,1,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	db mi=1e15;
	For(i,1,n)For(j,1,n) if (d[i][j]) mi=min(mi,work(i,j));
	printf("%.12lf\n",mi);
	return 0;
}
