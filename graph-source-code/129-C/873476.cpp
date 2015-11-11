//Language: GNU C++


    #include<cstdio>
    #include<vector>
    #include<algorithm>
    #include<cstring>
    #include<queue>
    using namespace std;
    char s[8][8];
    int dx[9]={1,1,1,-1,-1,-1,0,0,0};
    int dy[9]={0,-1,1,0,-1,1,0,-1,1};
    struct enemy
    {
        int x,y;
    }en[100];
    int len;
    bool has(int x,int y,int t)
    {
        int i;
        for(i=0;i<len;i++)
        {
            int xx=en[i].x+t;
            int yy=en[i].y;
            if(xx==x&&yy==y)return 1;
        }
        return 0;
    }
    struct node
    {
        int x,y,time;
    }n1,n2;
    queue<node>qu;
    bool hash[10][10][10];
    void push()
    {
        if(hash[n2.x][n2.y][n2.time])return;
        hash[n2.x][n2.y][n2.time]=1;
        qu.push(n2);
    }
    void bfs()
    {
        n2.x=7;
        n2.y=0;
        n2.time=0;
        push();
        int i;
        while(!qu.empty())
        {
            n1=qu.front();
            qu.pop();
            if(n1.time>=8)break;
            for(i=0;i<9;i++)
            {
                n2.x=n1.x+dx[i];
                n2.y=n1.y+dy[i];
                if(n2.x<0||n2.x>7||n2.y<0||n2.y>7)continue;
                n2.time=n1.time+1;
                if(has(n2.x,n2.y,n1.time))continue;
                if(has(n2.x,n2.y,n2.time))continue;
                push();
            }
        }
        if(n1.time>=8)
        {
            puts("WIN");
        }
        else puts("LOSE");
    }
    int main()
    {
        int i,j;
        for(i=0;i<8;i++)
        {
            scanf("%s",s[i]);
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(s[i][j]=='S')
                {
                    en[len].x=i;
                    en[len].y=j;
                    len++;
                }
            }
        }
        bfs();
        return 0;
    }