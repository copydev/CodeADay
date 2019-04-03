#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long

using namespace std;

ll N,M;

unordered_map<ll,ll> pondSize;

ll pondIndex = 2;

ll maxPond;

void dfs(vector<vector<ll>> &mat, vector<vector<ll>> &visit, ll i ,ll j,ll pondIndex){
    if(i<0 || i>=N || j<0 || j>=M || visit[i][j] == 1 || mat[i][j] == 0){
        return;
    }

    // cout<<" i "<<i<<" j "<<j<<endl;
    // for(int i =0;i<N;i++){
    //     for(int j =0;j<M;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    int numRow[] = {1,0,-1,0};
    int colRow[] = {0,1,0,-1};

    visit[i][j] = 1;
    mat[i][j] = pondIndex;
    pondSize[pondIndex] ++;

    for(int p = 0;p<4;p++){
        dfs(mat,visit,i + numRow[p], j+ colRow[p],pondIndex);
    }
}

void countPond(vector<vector<ll>> &mat){
    vector<vector<ll>> visited(N,vector<ll>(M));
    ll pondIndex = 2;
    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            if(mat[i][j] == 1 && visited[i][j] == 0){
                pondSize[pondIndex] = 0;
                dfs(mat,visited,i,j,pondIndex);
                pondIndex++;
            }
        }
    }
}

int main(){
    
    cin>>N>>M;

    vector<vector<ll>> mat(N,vector<ll> (M));
    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            cin>>mat[i][j];
        }
    }

    maxPond = 0;
    
    countPond(mat);
    
    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            unordered_map<ll,ll> check;
            if(mat[i][j] == 0){
                ll temp = 0;
                if(i-1 >= 0){
                    if(mat[i-1][j]!= 0){
                        temp+= pondSize[mat[i-1][j]];
                        check[mat[i-1][j]] = 1;
                    }
                }
                if(j-1>=0){
                    if(mat[i][j-1]!= 0 && check[mat[i][j-1]] != 1){
                        temp+= pondSize[mat[i][j-1]];
                        check[mat[i][j-1]] = 1;
                    }
                }
                if(i+1<N){
                    if(mat[i+1][j]!=0 && check[mat[i+1][j]] != 1){
                        temp+= pondSize[mat[i+1][j]];
                        check[mat[i+1][j]] = 1;
                    }
                }
                if(j+1<M){
                    if(mat[i][j+1]!=0 && check[mat[i][j+1]] != 1){
                        temp+= pondSize[mat[i][j+1]];
                        check[mat[i][j+1]] = 1;
                    }
                }

                if(temp >maxPond){
                maxPond = temp;
                }
            }

            
        }
    }
   
    //cout<<"2"<<pondSize[2]<<" 3 "<<pondSize[3]<<endl;
    cout<<maxPond+1<<endl;
    return 0;
}