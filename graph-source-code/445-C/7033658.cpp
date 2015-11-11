//Language: GNU C++0x


#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <fstream>

#define PI 3.14159265359

using namespace std;
typedef unsigned long long ull;

template <typename T>
void print2dvector(vector< vector<T> > v)
{
    cout << "A 2d vector:" << endl;
    int a = v.size();
    int b = v[0].size();

    if (a <= 15 && b <= 15)
    {
        for (int i=0; i<a; i++)
        {
            for (int j=0; j<b; j++)
            {
                cout << setw(4) << v[i][j];
            }
            cout << endl;
        }

    }

    if (a > 15 && b > 15)
    {
        for (int i=0; i<9; i++)
        {
            for (int j = 0; j<9; j++)
            {
                cout << setw(4) << v[i][j];
            }
            cout << "   " << ".   .   ." << setw(4) << v[i][b-3] << setw(4) << v[i][b-2] << setw(4) << v[i][b-1] << endl;
        }

        for (int i=0; i<15; i++)
        {
            cout << setw(4) << '.';
        }
        cout << endl;

        for (int i=a-3; i<a; i++)
        {
            for (int j = 0; j<9; j++)
            {
                cout << setw(4) << v[i][j];
            }
            cout << "   " << ".   .   ." << setw(4) << v[i][b-3] << setw(4) << v[i][b-2] << setw(4) << v[i][b-1] << endl;
        }
    }

    if (a>15)
    {
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<b; j++)
            {
                cout << setw(4) << v[i][j];
            }
            cout << endl;
        }

        for (int i=0; i<b; i++)
        {
            cout << setw(4) << '.';
        }
        cout << endl;

        for (int i=a-3; i<a; i++)
        {
            for (int j = 0; j<b; j++)
            {
                cout << setw(4) << v[i][j];
            }
            cout << endl;
        }

    }

    if (b>15)
    {
        for (int i=0; i<a; i++)
        {
            for (int j = 0; j<9; j++)
            {
                cout << setw(4) << v[i][j];
            }
            cout << "   " << ".   .   ." << setw(4) << v[i][b-3] << setw(4) << v[i][b-2] << setw(4) << v[i][b-1] << endl;
        }
    }

}

template <typename T>
void printvector(vector<T> v)
{
    cout << "A 1d vector:" << endl;
    int a = v.size();

    if (a <= 15)
    {
        for (int i=0; i<a; i++)
        {
            cout << setw(4) << v[i];
        }
    }

    else
    {
        for (int i=0; i<9; i++)
        {
            cout << setw(4) << v[i];
        }
        cout << "   " << ".   .   ." << setw(4) << v[a-3] << setw(4) << v[a-2] << setw(4) << v[a-1];
    }

    cout << endl;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n, 0);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }

    double ans = 0;
    int a, b, c;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        ans = max(ans, 1.0*(v[a-1]+v[b-1])/c);
    }

    printf("%.12lf", ans);
    return 0;
}
