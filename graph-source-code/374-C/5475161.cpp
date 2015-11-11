//Language: GNU C++


#include <cstdio>

#define N 1000
#define MX 1000000000

int a[N][N], n, m, i, j, max;
char c[N][N];
bool b[N][N];

int go(int x, int y)
{
	if (a[x][y])
		return a[x][y];
	if (b[x][y])
		return a[x][y] = max = MX;
	int mr = 0;
	if (max < MX)
	{
		b[x][y] = 1;
		char cc;
		switch (c[x][y])
		{
			case 'D': cc = 'I'; break;
			case 'I': cc = 'M'; break;
			case 'M': cc = 'A'; break;
			case 'A': cc = 'D'; break;
		}
		int r = 0;
		if (x && c[x - 1][y] == cc)
		{
			r = go (x - 1, y);
			if (r > mr)
				mr = r;
		}
		if (x < n - 1 && c[x + 1][y] == cc)
		{
			r = go (x + 1, y);
			if (r > mr)
				mr = r;
		}
		if (y && c[x][y - 1] == cc)
		{
			r = go (x, y - 1);
			if (r > mr)
				mr = r;
		}
		if (y < m - 1 && c[x][y + 1] == cc)
		{
			r = go (x, y + 1);
			if (r > mr)
				mr = r;
		}
		b[x][y] = 0;
	}
	return a[x][y] = mr + 1;
}

int main()
{
	scanf("%d%d", &n, &m);

	for (i = 0; i < n; i ++)
		scanf("%s", c[i]);

	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			if (c[i][j] == 'D' && !a[i][j])
			{
				int r = go(i, j);
				if (r > max)
					max = r;
			}

	printf(max >= MX ? "Poor Inna!\n" : !(max / 4) ? "Poor Dima!\n" : "%d\n", max / 4);

	return 0;
}
