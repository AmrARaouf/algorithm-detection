//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

long long k, k1, st, ed, pow[50], step[100], ps = 0ll, n, num = 3l, nb = 3ll, edge;

bool a[1010][1010];

main()
{
      //freopen("in.txt","r",stdin);
      //freopen("out.txt","w",stdout);
      cin >> k;
      k1 = k;
      for (;k1;)
      {
          k1/=2ll;
          st++;
      }
      st--;
      ed = st*2ll - 1ll;
      for (long long i = 1ll; i <= ed; i+=2ll)
      {
          pow[ps] = nb;
          nb+=2ll;
          ps++;
      }
      for (long long l = 0ll, r = ps - 1ll;l < r; l++,r--)
          swap(pow[l],pow[r]);
      
      
      if (st == 0ll)
      {
             cout << 2 << endl ;
             cout << "NY" << endl ;
             cout << "YN" ;
             cin >> k;
             return 0;
      }
      nb-=2ll;
      a[1][3] = a[3][1] = true;
      if (nb > 3ll)
         a[3][4] = a[4][3] = true;
      for (long long i = 5ll; i < nb; i+=2ll)
      {
          a[i][i - 1ll] = a[i - 1ll][i] = true;
          a[i][i + 1ll] = a[i + 1ll][i] = true;
      }
      
      if (nb > 3)
         a[nb][nb - 1ll] = a[nb - 1ll][nb] = true;
      
      edge = nb + 3ll;
      for (long long i = 1ll; i < st;i++, edge+=3)
      {
          step[st - i] = edge;
          if (k & (1ll << (st - i)))
             a[step[st-i]][pow[st - i]] = a[pow[st - i]][step[st-i]] = true;
      }
      
      if (k & 1ll)
         a[pow[0]][2] = a[2][pow[0]] = true;
         
      
      a[1][nb + 1ll] = a[nb + 1ll][1] = true;
      a[1][nb + 2ll] = a[nb + 2ll][1] = true;
      a[2][edge - 1ll] = a[edge - 1ll][2] = true;
      a[2][edge - 2ll] = a[edge - 2ll][2] = true;
      for (long long i = nb + 3ll; i < edge; i+=3ll)
      {
          a[i][i - 1ll] = a[i - 1ll][i] = true;
          a[i][i - 2ll] = a[i - 2ll][i] = true;
          a[i][i + 1ll] = a[i + 1ll][i] = true;
          a[i][i + 2ll] = a[i + 2ll][i] = true;
      }

cout << edge - 1ll << endl ;                    
for (long long i = 1ll; i < edge; i++)
{
    for (long j = 1ll; j < edge; j++)
        if (a[i][j])
           cout << 'Y';
        else
           cout << 'N';
    cout << endl ;
}       
              
cin >> k;
return 0;
}
