//Language: GNU C++


/**
  *@xiaoran
  *bfs：求a-->b的最少次数，变换规则1、a=a-1， 2、a=2*a
  */
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cstdlib>
#include<cctype>
#include<cmath>
#define LL long long
using namespace std;
int has[21000],a,b;
struct Node{
    int n,step;
};
int bfs(){
    memset(has,0,sizeof(has));
    queue<Node> q;
    Node node;
    node.n=a;
    node.step=0;
    has[node.n]=1;
    q.push(node);
    while(!q.empty()){
        Node tmp,cru;
        cru=q.front();
        q.pop();
        //cout<<cru.n<<endl;
        if(cru.n==b) return cru.step;
        //a=a-1
        tmp.n=cru.n-1;
        tmp.step=cru.step+1;
        if(!has[tmp.n]&&tmp.n>=0) q.push(tmp);
        has[tmp.n]=1;
        //a=a*2
        tmp.n=cru.n*2;
        tmp.step=cru.step+1;
        if(!has[tmp.n]&&tmp.n<=10000) q.push(tmp);
        has[tmp.n]=1;

    }
    return -1;
}

int main()
{
	while(cin>>a>>b){
        cout<<bfs()<<endl;
	}
	return 0;
}
