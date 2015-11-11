//Language: GNU C++


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int binarysearch(long long int n,long long int x){
    long long int lo=0;long long int high=1000000000;

    long long int mid;
    while(lo<=high){
        mid=lo+(high-lo)/2;
        if(mid*mid+x*mid-n<0)
            lo=mid+1;
        else if(mid*mid+x*mid-n>0){
            high=mid-1;
        }
        else{
            return mid;
        }
        //if(x==1)
        //cout << lo << " " << high << endl;
        //cout<<lo<<" "<<high<<endl;

    }
    //cout<<high <<endl;
    //cout << high << endl;
    return -1;

 }
 int sum(long long int r){
    long long int sum=0;
    while(r){
        sum+=(r%10);
        r=r/10;
    }
    return sum;
 }
int function(int n){
    int sum=1;
    sum=n*(n-1)*(n-2);
    sum=sum/6;
    return sum;
}
int function2(int n){
int sum=1;
sum=n*(n-1);
sum=sum/2;
return sum;
}
int main()
{   int n;
    cin>> n;
    vector<int> V;
    int i;
    while(n){
    for(i=(V.empty())?3:2;;++i){

            int z;if(V.empty())
             z=function(i);
            else{
                 z=function2(i);
            }
        if(z>n){//cout << z << endl;
            break;
        }
    }
    if(V.empty())
    n=n-function(i-1);
    else
        n=n-function2(i-1);
    V.push_back(i-1);
    }
    int B[100][100]={0};
    int sum=0;
    for(i=0;i<V.size();++i){
        if(i==0){
            for(int j=0;j<V[i];++j){
                for(int k=0;k<V[i];++k){
                    if(j==k)
                        B[j][k]=0;
                    else
                        B[j][k]=1;
                }
            }
            sum+=V[i];

        }
        else{
            for(int j=0;j<V[i];++j){
                for(int k=sum;k<sum+1;++k){
                    B[j][k]=1;
                    B[k][j]=1;
                }
            }
            sum+=1;
        }
    }
    cout << sum << endl;
    for(i=0;i<sum;++i){
        for(int j=0;j<sum;++j){
            cout << B[i][j];
        }
        cout<<endl;
    }
    return 0;



    }





