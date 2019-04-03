#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll minplaces = 0;

void minChessProblem(ll n,ll r, ll c, vector<vector<ll>> chessBoard, ll places){
    // for(ll i =0;i<n;i++){
    //     for(ll j =0;j<n;j++){
    //         cout<< chessBoard[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    if(r < 0 || r >= n || c < 0 || c >= n){
        if(minplaces < places){
            minplaces = places;
        }
        return;
    }

    if(chessBoard[r][c] == 0){
        if(minplaces < places){
            minplaces = places;
        }
        return;
    }

    chessBoard[r][c] = 0;
    minChessProblem(n,r-2,c-1,chessBoard,places+1);
    minChessProblem(n,r-2,c+1,chessBoard,places+1);
    minChessProblem(n,r-1,c-2,chessBoard,places+1);
    minChessProblem(n,r-1,c+2,chessBoard,places+1);
    minChessProblem(n,r+1,c-2,chessBoard,places+1);
    minChessProblem(n,r+1,c+2,chessBoard,places+1);
    minChessProblem(n,r+2,c-1,chessBoard,places+1);
    minChessProblem(n,r+2,c+1,chessBoard,places+1);
    chessBoard[r][c] = 1;
    return;
}

int main(){
    ll n;
    cin>> n;
    vector<vector<ll>> chessBoard(n,vector<ll>(n));
    ll places = 0;
    for(ll i =0;i<n;i++){
        for(ll j =0;j<n;j++){
            cin>> chessBoard[i][j];
            if(chessBoard[i][j] == 1){
                places++;
            }
        }
    }

    minplaces = 0; //horse at top left

    minChessProblem(n,0,0,chessBoard,0);
    cout<<places - minplaces<<endl;

    return 0;
}