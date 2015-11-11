//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
int main()
{
    int n; cin >> n;
    vector<ii> black;
    vector<ii> white;

    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a==1)
            black.pb(ii(b, i));
        else
            white.pb(ii(b, i));
    }
    sort(black.begin(), black.end());
    sort(white.begin(), white.end());
    int a=0, b=0;
    while(a<black.size() && b<white.size())
    {
        int mm=min(black[a].first, white[b].first);
        black[a].first-=mm;
        white[b].first-=mm;
        cout << black[a].second+1<<" "<<white[b].second+1<<" "<<mm<<endl;
        if(a==black.size()-1)
        {
            b++;
        }
        else if(b==white.size()-1)
        {
            a++;
        }
        else if(black[a].first==0)
        a++;
        else
            b++;
    }

    return 0;
}
