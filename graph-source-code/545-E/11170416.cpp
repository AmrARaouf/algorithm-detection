//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(){
	int t,n,m,i,j,x,y;
	bool *p;
	long long k,s;

	t=1;

	while(t--){
		scanf("%d", &n);
		scanf("%d", &m);

		vector < vector < pair <pair<int,int>,int> > > v;

		v.resize(n+1);

		for(x=0;x<m;x++){
			scanf("%d", &i);
			scanf("%d", &j);
			scanf("%d", &y);

			v[i].push_back(make_pair(make_pair(y,j),x+1));
			v[j].push_back(make_pair(make_pair(y,i),x+1));
		}

		/*for(i=1;i<v.size();i++){
			for(j=0;j<v[i].size();j++)
				printf("%d %d %d\n", v[i][j].first.first, v[i][j].first.second,v[i][j].second);

			printf("\n");
		}*/

		scanf("%d", &x);

		p=(bool*)calloc(n+1,sizeof(bool));

		priority_queue< pair<pair<long long,int>,pair<int,int> > > q;

		q.push(make_pair(make_pair(0,x),make_pair(0,0)));

		vector <int> u;

		s=0;

		while(n>0){
			k=-q.top().first.first;
			i=q.top().first.second;
			j=q.top().second.second;
			y=-q.top().second.first;

			//printf("%lld %d %d\n", k,i,j);

			q.pop();

			if(p[i]==0){
				u.push_back(j);
				s+=y;
				//printf("%lld\n", s);
				n--;
				p[i]=1;
				for(j=0;j<v[i].size();j++)
					if(p[v[i][j].first.second]==0){
						//printf("%d %d %d\n", i, k+v[i][j].first, v[i][j].second);
						q.push(make_pair(make_pair(-(k+v[i][j].first.first),v[i][j].first.second),make_pair(-v[i][j].first.first,v[i][j].second)));
					}
					else;

				//printf("\n");
			}
		}

		cout << s;

		printf("\n");

		for(i=1;i<u.size();i++)
			printf("%d ", u[i]);

		printf("\n");
	}

	return 0;
}