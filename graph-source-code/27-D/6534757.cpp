//Language: GNU C++


#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;
#define LL			long long int
#define PB			push_back
#define ALL(vec)		(vec).begin(), (vec).end()
#define SZ(v)			((LL)(v).size())
#define MP			make_pair
//#define debug
#ifndef debug
	#define VAR(a, b)		__typeof(b) a=(b)
	#define EACH(i, c)		for(__typeof((c).begin()) i=(c).begin(); i!= (c).end(); ++i)
#else
	#define VAR(a, b)		decltype(b) a=(b)
	#define EACH(i, c)		typedef decltype(c) obj_type; \
	for(obj_type::iterator i=c.begin(); i!= (c).end(); ++i)

#endif
#define REP(i, to)		for(LL i = 0; i< (LL)(to); ++i)
#define REPO(i, to)		LL i = 0; for(; i< (LL)(to); ++i)
#define FOR(i, a, b)		VAR(i, a); for(; i <=b; ++i)
#define FORD(i, a, b)		VAR(i, a); for(; i >=b; --i)
#define MEMSET(p, c)		memset(p, c, sizeof(p))

struct Node
{
    long left, right;
	vector<LL> status;
    struct Node * leftChild, * rightChild;
};

class SegmentTree
{
public:
	SegmentTree(long left, long right)
	{ 
		tot = 0;
		buildTree(left, right);
	}

	vector<LL> query(long left, long right)
	{ return queryHelper(left, right, &(treeArr[1])); }

	void update(long newVal, long index)
	{ updateHelper(newVal, index, &(treeArr[1])); }
	
private:
	
	// element is passed from segArr[]
	// left is usually start from 0 which use all the elements of segArr
	// for example left = 0 right = 20
	// Node such as [0, 20] [0,10] [11, 20].... [0, 0] [1, 1] [2, 2] [3, 3] [4, 4] 
	// is stored in an array starting from  treeArr from index 1
	// highest is stored in each Treenode of the maxVal of this segment 

	void buildTree(long left, long right)
	{
		long size = right - left, mid = (left + right)/2;
		struct Node * root = treeArr + (++tot);
		root->left = left;
		root->right = right;
		root->status.resize(2);
		REP(iterI, SZ(root->status))
		{ root->status[iterI] = 0; }
		if( size == 0)
			root ->leftChild = root ->rightChild = NULL;
		else
		{
			root->leftChild = treeArr + tot + 1;
			buildTree(left, mid );

			root->rightChild = treeArr + tot + 1;
			buildTree(mid + 1, right);
		}
	}

	// query get the max value from segment[left, right] 
	vector<LL> queryHelper(long left, long right, struct Node * root)
	{
		if(root->left == left && root->right == right)
			return root->status;
		else
		{
			long mid = (root->left + root->right)/2;
			if(right <= mid)
				return queryHelper(left, right, root->leftChild);
			else if(left >= mid + 1)
				return queryHelper(left, right, root->rightChild);
			else
			{
				vector<LL> leftQ = queryHelper(left, mid, root->leftChild); 
				vector<LL> rightQ = queryHelper(mid+1, right, root->rightChild);
				vector<LL> tot;
				REP(iterI, SZ(leftQ))
				{ tot.push_back(leftQ[iterI]^ rightQ[iterI]);	}
				return tot;
			}    
		}
	}

	// change a single element of segArr[index]
	// update all the corresponding the tree's ancestor's
	// Node highest val to newHighest
	void updateHelper(long newVal, long index, struct Node * root)
	{
		if(root->left == root->right)
		{
			root->status[newVal/64] |= ((LL)(1)<<(newVal%64)); 
			return;
		}
		long mid = (root->left + root->right)/2;
		if(index > mid)
			updateHelper(newVal, index, root->rightChild);
		else
			updateHelper(newVal, index, root->leftChild);
		vector<LL> & leftQ = root->leftChild->status;
		vector<LL> & rightQ = root->rightChild->status;
		REP(iterI, SZ(leftQ))
		{ root->status[iterI] = leftQ[iterI]^ rightQ[iterI];}
	}

	struct Node treeArr[1000001];
	long tot;
};

class disjointSet
{
public:
	// size is the used size
	// should be smaller than the pre allocated size
	// STOREMAX 
	// node val is between 0 to size
	// get rank can not get the absolute 
	// if not call findAncestor frist
    disjointSet(long size)
    {
		clear();
		for(long iter = 0; iter <= size; ++ iter)
			makeSet(iter);
    }

    void unionSet(long val1, long val2)
    {    
        long res1 = findAncestor(val1), res2 = findAncestor(val2);
        if(res1 != res2)
        {
            father[res1] = res2;
            rank[res1] = (rank[val1] + rank[val2] + 1) %2;
        }
    }

    long findAncestor(long val)
    {
        if(father[val]!= val)
        {
            long tempFather = father[val];
            father[val] = findAncestor(father[val]);
            rank[val] = (rank[val] + rank[tempFather]) % 2;
        }
        return father[val];
    }

	long getRank(long val)
	{ return rank[val]; }

	void clear()
    {    
        memset(father, -1, sizeof(father));
        memset(rank, 0, sizeof(rank));
    }

private:
	static const long STOREMAX = 100001; 
    long father[STOREMAX];
    long rank[STOREMAX];

	void makeSet(long val)
    {    
        father[val] = val;
        rank[val] = 0;
    }
};

int main()
{
#ifdef debug
	ifstream cin("a.in");
	ofstream cout("a.out");
#endif
	LL nodeNum, roadNum;
	cin>>nodeNum>>roadNum;
	LL from, to;
	SegmentTree* st = new SegmentTree(1, nodeNum);
	disjointSet dSet(roadNum); 
	bool failF = false;
	for(int roadI = 0; roadI < roadNum; ++ roadI)
	{
		cin>>from>>to;
		if(failF)
			continue;
		int newFrom = min(from, to);
		int newTo = max(from, to);
		vector<LL> status = st->query(newFrom + 1, newTo - 1);
		vector<LL> frontS = st->query(newFrom, newFrom);
		vector<LL> endS = st->query(newTo, newTo);
		REP(stI, SZ(status))
		{ status[stI] &= ~(frontS[stI] | endS[stI]); }

		REP(staI, SZ(status))
		{ 
			REP(bitI, 64)
			{
				if( status[staI] & ((LL)(1)<<bitI))
				{
					int val1 = (staI <<6) + bitI;
					if(dSet.findAncestor(val1) == dSet.findAncestor(roadI) &&
						dSet.getRank(val1) == dSet.getRank(roadI))
					{
						failF = true;
						goto outside;
					}
					dSet.unionSet(val1, roadI);
				}
			}
		}
		st->update(roadI, newFrom);
		st->update(roadI, newTo);
outside:
		;
	}

	if(failF)
		cout<<"Impossible"<<endl;
	else
	{
		REP(roadI, roadNum)
		{ 
			dSet.findAncestor(roadI);
			cout<<(dSet.getRank(roadI)?"i":"o"); 
		}
		cout<<endl;
	}
	return 0;
}