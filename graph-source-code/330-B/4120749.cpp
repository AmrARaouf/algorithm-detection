//Language: GNU C++


#include<iostream>

using namespace std;

bool used[1001];
int N, M;

int main()
{
	cin >> N >> M;
	int a, b;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		used[a] = true;
		used[b] = true;
	}
	cout << N-1 << endl;
	for(int i = 1; i <= N; i++)
	{
		if(!used[i])
		{
			for(int j = 1; j <= N; j++)
				if(i != j)
					cout << i << " " << j << endl;
			break;
		}
	}
}
