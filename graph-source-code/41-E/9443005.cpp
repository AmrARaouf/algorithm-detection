//Language: GNU C++


#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#define rep(_m,s,e) for(int _m=s;_m<e;_m++)
typedef long long ll;
int  toInt(string s)   {int r=0; istringstream sin(s); sin>>r; return r;}
ll   toInt64(string s) {ll r=0; istringstream sin(s); sin>>r; return r;}
double  toDouble(string s){double r=0; istringstream sin(s); sin>>r; return r;}
string toString(ll n) {string s,s1; while (n / 10 > 0){ s += (char)((n%10) + 48); n/=10;} s += (char)((n%10) + 48); n/=10; s1 = s; rep(i,0,s.length()) s1[(s.length()-1)-i] = s[i]; return s1;}
bool isUpperCase(char c){return c >= 'A' && c <= 'Z';}
bool isLowerCase(char c){return c >= 'a' && c <= 'z';}
bool isLetter(char c)   {return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';}
bool isDigit(char c)    {return c >= '0' && c <= '9';}
char toLowerCase(char c){return (isUpperCase(c))?(c + 32) : c;}
char toUpperCase(char c){return (isLowerCase(c))?(c - 32) : c;}
ll gcd(ll a, ll b) {if(!a) return b; return gcd(b%a, a);}

bool matrix[101][101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	for (int i = 1; i <= n/2; i++)
		for (int j = n/2+1; j <= n; j++)
			matrix[i][j] = matrix[j][i] = 1;
	vector<pair<int, int> > v;
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			if (matrix[i][j])
				v.push_back(make_pair(i, j));
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << endl;
}

