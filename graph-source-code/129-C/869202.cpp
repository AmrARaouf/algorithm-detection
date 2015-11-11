//Language: GNU C++


#include<stdio.h>
#include<stdlib.h>

#include<string.h>

struct node
{
	int x,y,step;
	node (int x1,int y1,int step1)
	{
		x=x1;y=y1;step=step1;
	}
	node (){}
}q[100000];

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};

int visit[10][10][100];
int v[10][10][100];
void deal(int x,int y)
{
	int i;

	for(i=1;i<=8-x+1;i++)
	{
       v[i+x-1][y][i]=0;
	   v[i+x][y][i]=0;
	}
}


int BFS()
{
	int i,head,tail,x,y,x1,y1,t;

	memset(visit,0,sizeof(visit));
	q[1]=node(8,1,0);
	visit[8][1][0]=1;

	head=0;tail=1;

	while(head<tail)
	{

		head++;
		t=q[head].step+1;
		x=q[head].x;
		y=q[head].y;
        if(t>=100) break;
		for(i=0;i<8;i++)
		{
			x1=x+dx[i];
			y1=y+dy[i];

			//printf("x1=%d  y1=%d\n",x1,y1);getchar();
			if(1<=x1 && x1<=8 && 1<=y1 && y1<=8 && v[x1][y1][t] &&!visit[x1][y1][t])
			{
				q[++tail]=node(x1,y1,t);
				visit[x1][y1][t]=1;
				if(x1==1 && y1==8) return 1;
			}
		}
		if(!visit[x][y][t] && v[x][y][t])
		{
			q[++tail]=node(x,y,t);
		    visit[x][y][t]=1;
		}
	}

    return -1;
}

int main()
{
    char s[10];
	int i,j,ans;


	memset(v,1,sizeof(v));
	for(i=1;i<=8;i++)
	{
		scanf("%s",s);

		for(j=0;j<8;j++)
		{
			if(s[j]=='S')
			{
				deal(i,j+1);
			}
		}
	}


//	system("pause");
	ans=BFS();

	if(ans==-1) printf("LOSE\n");
	else printf("WIN\n");

	return 0;
}