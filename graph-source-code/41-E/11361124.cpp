//Language: GNU C++


/*
 * e.cpp
 *
 *  Created on: May 30, 2015
 *      Author: hassan
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long                       ll;
typedef unsigned long long              ull;
typedef pair<ll, ll>                    pll;
typedef pair<int,int>                   ii;
typedef vector<int>                     vi;
typedef vector<vector<int> >            vvi;
typedef vector<pair<int,int> >          vii;
typedef vector<vector<pair<int,int> > > vvii;
typedef complex<double>                 point;

#define PI                 (acos(-1.0))
#define EPS                (1e-12)
#define MOD                ((int)(1e9)+7)
#define Inff               ((int)(1e8))
#define pb                 push_back
#define mp                 make_pair
#define X                  real()
#define Y                  imag()
#define polar(r,t)         ((r)*exp(point(0,(t))))
#define length(a)          hypot((a).X,(a).Y)
#define angle(a)           atan2((a).Y,(a).X)
#define vec(a,b)           ((b)-(a))
#define dot(a,b)           ((conj(a)*(b)).real())
#define cross(a,b)         ((conj(a)*(b)).imag())
#define length_sqr(a)      dot(a,a)
#define rotate(v,t)        ((v)*exp(point(0,t)))
#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(v,m)       (conj((v)/(m))*(m))
#define endl               "\n"

int n;

int main() {
    scanf("%d", &n);
    printf("%d\n", n&1 ? (n/2)*((n+1)/2) : (n/2)*(n/2));
    for(int i = 1 ; i <= n/2 ; ++i)
    	for(int j = n/2 + 1 ; j <= n ; ++j)
    		printf("%d %d\n", i, j);
    return 0;
}
