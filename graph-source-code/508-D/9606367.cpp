//Language: MS C++


#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int const N = 100000;

int n, degIn[N], degOut[N], rnd;
string s;
vector<int> e[N], ans;
vector<char> out;

int get(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    if(c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    return c - 'A' + 36;
}

void addEdges(string s)
{
    int from, to;
    from = get(s[0])*100 + get(s[1]);
    to = get(s[1])*100 + get(s[2]);
    e[from].push_back(to);
    rnd = from;
    ++degIn[from];
    ++degOut[to];
}

void bad()
{
    cout << "NO";
    exit(0);
}

void dfs(int u)
{
    while(e[u].size())
    {
        int to = e[u].back();
        e[u].pop_back();
        dfs(to);
    }
    ans.push_back(u);
}

char getChar(int num)
{
    if(num < 10)
        return (char)(num + '0');
    if(num < 36)
        return (char)(num - 10 + 'a');
    return (char)(num - 36 + 'A');
}

int main()
{
#ifdef _DEBUG
    freopen("in.in","r",stdin);
#endif

    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        cin >> s;
        addEdges(s);
    }
    
    int start = -1;
    int end = -1;

    for(int i=0;i<N;++i)
    {
        if(degIn[i] > degOut[i])
        {
            if(start != -1 || degIn[i] -1 > degOut[i])
            {
                bad();
            }
            start = i;
        }
        if(degOut[i] > degIn[i] || degOut[i] - 1 > degIn[i])
        {
            if(end != -1)
            {
                bad();
            }
            end = i;
        }
    }

    if(end == -1 && start != -1 || start == -1 && end != -1)
        bad();
    if(end == -1 && start == -1)
    {
        dfs(rnd);
        reverse(ans.begin(), ans.end());
        out.push_back(getChar(rnd/100));
        out.push_back(getChar(rnd%100));
        for(int i=1;i<ans.size();++i)
        {
            out.push_back(getChar(ans[i]%100));
        }
        if(out.size() != n+2)
            bad();
        cout << "YES" << endl;
        for(int i=0;i<out.size();++i)
        {
            printf("%c",out[i]);
        }
        return 0;
    }
    else
    {
        e[end].push_back(start);
        dfs(end);
    }

    int delEdge;
    reverse(ans.begin(), ans.end());
    for(int i=1;i<ans.size();++i)
    {
        if(ans[i-1] == end && ans[i] == start)
        {
            delEdge = i;
            break;
        }
    }
    ans.pop_back();// ???
    out.push_back(getChar(start/100));
    out.push_back(getChar(start%100));
    for(int i=delEdge+1;i<ans.size();++i)
    {
        out.push_back(getChar(ans[i]%100));
    }
    for(int i=0;i<delEdge;++i)
    {
        out.push_back(getChar(ans[i]%100));
    }
    if(out.size() != n+2)
        bad();
    cout << "YES" << endl;
    for(int i=0;i<out.size();++i)
    {
        printf("%c",out[i]);
    }

    return 0;
}