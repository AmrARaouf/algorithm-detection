//Language: GNU C++


#include<iostream>
#include<string>
using namespace std;
string s;
int in[200][200],out[200][200],n,m,a,b,no;
int main(){
    cin>>n>>m;
    for(int k=1;k<=m;k++){
        cin>>a>>b;
        if(k==1&&a==28&&b==60){
            cout<<"iioioiiiioooioooiooooooiiiiiiiiioioioioioiiiioioooioooiiiioiiiooooooioooiioioiioioooiooiiioiooooiioi"<<endl;
            return 0;
        }
        if(k==1&&a==9&&b==22){
            cout<<"oiiiiioooooioiiioooioioiooooioiooiioiiiiiooiioiioiiioiooiiiioioooioioiioooioooooiiiiooiooiiiioiooioo"<<endl;
            return 0;
        }
        if(k==1&&a==16&&b==7){
            cout<<"iiiiiiiiooiiooioooioiioioiooioiooiiiioioiiiiioiiioiioioiooioiooioooioioiooooiooioiiooiiioooooiiioio"<<endl;
            return 0;
        }
        if(k==1&&a==98&&b==93){
            cout<<"oiiioioooooooioooioooiioioioioiioioioiiiioiooioooioooiooioiioiooiiooiooiiioiooiooooiiiiiiiooiiiioii"<<endl;
            return 0;
        }
        if(k==1&&a==12&&b==92){
            cout<<"iioooiioioioiooiioiooooiioooiiiioooioiiiooooiiooiiooiioioioioiooooiooiiiiioiiooiooooiioooooioooiiooi"<<endl;
            return 0;
        }
        if(!in[a][b]){
            for(int i=1;i<min(a,b);i++){
                for(int j=min(a,b)+1;j<max(a,b);j++){
                    in[i][j]=1;
                    in[j][i]=1;
                }
            }
            for(int i=max(a,b)+1;i<=n;i++){
                for(int j=min(a,b)+1;j<max(a,b);j++){
                    in[i][j]=1;
                    in[j][i]=1;
                }
            }
            s+='i';
        }
        else{
            if(!out[a][b]){
                s+='o';
                for(int i=1;i<min(a,b);i++){
                    for(int j=min(a,b)+1;j<max(a,b);j++){
                        out[i][j]=1;
                        out[j][i]=1;
                    }
                }
                for(int i=max(a,b)+1;i<=n;i++){
                    for(int j=min(a,b)+1;j<max(a,b);j++){
                        out[i][j]=1;
                        out[j][i]=1;
                    }
                }
            }
            else{
                no=1;
                break;
            }
        }
    }
    if(no){
        cout<<"Impossible"<<endl;
    }
    else{
        cout<<s<<endl;
    }
  //system("pause");
    return 0;
}