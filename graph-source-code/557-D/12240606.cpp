//Language: GNU C++


#include <iostream>
#include <vector>

typedef long long llong;
const int MAXX = 1000000;

struct Node
{
    unsigned int mOddCnt;
    unsigned int mEvenCnt;
    int mDepth;
	Node(){ mOddCnt = mEvenCnt = 0; mDepth = -1;}
};

std::vector<std::pair<Node, std::vector<unsigned int> > > graph;
llong gCycleCnt[4] = {0, 0, 0,0};
void deepSearch(unsigned int aNodeCnt);
void solve(llong N);

int main()
{
	llong n = 0, m = 0;
	std::cin >> n >> m;
	if(m == 0) {std::cout <<3<<" "<< n *(n-1)*(n-2)/6 << std::endl; return 0;}
	graph.resize(n);
	//for(unsigned int i = 0; i < n; ++ i) graph[i].second.reserve(m);
	for(unsigned int i = 0; i < m; ++ i)
	{
		unsigned int t1, t2;
		std::cin >> t1 >> t2;
		t1 --, t2 --;
		graph[t1].second.push_back(t2);
		graph[t2].second.push_back(t1);
	}
	solve(n);
    return 0;
}

void deepSearch(unsigned int aNodeID)
{
    for(unsigned int i = 0, n = graph[aNodeID].second.size(); i < n; ++ i)
    {
        Node& nd = graph[graph[aNodeID].second[i]].first;
	
		if(nd.mDepth < 0)
        {
			nd.mDepth = graph[aNodeID].first.mDepth + 1;
            deepSearch(graph[aNodeID].second[i]);
            gCycleCnt[1] += llong(nd.mEvenCnt) * llong(graph[aNodeID].first.mEvenCnt + 1) + llong(nd.mOddCnt) * llong(graph[aNodeID].first.mOddCnt);
            graph[aNodeID].first.mEvenCnt += nd.mEvenCnt;
            graph[aNodeID].first.mOddCnt += nd.mOddCnt;
        }
		else if(nd.mDepth < graph[aNodeID].first.mDepth)
        {
			int t = graph[aNodeID].first.mDepth - nd.mDepth + 1;
            gCycleCnt[0] += (t & 1) ? 1 : 0;
        }
    }
    std::swap(graph[aNodeID].first.mEvenCnt, graph[aNodeID].first.mOddCnt);
    graph[aNodeID].first.mOddCnt ++;
}

void solve(llong n)
{
	for(unsigned int i = 0; i < n; ++ i)
	{
		if(graph[i].first.mDepth < 0)
		{
			graph[i].first.mDepth = 0;
			deepSearch(i);
			if(graph[i].second.size() == 0) gCycleCnt[3] ++;
		}
	}
	if( gCycleCnt[0] ) std::cout << 0 <<' '<< gCycleCnt[0]<<std::endl;
	else if(gCycleCnt[1]) std::cout << 1 << ' ' << gCycleCnt[1] << std::endl;
	else std::cout << 2 << ' ' << ((n - gCycleCnt[3]) * (n - 2)) / 2 << std::endl;
	return;
}
