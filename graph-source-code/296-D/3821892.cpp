//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<climits>
#define IM 100005
using namespace std;
int belongs_to(int x[],int u,int i,int n)
{
        int j;
        for(j=i;j<n;j++)
        {
	    if(x[j]==u)
		return true;
        }
        return false;
}
int main()
{
        int n;
        cin>>n;
        int a[n][n];
        int i,j,k,top=-1;
        for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
		cin>>a[i][j];
	    
        
        long long int sum=0,sumStack[n];
        int x[n];
        for(i=0;i<n;i++)
        {
	    cin>>x[i];
	    x[i]--;
        }
        int prev[n][n];
        for(i=0;i<n;i++)
	    a[i][i]=IM;
        for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
		prev[i][j]=a[i][j];
        for(k=n-1;k>=0;k--)
        {
	    for(i=0;i<n;i++)
	    {
		for(j=0;j<n;j++)
		{
		        a[i][j]=min(prev[i][j],prev[i][x[k]]+prev[x[k]][j]);
		}
	    }
	    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		        prev[i][j]=a[i][j];	
	    sum=0;
	    for(i=k;i<n;i++)
	    {
		for(j=k;j<n;j++)
		{
		        if(x[i]!=x[j])
			    sum+=a[x[i]][x[j]];
		}
	    }
	    sumStack[++top]=sum;
	    //cout<<"done";
        }
        for(i=top;i>=0;i--)
	    cout<<sumStack[i]<<" ";
        
        return 0;
}