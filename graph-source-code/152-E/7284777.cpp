//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int,int> PII;

const int INF = 0x7f7f7f7f;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int n,m,k,cnt;
int cost[110][110],num[110][110],px[10],py[10];
int d[210][1<<7],inq[210][1<<7],pre[210][1<<7][2];
char grid[110][110];
queue<PII> q;

inline int checkmin(int &a,int b){return b<a ? (a=b),1 :0;}
void spfa(){
	for(int i=0;i<k;i++)
		pre[num[px[i]][py[i]]][1<<i][0]=-1,
		pre[num[px[i]][py[i]]][0][0]=-1,
		d[num[px[i]][py[i]]][1<<i]=cost[px[i]][py[i]],
		inq[num[px[i]][py[i]]][1<<i]=1,
		q.push(PII(num[px[i]][py[i]],1<<i));
	while(!q.empty()){
		PII t=q.front();q.pop();inq[t.first][t.second]=0;
		int qx=(t.first-1)/m+1,qy=(t.first-1)%m+1;
		for(int i=0;i<4;i++){
			int tn=num[qx+dx[i]][qy+dy[i]];
			if(!tn || d[tn][0]>=INF) continue;
			if(checkmin(d[tn][t.second],d[t.first][t.second]+d[tn][0])){
				pre[tn][t.second][0]=0,pre[tn][t.second][1]=t.first;
				if(!inq[tn][t.second]) q.push(PII(tn,t.second)),inq[tn][t.second]=1;
			}
		}
		for(int i=0;i<(1<<k);i++) if(d[t.first][i]<INF && !(i&t.second))
			if(checkmin(d[t.first][i|t.second],d[t.first][i]+d[t.first][t.second]-cost[qx][qy])){
				pre[t.first][i|t.second][0]=1;pre[t.first][i|t.second][1]=i;
				if(!inq[t.first][i|t.second]) q.push(PII(t.first,i|t.second)),inq[t.first][i|t.second]=1;
			}
	}
}

void getAns(int pos,int mask){
	grid[(pos-1)/m+1][(pos-1)%m+1]='X';
	if(pre[pos][mask][0]==-1) return;
	if(pre[pos][mask][0]) getAns(pos,pre[pos][mask][1]),getAns(pos,mask^pre[pos][mask][1]);
	else getAns(pre[pos][mask][1],mask);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&cost[i][j]),num[i][j]=++cnt,grid[i][j]='.';
	for(int i=0;i<k;i++) scanf("%d%d",&px[i],&py[i]);
	memset(d,0x7f,sizeof(d));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			d[num[i][j]][0]=cost[i][j];
	spfa();
	int ans=INF,ansx,ansy;
//	for(int i=1;i<=cnt;i++){
//		for(int j=0;j<(1<<k);j++)
//			printf("%d:(%d,%d,%d) : %d %d %d\n",i,(i-1)/m+1,(i-1)%m+1,j,d[i][j],pre[i][j][0],pre[i][j][1]);
//	}
	for(int i=1;i<=cnt;i++) if(checkmin(ans,d[i][(1<<k)-1])) ansx=i,ansy=(1<<k)-1;
	printf("%d\n",ans);
	getAns(ansx,ansy);
	for(int i=1;i<=n;i++) puts(grid[i]+1);
	return 0;
}
