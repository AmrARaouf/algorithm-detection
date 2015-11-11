//Language: GNU C++


#include <cstdio>
int N,M,K,x,y,a[305];
bool b[305],c[305][305];
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for (int i=1; i<=K; i++) scanf("%d",&a[i]),b[a[i]]=1;
	if (K==N||M>N*(N-1)/2-K+1) {puts("-1"); return 0;}
	x=a[1],y=1+(x==1);
	for (int i=y+1; i<=N; i++) if (i!=x) y+=y==x,c[y][i]=c[i][y]=1,M--,printf("%d %d\n",y,i),y++;
	for (int i=1; M&&i<=N; i++) if (!b[i]) c[x][i]=c[i][x]=1,M--,printf("%d %d\n",x,i);
	for (int i=1; M&&i<=N; i++) if (i!=x)
		for (int j=i+1; M&&j<=N; j++) if (j!=x&&!c[i][j]) c[i][j]=c[j][i]=1,M--,printf("%d %d\n",i,j);
}
 		   	  			 				  		 		  	