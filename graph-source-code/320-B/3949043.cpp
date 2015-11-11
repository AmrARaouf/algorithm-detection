//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cstdio>

using namespace std;

typedef vector<int> vi ;
typedef long long int LL ;

int M , N ;

int main ( )
{
 pair<int,int> val ;
 vector < pair<int,int> > arr ;
 cin >> N ;
 int a,b,ind ,A,B;
 while ( N-- )
 {
  scanf("%d",&M);
  if ( M==1)
  {
   cin>>a;
   cin>>b;
   a--;b--;
   arr.push_back(make_pair(a,b));
  }
  else if ( M==2)
  {

   cin>>A;
   cin>>B;
   A--;B--;
   int visited[1100]={0};
   int a , b ;
   int c =arr[B].first , d = arr[B].second ;
   visited[A]=true ;
   int ok = false ;
   int sz = arr.size() ;
   queue< pair <int ,int> > Queue ;
   Queue.push(arr[A]) ;
   while ( !Queue.empty() )
   {
    val = Queue.front() ;
    Queue.pop();
    a = val.first ;
    b = val.second ;
    if ( ( a > c && a < d ) || (b > c && b < d))
    {
     ok = true ;
    }
    for ( int i = 0 ; i < sz ; i++ )
    {
     if ( !visited[i])
     {
      int p = arr[i].first ;
      int q = arr[i].second ;
      if ( (p<a && q >a ) || ( p <b && q >b))
      {
       visited[i] = true ;
       Queue.push( arr[i]) ;
      }
     }
    }

   }
   if ( ok )
    cout <<"YES\n";
   else
    cout <<"NO\n" ;
  }
 }

 return 0 ;
}

