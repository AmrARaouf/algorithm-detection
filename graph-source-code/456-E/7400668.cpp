//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
int p[300100],l[300100];
vector<int> e[300100];

int f(int x){
    while(x!=p[x]){
        x=p[x]=p[p[x]];
    }
    return x;
}

ii L(int x,int p){
    int lon=0,h1=0,h2=0,S=e[x].size();
    ii R;
    for(int i=0;i<S;i++){
        if(p==e[x][i])continue;
        R=L(e[x][i],x);
        if(R.first>h1){
            h2=max(h1,h2);
            h1=R.first;
        }
        else if(R.first>h2){
            h2=R.first;
        }
        if(R.second>lon)
            lon=R.second;
    }
    lon=max(h1+h2,lon);
    return ii(h1+1,lon);
}

int main() {
    stringstream ss;
	memset(l,0,sizeof(l));
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
        p[i]=i;
	int a,b;
	for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
	}
	bitset<300100> B;
	queue<int> Q;
	for(int i=0;i<n;i++){
        if(!B.test(i)){
            B.set(i);
            Q.push(i);
            while(!Q.empty()){
                int x=Q.front();
                Q.pop();
                for(int j=0;j<e[x].size();j++){
                    if(!B.test(e[x][j])){
                        B.set(e[x][j]);
                        Q.push(e[x][j]);
                        p[e[x][j]]=i;
                    }
                }
            }
            l[i]=L(i,i).second;
        }
	}
	int c,x,y;
	for(int i=0;i<q;i++){
        scanf("%d",&c);
        if(c==2){
            scanf("%d %d",&x,&y);
            x--;
            y--;
            x=f(x);
            y=f(y);
            if(x!=y){
                int m=max(l[x],l[y]);
                l[x]=max(m,(l[x]+1)/2+(l[y]+1)/2+1);
                p[y]=x;
            }
        }
        else if(c==1){
            scanf("%d",&x);
            x--;
            printf("%d\n",l[f(x)]);
        }
	}
	return 0;
}
