//Language: GNU C++


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,b,i,num,x;
    while(~scanf("%d%d",&a,&b))
    {
        num=0;
        x=1;
        if(a>=b)
        {
            printf("%d\n",a-b);
        }
        else
        {
            while(a<b)
            {
                a*=2;
                x*=2;
                num++;
            }
            i=a-b;
            while(i>1)
            {
                num+=(i/x);
                i%=x;
                x/=2;
                /*else if(i==0||x==1)
                    break;
                else
                    x/=2;*/
            }
            num+=i;
            printf("%d\n",num);
        }
    }
    return 0;
}


                                                                                                                                                                                                                                       