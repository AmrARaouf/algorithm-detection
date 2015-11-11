//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<int,int>ma,mq;
int A[100100],B[100100],R[100010],P[200100],Q[100010],jud[100010];
int sav[100010],ww[100100][2];
int main()
{
    int i,j,k,n;
    int a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",A+i,B+i);
    }
    for(i=0;i<n;i++)
    {
        P[2*i]=A[i];P[2*i+1]=B[i];
    }sort(P,P+n*2);j=0;
    Q[j++]=P[0];
    for(i=1;i<2*n;i++)
    {
        if(P[i]==P[i-1]) continue;
        Q[j++]=P[i];
    }
    for(i=0;Q[i];i++) {ma[Q[i]]=i+1;mq[i+1]=Q[i];}//cout<<Q[i]<<ma[Q[i]]<<endl;}
    for(i=0;i<n;i++)
    {
        a=ma[A[i]];
        b=ma[B[i]];
        sav[a]++;
        sav[b]++;
        j=0;if(ww[a][0]) j++;
        ww[a][j]=b;
        j=0;if(ww[b][0]) j++;
        ww[b][j]=a;
    }
    for(i=1;i<=n;i++)
    {
        if(sav[i]==1) break;
    }
    printf("%d",mq[i]);
    jud[i]=1;
    do
    {
        a=ww[i][0];b=ww[i][1];
        if(!jud[a]&&a) i=a;
        else i=b;
        jud[i]=1;
        printf(" %d",mq[i]);
    }while(sav[i]==2);
    printf("\n");
    return 0;
}

  	  	 					 		 		 		   	