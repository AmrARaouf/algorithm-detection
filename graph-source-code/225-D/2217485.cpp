//Language: GNU C++


#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define REP(i,x)for(int i=0;i<(int)x;i++)
int H,W,k;
string MAP[15];
struct Snake{
	int y,x;
	int back;
};
int dx[4]={-1,0,1,0},
	dy[4]={0,1,0,-1};
int cost[15][15][65536];
int dfs(int y,int x,int t){
	REP(k,4){
		int ny=y+dy[k],nx=x+dx[k];
		if(ny>=0&&ny<H&&nx>=0&&nx<W){
			if(MAP[ny][nx] == t + 1 + '0'){
				return dfs(ny,nx,t+1)*4+(2^k);
			}
		}
	}
	return 0;
}
int main() {
	cin>>H>>W;
	REP(i,H){
		cin>>MAP[i];
	}
	REP(i,H){
		REP(j,W){
			if(isdigit(MAP[i][j])){
				k=max(k,MAP[i][j]-'0');
			}
		}
	}
	Snake init;
	REP(i,H){
		REP(j,W){
			if(MAP[i][j]=='1'){
				init.y=i;
				init.x=j;
				init.back=dfs(i,j,1);
			}
		}
	}
	memset(cost,-1,sizeof(cost));
	cost[init.y][init.x][init.back]=0;
	queue<Snake> que;
	que.push(init);
	int mask=(1<<(2*(k-1)))-1;
	while(!que.empty()){
		Snake now=que.front();que.pop();
		int cst=cost[now.y][now.x][now.back];
		if(MAP[now.y][now.x]=='@'){
			cout<<cst<<endl;
			return 0;
		}
		REP(d,4){
			int nx=now.x+dx[d],ny=now.y+dy[d];
			if(ny>=0&&ny<H&&nx>=0&&nx<W){
				if(MAP[ny][nx] == '#')continue;
				Snake next={ny,nx,((now.back<<2)+d)&mask};
				if(cost[next.y][next.x][next.back]==-1){
					bool ok=true;
					int tx=next.x,ty=next.y,tb=next.back;
					//cout<<tx<<","<<ty<<endl;
					for(int i=0;i<k - 1;i++){
						tx-=dx[tb&3];ty-=dy[tb&3];
						//cout<<tx<<","<<ty<<endl;
						if(tx==next.x&&ty==next.y){
							ok=false;
							break;
						}
						tb >>= 2;
					}
					if(ok){
						que.push(next);
						cost[next.y][next.x][next.back]=cst+1;
					}else{
						cost[next.y][next.x][next.back]=-2;
					}
				}
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
