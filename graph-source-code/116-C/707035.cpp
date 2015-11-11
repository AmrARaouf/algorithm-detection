//Language: MS C++


#include<stdio.h>
int main()
{
	int n;
	int e[2002];
	int i;
	int levmax=-1;
	int max,t;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&e[i]);
	}
	for(i=1;i<=n;i++)
	{
		t=e[i];
		max=1;
		while(1)
		{
			if(t==-1)
			{
				if(max>levmax)
					levmax=max;
				break;
			}
			t=e[t];
			max++;
		}
	}
	printf("%d",levmax);
	return 0;
}