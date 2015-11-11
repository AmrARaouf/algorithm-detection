//Language: GNU C++11


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int n=1000000;
int t,a[n],s[n],d[n],f[n],f1[n],f9[n+1],g[n];
void qs(int q,int w){
  int e=q,r=w,y=q+(rand()%(w-q+1)),t=a[y],t1=s[y];
  do{
  while((a[e]<t)||((a[e]==t)&&(s[e]<t1)))e++;
  while((a[r]>t)||((a[r]==t)&&(s[r]>t1)))r--;
  if(e<=r){
   y=a[e];a[e]=a[r];a[r]=y;
   y=s[e];s[e]=s[r];s[r]=y;
   e++;r--;}
  }while(e<=r);
  if(q<r)qs(q,r);
  if(e<w)qs(e,w);
}
int bp(int e,int r){
  int c,c1=-1,v;
  if(e>r){
   c=e;e=r;r=c;}
  for(v=1<<19;v;v>>=1){
   c=c1+v;
   if((c<t)&&((a[c]<e)||((a[c]==e)&&(s[c]<=r))))
    c1=c;}
  if((c1>=0)&&((a[c1]==e)&&(s[c1]==r)))
   return 1;
  return 0;
}
int k(int w){
  if(f[w]!=w)
   f[w]=k(f[w]);
  return f[w];
}
int k9(int w){
  if(f9[w]!=w)
   f9[w]=k9(f9[w]);
  return f9[w];
}
bool sch(int w,int e){
  int c,v;
  for(c=g[w];c>=0;c=d[c])
   for(v=g[e];v>=0;v=d[v])
    if(!bp(c,v))
     return 1;
  return 0;
}
void un(int w,int e){
  int c;
  if(f1[w]>f1[e]){
   for(c=g[e];d[c]>=0;c=d[c]);
   d[c]=g[w];
   g[w]=g[e];}
  else{
   for(c=g[w];d[c]>=0;c=d[c]);
   d[c]=g[e];}
  f1[w]+=f1[e];
  f[e]=w;
  f9[e]=k9(e+1);
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int q,w,e,r,c,v,o;
  scanf("%d%d",&q,&t);
  for(w=0;w<q;w++){
   f[w]=f9[w]=g[w]=w;
   f1[w]=1;
   d[w]=-1;}
  f9[q]=q;
  for(w=0;w<t;w++){
   scanf("%d%d",&a[w],&s[w]);
   if(a[w]>s[w]){
    e=a[w];a[w]=s[w];s[w]=e;}
   a[w]--;
   s[w]--;}
  if(t)
   qs(0,t-1);
  for(w=k9(0);w<q;w=k9(w+1))
   for(e=k9(0);e<q;e=k9(e+1))
    if(w!=e)
     if(sch(w,e)){
      for(c=k9(0);c<max(e,w);c=k9(c+1))
       if(((c!=w)&&(c!=e))&&(sch(e,c)))
        un(w,c);
      un(w,e);}
  r=0;
  for(w=0;w<q;w++)
   if(f[w]==w)
    r++;
  printf("%d\n",r);
  for(w=0;w<q;w++)
   if(f[w]==w){
    printf("%d",f1[w]);
    for(e=g[w];e>=0;e=d[e])
     printf(" %d",e+1);
    printf("\n");}
  return 0;}
