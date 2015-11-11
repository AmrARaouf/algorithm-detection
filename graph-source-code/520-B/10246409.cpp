//Language: GNU C++


#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
struct AC{
    int x,s;
};
int n,m;
int f[100010];
void bfs()
{
    queue<AC> Q;
    AC t;
    t.x=n;
    t.s=0;
    Q.push(t);
    f[n]=1;
    int minn=9999999;
    while(!Q.empty())
    {
        AC s=Q.front();
        Q.pop();
//        printf("aa");
        if(s.x == m)
        {
            printf("%d\n",s.s);
            return ;
        }
        else if(s.x>m)
        {
            minn=min(minn,s.s+s.x-m);
            continue;
        }
        t.x=s.x*2;
        t.s=s.s+1;
        if(f[t.x]) ;
        else Q.push(t);
        f[t.x] =1;
        t.x=s.x-1;
        t.s=s.s+1;
        if(t.x<0||f[t.x])  ;
        else Q.push(t);
        f[t.x]=1;
    }
    printf("%d\n",minn);
}
int main()
{

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n>=m) {
            printf("%d\n",n-m);
            continue;
        }
        memset(f,0,sizeof(f));
        bfs();
    }
}

 		     	  	   		  						 	 			