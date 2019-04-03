#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll sum1, sum2;

ll coinChange(ll c[], int i, int j){
    if(i == j){
        return c[i];
    }
    if(i+1 == j){
        return max(c[i],c[j]);
    }

    ll costFront = c[i] + min(coinChange(c,i+2,j),coinChange(c,i+1,j-1));
    ll costBack = c[j] +min(coinChange(c,i+1,j-1),coinChange(c,i,j-2));

    return max(costFront,costBack);
}

int main(){
    int n;
    cin>> n;
    ll c[n];

    for(int i = 0;i<n;i++){
        cin>>c[i];
    }

    

    cout<<coinChange(c,0,n-1)<<endl;
    return 0;

}