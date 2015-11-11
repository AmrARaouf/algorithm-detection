//Language: MS C++


#include <iostream>
//#include <algorithm>
#include <cstdio>
//#include <cstdlib>
#include <cstring>	// memset()�� ���� ����
//#include <climits>
//#include <cmath>

using namespace std;

const int N=50;

struct stack{
    static int n;
    int x,y;
};

struct point{
    int x,y;
};

int stack::n=0;

int i,j,k,m,n,l;
char a[N+10][N+10];	// ���� �ִ��� ����� ����
//bool is_cycle[N+10][N+10];
int dir[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};	// �� ������ üũ
bool v[N+10][N+10];	// �湮������ ǥ��
//stack s[N*N+100];
//point fa[N+10][N+10];


void dfs(int i, int j)
{    
    v[i][j]=true;	// �湮����
    for (int k=0; k<4; k++)
    {	// �� ������ üũ
        int x=i+dir[k][0], y=j+dir[k][1];
        if (x>=1 && y>=1 && x<=n && y<=m && a[x][y]=='#' && !v[x][y])
            dfs(x, y);	// ���� �Ѿ�� �ʾҰ�, ���� �ְ�, �Ȱ��� ���̸�
        
    }
}

int main()
{
    cin>>n>>m;
    int cnt=0;	// �� ����
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            a[i][j]=getchar();
            while (a[i][j]!='.' && a[i][j]!='#')
                a[i][j]=getchar();	// �߸�� �Է��� ������ ���Է�
            if (a[i][j]=='#') cnt++;	// �� ���� ���ֱ�
        }
    }
    if (cnt<=2)	// �� ������ 1 �Ǵ� 2�� �ѷ� �ڸ��� �Ұ���
        cout<<-1<<endl;
    else
    {       
        bool is_one=false;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) if (a[i][j]=='#')
            {
                a[i][j]='.';	// ���� �ִµ� �ϴ� ��ٰ� �ĺ���
                
                for (int x=1; x<=n; x++)
                    for (int y=1; y<=m; y++) if (a[x][y]=='#')
                    {	////////////////// �� �ϳ� ��ֺ��� Ž�� ����////////////////
                        memset(v, 0, sizeof(v));	// ��� �� �湮 ���ߴٰ� �ʱ�ȭ�ϰ�
                        dfs(x, y);	// �ѹ� �� ���ƺ�
                        
                        for (int xx=1; xx<=n; xx++)
                            for (int yy=1; yy<=m; yy++) if (a[xx][yy]=='#' && !v[xx][yy])
                            {	// �ִµ� �湮 ���� ���� ������ �ѷ� ������ ��
                                is_one=true;
                                goto end2;
                            }
                            
                        goto end;
                    }////////////////////// Ž�� �� /////////////////////////
                end:;
                a[i][j]='#';	// ��ݴ� �� �ٽ� ����
            }
        
        end2:;
        if (is_one)
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }

    return 0;
}