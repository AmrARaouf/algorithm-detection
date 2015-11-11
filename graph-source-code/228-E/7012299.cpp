//Language: GNU C++


#include <bits/stdc++.h>


using namespace std;

vector<vector<bool> > gauss(  vector<vector<bool> > MM ){

    vector<vector<bool> > M = MM;

    int n  = M.size(),  m = M[0].size();
    int col = 0;
    for(int i =  0 ; col<m-1 && i<n ;col++){
        for(int j = i ; j<n ;j++){
            if(M[j][col]==1){
                swap(M[j] , M[i]);
                break;
            }
        }
        if(M[i][col] == 0)    continue;
        for(int j = 0 ; j<n ;j++) if(j!=i){
            if(M[j][col]){
                for(int k =  0 ; k<m ;k++)  M[j][k] = M[j][k]^M[i][k];
            }
        }
        i++;
    }
    return M;
}


int main(){
   // freopen("in.c","r" ,  stdin);
    //freopen("out.c","w" ,  stdout);

    int n, m,x,y,z;

    cin>>n>>m;

    vector<bool> tt(n+1 , 0);

    vector<  vector<bool>  >  MM( m , tt  );

    for(int i = 0  ; i<m ;i++){
        scanf("%d%d%d",&x,&y,&z);
        x-- , y--;
        MM[i][x] = 1 ,  MM[i][y] = 1 , MM[i][n] = z^1;
    }


    MM = gauss(MM);
    n = MM.size();
    m = MM[0].size();


    vector<int> ans;

    /*for(int i =  0 ; i<n ;i++){
        for(int j = 0 ; j<m ;j++){
            cout<<MM[i][j]<<" ";
        }
        cout<<endl;

    }*/


    for(int i = 0  ; i<n ;i++){
        int first_one=-1;
        for(int j =  0 ; j<m ;j++){
            if(MM[i][j] == 1) {
               first_one = j;
               break;
            }
        }
        if(first_one==-1){
           // cout<<i<<"--";
            continue;
        }



        if(first_one == m-1)    {
            cout<<"Impossible"<<endl;
            return 0;
        }

        if(i<min(n, m-1)){

            if(MM[i][m-1] )  ans.push_back( first_one);
        }


    }

//    cout<<endl;

    sort(ans.begin() , ans.end());

    cout<<ans.size()<<endl;
    for(int i = 0  ; i<ans.size() ;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}
