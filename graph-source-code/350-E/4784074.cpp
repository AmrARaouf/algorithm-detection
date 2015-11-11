//Language: GNU C++


#include<iostream>
using namespace std;
main()
{
    int i,j,k,l,m,n,count=0,edge;  //cout<<"anuj";
    cin>>n>>m>>k;
    int a[k],marked[n],chain[n-1],later;
    for(i=0;i<n;i++) marked[i]=0;

    for(i=0;i<k;i++) {cin>>a[i]; marked[a[i]-1]=1;} marked[a[0]-1]=2; later=a[0]; marked[a[1]-1]=2; chain[count++]=a[1];
    if(m>(((n-2)*(n-1))/2)+n-k){cout<<-1; return 0;}
    //if(k==n-1&&m==((n*(n-1))/2)){cout<<-1; return 0;}
    if(k==n) {cout<<-1; return 0;}
    for(i=0;i<n;i++) if(marked[i]==0){chain[count++]=i+1; marked[i]=2; break;}
    for(i=0;i<n;i++) if(marked[i]!=2){chain[count++]=i+1;}

    edge=m-1;
    for(i=0;i<n-1&&edge>0;i++) for(j=i+1;j<n-1&&edge>0;j++) {cout<<chain[i]<<" "<<chain[j]<<endl; edge--;}

    cout<<chain[1]<<" "<<later<<endl;
    if(edge>0)
        for(i=0;i<n&&edge>0;i++)if(marked[i]==0){cout<<i+1<<" "<<later<<endl; edge--;}
}
