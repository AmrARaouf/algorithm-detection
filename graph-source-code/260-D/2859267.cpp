//Language: GNU C++


#include<cstdio>
#define M 100010
#define K(x,y) (x<y?x:y)
#define u(l) printf("%d %d %d\n",A->p,B->p,l)
struct t{int s,p;};int N,x,y,i,l;t a[M],*Q=a,*b=a+M-1,*G=b,*A,*B;main(){scanf("%d",&N);while(++i<=N){scanf("%d%d",&x,&y);if(x)Q->s=y,Q->p=i,++Q;else G->s=y,G->p=i,--G;}for(A=a,B=b;A!=Q&&B!=G;++A)if(!A->s)u(0);else while(A->s){l=K(A->s,B->s),A->s-=l;B->s-=l,u(l);if(A->s)--B;}for(--A,--B;B!=G;--B)u(0);}