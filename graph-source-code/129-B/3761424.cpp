//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

vector<int> student[105];
int n,m,group;
int a,b;
int i;



int main()
{	
	
	bool over[105];
	bool con=false;
	memset(over,0,sizeof(over));
	
	//input
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		student[a].push_back(b);
		student[b].push_back(a);
	}


	//process
	group=0;
	while(1)
	{	
		con=false;		

		//check who will be reprimanded
		for(i=1;i<=n;i++)
		{
			if(student[i].size()==1&&!over[i])
			{
				con=true;
				over[i]=true;
			}
		}

		//kick those students
		if(con)
		{
			for(i=1;i<=n;i++)
			{
				if(!over[i])
				{
					for(a=student[i].size()-1;a>=0;a--)
					{
						b=student[i][a];
						if(over[b])
						{
							//student[i].erase(student[i].end()-(student[i].size()-a-1));

							swap(student[i][a],student[i][student[i].size()-1]);
							student[i].pop_back();
						}
					}
				}
			}
		}
		//if no more students who are reprimanded
		else	break;


		group++;
	}
	cout<<group<<"\n";
	return 0;
}
