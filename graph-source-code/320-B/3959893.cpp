//Language: GNU C++


#include<iostream>
using namespace std;

class pa
{
public:
    long long x,y;
    int list[200];
    int size;
    pa()
    {
        size=0;
    };
    void get()
    {
        cin>>x>>y;
        
    };
    bool search(int a)
    {
        for(int i=0;i<size;i++)
            if(list[i]==a)
                return true;
        return false;
    };
};

pa add(pa a,pa b)
{
    bool ch;
    for(int i=0;i<b.size;i++)
    {
        ch=true;
        for(int j=0;j<a.size;j++)
            if(a.list[j]==b.list[i])
                ch=false;
        if(ch)
        {
            a.list[a.size]=b.list[i];
            a.size++;
        }
    }
    return a;
}

int main()
{
    int n;
    cin>>n;
    pa p[200];
    int ch;
    int count=0;//ta hala add shodan
    int f,e;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        if(ch==1)
        {
            p[count].get();
            for(int k=0;k<count;k++)
            {
                if((p[k].x<p[count].y and p[k].x>p[count].x) or (p[k].y<p[count].y and p[k].y>p[count].x))
                {
                    bool ch=true;
                    for(int j=0;j<p[k].size;j++)
                        if(p[k].list[j]==count)
                            ch=false;
                    if(ch)
                    {
                        p[k].list[p[k].size]=count;
                        p[k].size++;
                    }
                }
                if((p[k].x<p[count].y and p[k].y>p[count].y) or (p[k].y>p[count].x and p[k].x<p[count].x))
                {
                    bool ch=true;
                    for(int j=0;j<p[count].size;j++)
                        if(p[count].list[j]==k)
                            ch=false;
                    if(ch)
                    {
                        p[count].list[p[count].size]=k;
                        p[count].size++;
                    }
                }
            }
            count++;
        }
        else
        {
            cin>>f>>e;
            for(int i=0;i<p[f-1].size;i++)
            {
                p[f-1]=add(p[f-1],p[p[f-1].list[i]]);
            }
            if(p[f-1].search(e-1))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}