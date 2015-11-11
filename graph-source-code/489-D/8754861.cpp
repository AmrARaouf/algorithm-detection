//Language: GNU C++


/*
//如何写一份可以提交的代码？以A+B为例
#include <iostream>
using namespace std;
int main()
{
	int a, b; //定义两个变量名
	cin >> a >> b; //从标准输入流中输入两个整数
	cout << a + b << endl; //输出到标准输出流中
	return 0;
}
// 完成程序以后，点击下方的提交，即可看到测试结果
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,a,b,ans,p;

int an[3100],head[3100],go[31000],nex[31000],use[3100];

void dfs(int a,int d)
{
	if (d==2) 
	{
		
		ans+=an[a]++;
	    return;
	}
    use[a]=1;
	for (int i=head[a];i;i=nex[i])
		if (!use[go[i]]) dfs(go[i],d+1);
	use[a]=0;
}

void build(int a,int b)
{
	go[++p]=b;
	nex[p]=head[a];
	head[a]=p;
}

int main()
{
    
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		build(a,b);
	}
	for (int i=1;i<=n;i++)
	{
	  for (int j=1;j<=n;j++)	
	  an[j]=0;
	  dfs(i,0);
	}
	printf("%d\n",ans);
	return 0;
}