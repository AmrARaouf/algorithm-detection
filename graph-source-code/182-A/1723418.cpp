//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cmath>
const int N = 1005;
#define x1 X1
#define y1 Y1
#define x2 X2
#define y2 Y2
double g[N][N],d[N];
double X1[N],Y1[N],X2[N],Y2[N];
double a,b;
bool u[N];
int tp[N];
void dij(int n)
{
	int i,j,p;
	memset(u,false,sizeof(u));
	for(i=1;i<=n+1;i++)d[i]=g[0][i];
	d[0]=0;
	u[0]=true;
	for(i=1;i<=n+1;i++)
	{
		double temp=1e9;
		for(j=1;j<=n+1;j++)
		{
			if(!u[j]&&d[j]<temp)
			{
				temp=d[j];
				p=j;
			}
		}
		if(temp==1e9)break;
		u[p]=true;
		for(j=1;j<=n+1;j++)
		{
			if(!u[j]&&d[j]>d[p]+g[p][j])
			{
				d[j]=d[p]+g[p][j];
			}
		}
	}
}
void swap(double &x,double &y)
{
	double temp=x;
	x=y;
	y=temp;
}
double st(int e,int sx,int sy)
{
	double temp;
	if(tp[e]==0)
	{
		if(sy<=y2[e]&&sy>=y1[e])
		{
			temp=(sx-x1[e])*(sx-x1[e]);
		}
		else
		{
			if(sy>y2[e])
			{
				//puts("here");
				temp=(sx-x1[e])*(sx-x1[e])+(sy-y2[e])*(sy-y2[e]);
			}
			else
			{
				temp=(sx-x1[e])*(sx-x1[e])+(sy-y1[e])*(sy-y1[e]);
			}
		}
	}
	else
	{
		if(sx<=x2[e]&&sx>=x1[e])
		{
			temp=(sy-y1[e])*(sy-y1[e]);
		}
		else
		{
			if(sx>x2[e])
			{
				temp=(sy-y1[e])*(sy-y1[e])+(sx-x2[e])*(sx-x2[e]);
			}
			else
			{
				temp=(sy-y1[e])*(sy-y1[e])+(sx-x1[e])*(sx-x1[e]);
			}
		}
	}
	//printf("e:%d tp:%d temp:%lf \n",e,tp[e],temp);
	if(temp<=a*a)return a+b;
	else return 1e9;
}
double end(int e,int sx,int sy)
{
	double temp;
	if(tp[e]==0)
	{
		if(sy<=y2[e]&&sy>=y1[e])
		{
			temp=(sx-x1[e])*(sx-x1[e]);
		}
		else
		{
			if(sy>y2[e])
			{
				temp=(sx-x1[e])*(sx-x1[e])+(sy-y2[e])*(sy-y2[e]);
			}
			else
			{
				temp=(sx-x1[e])*(sx-x1[e])+(sy-y1[e])*(sy-y1[e]);
			}
		}
	}
	else
	{
		if(sx<=x2[e]&&sx>=x1[e])
		{
			temp=(sy-y1[e])*(sy-y1[e]);
		}
		else
		{
			if(sx>x2[e])
			{
				temp=(sy-y1[e])*(sy-y1[e])+(sx-x2[e])*(sx-x2[e]);
			}
			else
			{
				temp=(sy-y1[e])*(sy-y1[e])+(sx-x1[e])*(sx-x1[e]);
			}
		}
	}
	if(temp<=a*a)return sqrt(temp);
	else return 1e9;
}
double check(int x,int y)
{
	if(x==y)return 0;
	double temp;
	if(tp[x]==0&&tp[y]==0)
	{
		if(y1[x]>y2[y])
		{
			temp=(x1[x]-x1[y])*(x1[x]-x1[y])+(y1[x]-y2[y])*(y1[x]-y2[y]);
		}
		else if(y2[x]<y1[y])
		{
			temp=(x1[x]-x1[y])*(x1[x]-x1[y])+(y2[x]-y1[y])*(y2[x]-y1[y]);
		}
		else
		{
			temp=(x1[x]-x1[y])*(x1[x]-x1[y]);
		}
	}
	else if(tp[x]==1&&tp[y]==1)
	{
		if(x1[x]>x2[y])
		{
			temp=(y1[x]-y1[y])*(y1[x]-y1[y])+(x1[x]-x2[y])*(x1[x]-x2[y]);
		}
		else if(x2[x]<x1[y])
		{
			temp=(y1[x]-y1[y])*(y1[x]-y1[y])+(x2[x]-x1[y])*(x2[x]-x1[y]);
		}
		else
		{
			temp=(y1[x]-y1[y])*(y1[x]-y1[y]);
		}
	}
	else
	{
		if(tp[x]==1&&tp[y]==0){int sw=x;x=y;y=sw;}
		if(y1[x]<=y1[y]&&y2[x]>=y1[y])
		{
			if(x1[x]<x1[y])temp=(x1[y]-x1[x])*(x1[y]-x1[x]);
			else temp=(x2[y]-x1[x])*(x2[y]-x1[x]);
		}
		else if(x1[y]<=x1[x]&&x2[y]>=x1[x])
		{
			if(y1[y]<y1[x])temp=(y1[y]-y1[x])*(y1[y]-y1[x]);
			else temp=(y1[y]-y2[x])*(y1[y]-y2[x]);
		}
		else
		{
			if(y1[y]>y2[x])
			{
				if(x1[y]>x1[x])
				{
					temp=(x1[x]-x1[y])*(x1[x]-x1[y])+(y1[y]-y2[x])*(y1[y]-y2[x]);
				}
				else
				{
					temp=(x1[x]-x2[y])*(x1[x]-x2[y])+(y1[y]-y2[x])*(y1[y]-y2[x]);
				}
			}
			else
			{
				if(x1[y]>x1[x])
				{
					temp=(x1[x]-x1[y])*(x1[x]-x1[y])+(y1[y]-y1[x])*(y1[y]-y1[x]);
				}
				else
				{
					temp=(x1[x]-x2[y])*(x1[x]-x2[y])+(y1[y]-y1[x])*(y1[y]-y1[x]);
				}
			}
		}
	}
	if(temp<=a*a)return a+b;
	else return 1e9;
}
int main()
{
	int n,i,sx,sy,ex,ey,j;
	scanf("%lf%lf",&a,&b);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",x1+i,y1+i,x2+i,y2+i);
		if(x1[i]>x2[i])swap(x1[i],x2[i]);
		if(y1[i]>y2[i])swap(y1[i],y2[i]);
		//printf("%lf %lf %lf %lf \n",x1[i],y1[i],x2[i],y2[i]);
		if(x1[i]==x2[i])tp[i]=0;
		else tp[i]=1;
	}
	if((sx-ex)*(sx-ex)+(sy-ey)*(sy-ey)<=a*a)
	{
		printf("%.9lf\n",sqrt((sx-ex)*(sx-ex)+(sy-ey)*(sy-ey)));
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		g[0][i]=st(i,sx,sy);
		g[i][n+1]=end(i,ex,ey);
		for(j=1;j<=n;j++)
		{
			g[i][j]=check(i,j);
		}
	}
	g[0][n+1]=g[n+1][0]=1e9;
	/*for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)printf("%lf ",g[i][j]);puts("");
	}*/
	
	dij(n);
	//for(i=0;i<=n+1;i++)printf("i:%d d:%lf \n",i,d[i]);
	if(d[n+1]==1e9)puts("-1");
	else printf("%.9lf\n",d[n+1]);
	return 0;
}
					  		 		 					 	    	