//Language: GNU C++


//By Lin
#include<cstdio>
#include<cstring>
#define maxn 3005
#define maxm 200005
using namespace std;

struct	Edge{
	int to,num,k; 
	Edge *next; 
}*g[2][maxn],edges[maxm]; 

int	n,m,cnt,p[2][maxn],que[maxn]; 

void	link(int i, int x ,int to , int num )
{
	edges[cnt].to = to; 
	edges[cnt].k  = i; 
	edges[cnt].num = num; 
	edges[cnt].next = g[i][x]; 
	g[i][x] = &edges[cnt++]; 
}

int		find(int i , int x )
{
	if ( p[i][x] != x ) p[i][x] = find(i,p[i][x]); 
	return p[i][x]; 
}

void	link_m(int x )
{
	int head = 0 , tail = 1; 
	que[0] = x; 
	while ( head < tail )
	{
		int i = que[head++]; 
		for ( Edge * pp = g[1][i]; pp ; pp = pp->next )
		{
			int to = pp->to; 
			if ( find(0,to) != find(0,i) )
			{
				p[0][find(0,to)] = i; 
				que[tail++] = to; 
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n,&m); 	
	cnt = 0; 
	memset( g , 0 , sizeof(g) ); 
	for (int i = 0; i<m; i++)
	{
		int x, y,k = 0; 
		char s[5]; 
		scanf("%d%d%s" , &x ,&y , s ); 
		if ( s[0] == 'M' ) k++; 
		link(k , x ,y , i+1); 
		link(k , y ,x , i+1);
	}
	if ( n%2 != 1 ) { printf("-1\n"); return 0; }
	for (int i = 0; i<n; i++) p[0][i] = p[1][i] = i; 
	for (int i = 0; i<n; i++)
		if ( p[0][i] == i ) link_m(i); 


	int m = 0; 
	for (int i = 0; i<n; i++)
	{
		for ( Edge *pp = g[0][i]; pp ; pp = pp->next )
		{
			int to = pp->to; 
			if ( find(0,to) != find(0,i) ) 
			{
				m++;
				p[0][find(0,to)] = i; 
				p[1][find(1,to)] = i;
				pp->num *= -1; 
			}
		}
	}

	bool flag = true;
	if ( m > (n-1)/2 ) flag = false; 
	for (int i = 1; i<n; i++) if ( find(0,i)!=find(0,0) ) flag = false; 
	if ( !flag ){ printf("-1\n"); return 0; }

	for (int i = 0; i<n && m<(n-1)/2; i++)
	{
		for ( Edge *pp = g[0][i]; pp ; pp = pp->next )
		{
			int to = pp->to; 
			if ( find(1,to) != find(1,i) ) 
			{
				m++;
				p[1][find(1,to)] = i;
				pp->num *= -1; 
				if ( m == (n-1)/2 ) break; 
			}
		}
	}
	if ( m<(n-1)/2 ) { printf("-1\n"); return 0; }
	for (int i = 0; i<n ; i++)
	{
		for ( Edge *pp = g[1][i]; pp ; pp = pp->next )
		{
			int to = pp->to; 
			if ( find(1,to) != find(1,i) ) 
			{
				p[1][find(1,to)] = i;
				pp->num *= -1; 
			}
		}
	}

	printf("%d\n",n-1 );
	for (int i = 0, j = 0; i<cnt; i++)
	{
		if ( edges[i].num > 0 ) continue; 
		j++; 
		printf("%d", edges[i].num * (-1) );
		if ( j != n-1 ) printf(" "); 
	}
	printf("\n"); 
	return 0; 
}
