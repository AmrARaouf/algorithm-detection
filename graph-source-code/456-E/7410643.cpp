//Language: MS C++


#include <stdio.h>
#include <algorithm>
#define NM 300005
#pragma comment (linker,"/STACK:16777216")
//FILE *in=fopen("input.txt","r"),*out=fopen("output.txt","w");
FILE *in=stdin,*out=stdout;
int n,m,Q;
struct LIST{
	int x,y;
	bool operator()(LIST A,LIST B){
		return A.x<B.x;
	}
}list[NM*2];
int indexed[NM],dy[NM],max[NM];
int mom[NM],visit[NM];
int group[NM],G;
void input(){
	fscanf(in,"%d %d %d",&n,&m,&Q);
	for (int i=1;i<=m;i++){
		fscanf(in,"%d %d",&list[i].x,&list[i].y);
		list[i+m].x=list[i].y;
		list[i+m].y=list[i].x;
	}
	std::sort(list+1,list+1+m*2,LIST());
	int pointer=1;
	for (int i=0;;i++){
		if (pointer>n) break;
		if (pointer!=list[i+1].x) indexed[pointer++]=i--;
	}
}
void search(int x){
	dy[x]=1;
	max[x]=1;
	group[x]=G;
	visit[x]=1;
	int max1=0,max2=0;
	for (int i=indexed[x-1]+1;i<=indexed[x];i++){
		if (visit[list[i].y]) continue;
		search(list[i].y);
		dy[x]=dy[x]<dy[list[i].y]+1?dy[list[i].y]+1:dy[x];
		max[G]=max[G]<dy[x]?dy[x]:max[G];
		if (max1<=dy[list[i].y]){
			max2=max1;
			max1=dy[list[i].y];
		}else if (max2<dy[list[i].y]){
			max2=dy[list[i].y];
		}
		if (max1!=0 && max2!=0){
			max[G]=max[G]<max1+max2+1?max1+max2+1:max[G];
		}
	}
}
void make(){
	for (int i=1;i<=n;i++){
		if (visit[i]==1) continue;
		G=i;
		search(i);
	}
}
int Find(int x){
	if (group[x]==group[group[x]]) return group[x];
	group[x]=Find(group[x]);
	return group[x];
}
void pro(){
	make();
	for (int i=1;i<=Q;i++){
		int k;
		fscanf(in,"%d",&k);
		if (k==2){
			int x,y;
			fscanf(in,"%d %d",&x,&y);
			int X=Find(x);
			int Y=Find(y);
			if (X==Y) continue;
			if (max[Y]>max[X]){
				int t;
				t=X,X=Y,Y=t;
			}
			group[Y]=X;
			int t1=max[X]/2+1;
			int t2=max[Y]/2+1;
			max[X]=max[X]<t1+t2?t1+t2:max[X];
		}else{
			int x;
			fscanf(in,"%d",&x);
			int X=Find(x);
			fprintf(out,"%d\n",max[group[X]]-1);
		}
	}
}
int main(){
	input();
	pro();
	return 0;
}