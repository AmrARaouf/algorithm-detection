//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
typedef long long LL;
int n;
int a[1000],b[200],next[1000];
int num,dq;
char s[200][200];
char dq1[200],dq2[200];
int len1,len2,len,indegree[200],ans[200],ans0,v;
queue<int> q;
void addedge(int x,int y)
{
	++num;a[num]=y;next[num]=b[x];b[x]=num;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%s",s[i]);
	for (int i=0;i<n-1;++i)
	{
		len1=strlen(s[i]);len2=strlen(s[i+1]);
		len=min(len1,len2);
		int j;
		j=0;
		while (j<len)
		{
			if (s[i][j]!=s[i+1][j]) break;
			++j;
		}
		if (j==len)
		{
			if (len==len2)
			{
				printf("Impossible\n");
				return 0;
			}
			continue;
		}
		addedge(s[i][j]-'a',s[i+1][j]-'a');
		indegree[s[i+1][j]-'a']++;
	}
	for (int i=0;i<26;++i) if (indegree[i]==0) q.push(i);
	while (!q.empty())
	{
		dq=q.front();
		q.pop();
		++ans0;ans[ans0]=dq;
		for (int i=b[dq];i!=0;i=next[i])
		{
			v=a[i];
			--indegree[v];
			if (indegree[v]==0) q.push(v);
		}
	}
	if (ans0!=26) printf("Impossible\n");
	else 
		for (int i=1;i<=26;++i) printf("%c",ans[i]+'a');
	return 0;
}