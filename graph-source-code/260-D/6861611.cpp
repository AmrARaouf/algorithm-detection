//Language: GNU C++



#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define For(i, a, b) for (int (i) = (a); (i) <= (b); (i) ++)
#define mp make_pair
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define pi 3.1415926535897932384626433832795028
#define db(x) cout << #x << " = " << (x) << endl;
#define dba(a,x,y) {cout << #a << " :";For(i, (x), (y))cout<<" "<<(a)[(i)];cout<<endl;}
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;

int s, N, S[100100], C[100100], A[100100], B[100100];
int main()
{
    ios_base::sync_with_stdio(0);
    // cout.precision(10);
    cin >> N;
    rep1(i, N)
    {
        cin >> C[i] >> S[i];
        if (C[i]) A[++A[0]]=i;
        else      B[++B[0]]=i;
    }

    int b = 1;
    rep1(a, A[0])
    {
        if (b > B[0])
            cout << A[a] << " " << B[1] << " " << 0 << endl;
        while (b <= B[0])
        {
            if (S[A[a]] < S[B[b]])
            {
                cout << A[a] << " " << B[b] << " " << S[A[a]] << endl;
                S[B[b]]-=S[A[a]];
                break;
            }
            else
            {
                cout << A[a] << " " << B[b] << " " << S[B[b]] << endl;
                S[A[a]]-=S[B[b]];
                b++;
            }
        }
    }



    return 0;
}
