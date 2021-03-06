//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

int n,m,a,b,graph[4010][4010],ct[4010],ans=100000000;

int main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> a >> b;
		graph[a][b] = graph[b][a] = true;
		ct[a]++;
		ct[b]++;
	}

	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(graph[i][j])
				for(int k=1;k<=n;k++)
					if(graph[j][k] && graph[i][k])
						ans = min(ans, ct[i] + ct[j] + ct[k]);
					
	if(ans==100000000)
		cout << "-1\n";
	else
		cout << ans-6 << '\n';
}
