//Language: GNU C++0x


#include <bits/stdc++.h>
using namespace std;

const int N = 62 * 62 + 10;
int m, V = 0, n = N - 10, seen[N], start = -1, G[N][N];
set<string> vertices;
vector<int> circuit;

int f(string t)
{
	int ret = 0;
	for(int i=0, mul = 62; i<2; i++, mul /= 62)	{
		if(t[i] >= 'a' and t[i] <= 'z')	{
			ret += (t[i] - 'a') * mul;
		}	else if(t[i] >= 'A' and t[i] <= 'Z')	{
			ret += (t[i] - 'A' + 26) * mul;
		}	else	{
			ret += (t[i] - '0' + 52) * mul;
		}
	}
	return ret;
}

string g(int num)	{
	string ret = "**";
	for(int i=0, dv = 1; i<2; i++, dv *= 62)	{
		int tnum = (num / dv) % 62;
		if(tnum < 26)	{
			ret[1-i] = ('a' + tnum);
		}	else if(tnum < 52)	{
			ret[1-i] = ('A' + tnum - 26);
		}	else	{
			ret[1-i] = ('0' + tnum - 52);
		}
	}
	return ret;
}

int out(int node)
{
	int ret = 0;
	for(int i=0; i<n; i++)	{
		if(G[node][i])	{
			ret+=G[node][i];
		}
	}
	return ret;
}

int inn(int node)
{
	int ret = 0;
	for(int i=0; i<n; i++)	{
		if(G[i][node])	{
			ret+=G[i][node];
		}
	}
	return ret;
}

void dfs(int node)
{
	for(int next=0; next<n; next++)	{
		while(G[node][next])	{
			G[node][next]--;
			dfs(next);
		}
	}
	circuit.push_back(node);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	memset(G, 0, sizeof G);
	for(int i=0; i<m; i++)	{
		string s;
		cin >> s;
		string t1 = ""; t1+= s[0]; t1+= s[1]; string t2 = ""; t2+= s[1]; t2+= s[2];
		vertices.insert(t1);
		vertices.insert(t2);
		G[f(t1)][f(t2)]++;
	}
	V = vertices.size();
	memset(seen, 0, sizeof seen);	
	int cnt = 0;
	for(int i=0; i<N; i++)	{
		if(out(i) != inn(i))	{
			if(abs(out(i) - inn(i)) != 1)	{
				cout << "NO\n";
				return 0;
			}
			cnt++;
			if(out(i) > inn(i))	{
				start = i;
			}
		}
	}
	if(start == -1)	{
		start = f(*(vertices.begin()));
	}
	if(cnt != 0 and cnt != 2)	{
		cout << "NO\n";
		return 0;
	}
	memset(seen, 0, sizeof seen);
	dfs(start);
	reverse(circuit.begin(), circuit.end());
	if(circuit.size() == m + 1)	{
		cout << "YES" << endl;
	}	else	{
		cout << "NO" << endl;
		return 0;
	}
	string temp;
	for(int i: circuit)	{
		temp = g(i);
		cout << temp[0];
	}
	cout << temp[1] << "\n";
}
