//Language: GNU C++


#include <stdio.h>
#include <string.h>
char conflict_point(char *p, char *q)
{
    int i=0;
    while (p[i]==q[i])
    {
        i++;
    }
    if (p[i]=='\0'&&q[i]=='\0') return -1;
    if (p[i]=='\0') return -2;
    if (q[i]=='\0') return -10;
    return i;
}
int main()
{
    char A[101][101], order[27];
    int indegree[26], ord_index, first, next, f, one;
    int i, j, k, temp;
    bool graph[27][27];
    int n;

    while (scanf("%d%*c", &n)!=EOF)
    {
        for (i=0; i<n; i++)
            scanf("%s", A[i]);
        ord_index=0;
        for (i=0; i<27; i++) for (j=0; j<27; j++) graph[i][j]=false;
        for (i=0; i<26; i++) indegree[i]=0;
        for (i=1; i<n; i++)
        {

             temp=conflict_point(A[i-1], A[i]);

             if (temp==-10) {printf("Impossible\n"); break;}
             if (temp==-1||temp==-2) continue;

             first=A[i-1][temp]-'a';
             next=A[i][temp]-'a';


             if (graph[first][next]==false) indegree[next]++;

             graph[first][next]=true;
        }
        if (temp==-10) { temp=0; continue;}

while (1)
{
    one=0;
    f=0;
    for (i=0; i<26; i++)
    {
        if (indegree[i]==0)
        {
            order[ord_index]=i;
            ord_index++;
            one++;
            for (j=0; j<26; j++)
            {
                if (graph[i][j]==true)
                    indegree[j]--;
            }
        indegree[i]=-1;
        }
        if (indegree[i]==-1) f++;
    }
if (one==0) break;
}
if (f==26)
{
    for (i=0; i<26; i++) printf("%c", order[i]+'a');
    printf("\n");
}
else printf("Impossible\n");
    }
return 0;
}