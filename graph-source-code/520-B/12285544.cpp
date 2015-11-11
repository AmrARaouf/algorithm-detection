//Language: GNU C++


#include <iostream>
#include <vector>

#define MAX 33333

using namespace std;

bool b[MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    while (m > n)
    {
        if (m % 2 == 0)
            m /= 2;
        else
            m++;
        cnt++;
    }
    cnt += n-m;
    cout << cnt << endl;
    return 0;
}
 	  				 	 	 		  							  					