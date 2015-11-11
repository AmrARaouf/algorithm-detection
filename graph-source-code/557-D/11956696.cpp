//Language: GNU C++


#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

inline long long int fast_input(void)
{
	char t;
	long long int x=0;
	long long int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
    while(t>=48 && t<=57)
    {
        x=(x<<3)+(x<<1)+t-48;
        t=getchar();
    }
	if(neg)
		x=-x;
	return x;
}

inline void fast_output(long long int x)
{
	char a[20];
	long long int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

vector <long long int> G[100001];
long long int visited[100001],flag=0,mark[100001],x,y;

int dfs(long long int a, long long int b)
{
	mark[a]=b;
	if (b==0) x++;
	else y++;
	visited[a]=1;
	int i,w,len=G[a].size(),size=0;
	for(i=0;i<len;i++)
	{
		w=G[a][i];
		if (!visited[w])
			size+=dfs(w,1-b);
		else if (mark[w]==mark[a]) flag=1;
	}
	return (1+size);
}

int main()
{
long long int n,m,i,a,b,size,maxsize=0,ans=0;
memset(visited,0,sizeof(visited));
memset(mark,0,sizeof(mark));
n=fast_input();
m=fast_input();
if (m==0) {printf("3 "); fast_output(n*(n-1)*(n-2)/6); return 0;}

for(i=0;i<m;i++)
{
	a=fast_input();
	b=fast_input();
	a--;
	b--;
	G[a].push_back(b);
	G[b].push_back(a);
}

for(i=0;i<n;i++)
{
	if (!visited[i])
	{
		x=0;
		y=0;
		size=dfs(i,0);
		if (size>maxsize)
			maxsize=size;
		ans+=x*(x-1)/2+y*(y-1)/2;
	}
}

if (flag) {printf("0 1\n"); return 0;}
if (maxsize==2)
{
	printf("2 "); fast_output(m*(n-2));
	return 0;
}
printf("1 "); fast_output(ans);
return 0;
}
