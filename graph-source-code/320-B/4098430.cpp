//Language: MS C++


#include <iostream>
using namespace std;
struct interval{
    long long l,r;
};

bool path_array[100]={false};
bool path_end[100]={false};
interval interval_array[100];
int n,c,i,array_index=0;
long long x,y;

int istherepath(interval in1,interval in2)
{
    if(((in1.l>in2.l) && (in1.l<in2.r))||((in1.r>in2.l) && (in1.r<in2.r)))
    {
        return 1;
    }else{
        return 0;
    }
}
void akhtar(int a)
{
    int k;
    bool tapilir=false;
    path_array[a]=true;
    for(k=0;k<array_index;k++)
    {
        if(istherepath(interval_array[a],interval_array[k]) && !path_array[k] && !path_end[k])
        {
            akhtar(k);
            tapilir=true;
        }
    }
    path_end[a]=true;
    if(tapilir) akhtar(a);
    else return;
}
int main()
{
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c>>x>>y;
        if(c==1)
        {
            interval_array[array_index].l=x;
            interval_array[array_index].r=y;
            array_index++;
        }else{
            x--;
            y--;
            for(c=0;c<array_index;c++) 
            {
                path_array[c]=false;
                path_end[c]=false;
            }
            akhtar(x);
            if(path_end[y]) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
