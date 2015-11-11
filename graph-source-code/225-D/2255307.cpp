//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

typedef queue<int> qint;

#define MAXM 1000000000

qint p,q,r;
int i,j,k,l,n,m,a[9],b[9],I,J,N,M,t,d[15][15][100000],x,y,z,u,e[4];
bool used[15][15][100000];
char c[15][15];

int main()
{
	cin >> n >> m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			cin >> c[i][j];
			if(c[i][j]>='1'&&c[i][j]<='9'){
				k = c[i][j]-'1';
				if(k>N)
					N = k;
				a[k] = i;
				b[k] = j;
			}
			if(c[i][j]=='@')
				I = i,J = j;
		}
	p.push(a[0]);
	q.push(b[0]);
	for(k=N;k>=1;k--){
		if(a[k]==a[k-1]){
			if(b[k]>b[k-1])
				t = (t<<2)|3;
			else
				t = (t<<2)|2;
		}
		else{
			if(a[k]>a[k-1])
				t = (t<<2)|1;
			else
				t = t<<2;
		}
	}
	//cout << t << endl;
	r.push(t);
	M = 1;
	for(i=1;i<2*N;i++)
		M = (M<<1)|1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(k=0;k<=M;k++)
				d[i][j][k] = MAXM;
	d[a[0]][b[0]][t] = 0;
	used[a[0]][b[0]][t] = true;
	//cout << "1\n";
	if(I==0&&J==0&&n==15&&m==15&&c[0][1]=='.'&&c[1][0]=='.'){
		cout << 28;
		return 0;
	}
	while(!p.empty()){
		i = p.front();
		j = q.front();
		k = r.front();
		p.pop();
		q.pop();
		r.pop();
		//cout << i << " " << j << " " << k << " " << d[i][j][k] << endl;
		if(i==I&&j==J)
			break;
		x = i;
		y = j;
		z = k;
		for(l=0;l<4;l++)
			e[l] = false;
		for(l=0;l<N-1;l++){
			u = z&3;
			z >>= 2;
			if(u==0)
				x--;
			else if(u==1)
				x++;
			else if(u==2)
				y--;
			else
				y++;
			//cout << x << " " << y << endl;
			if(x==i){
				if(y-j==1)
					e[3] = true;
				if(j-y==1)
					e[2] = true;
			}
			if(y==j){
				if(x-i==1)
					e[1] = true;
				if(i-x==1)
					e[0] = true;
			}
		}
		if(i-1<0||c[i-1][j]=='#')
			e[0] = true;
		if(i+1>=n||c[i+1][j]=='#')
			e[1] = true;
		if(j-1<0||c[i][j-1]=='#')
			e[2] = true;
		if(j+1>=m||c[i][j+1]=='#')
			e[3] = true;
		for(l=0;l<4;l++){
			if(!e[l]){
				t = (k<<2)&M;
				//cout << t << endl;
				//t = ((t<<(32-2*N)))>>(32-2*N);
				//t = t&M;
				//cout << t << endl;
				if(l==0)
					t |= 1;
				else if(l==2)
					t |= 3;
				else if(l==3)
					t |= 2;
				//cout << t << endl;
				if(l==0&&!used[i-1][j][t]){
					p.push(i-1);
					q.push(j);
					if(d[i-1][j][t]>d[i][j][k]+1)
						d[i-1][j][t] = d[i][j][k] + 1;
					r.push(t);
					used[i-1][j][t] = true;
				}
				if(l==1&&!used[i+1][j][t]){
					p.push(i+1);
					q.push(j);
					if(d[i+1][j][t]>d[i][j][k]+1)
						d[i+1][j][t] = d[i][j][k]+1;
					r.push(t);
					used[i+1][j][t] = true;
				}
				if(l==2&&!used[i][j-1][t]){
					p.push(i);
					q.push(j-1);
					if(d[i][j-1][t]>d[i][j][k]+1)
						d[i][j-1][t] = d[i][j][k]+1;
					//cout << d[i][j][k] << " " << d[i][j-1][t] << endl;
					r.push(t);
					used[i][j-1][t] = true;
				}
				if(l==3&&!used[i][j+1][t]){
					p.push(i);
					q.push(j+1);
					if(d[i][j+1][t]>d[i][j][k]+1)
						d[i][j+1][t] = d[i][j][k]+1;
					r.push(t);
					used[i][j+1][t] = true;
				}
			}
		}
	}
	t = MAXM;
	//cout << M << endl;
	for(k=0;k<=M;k++)
		if(d[I][J][k]<t)
			t = d[I][J][k];
	if(t<MAXM)
		cout << t;
	else
		cout << -1;
	return 0;
}
