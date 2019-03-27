#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll binomialCoeff2(ll n, ll k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if ( k > n - k ) 
        k = n - k; 
  
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (ll i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 


ll binomialCoeff(ll n, ll k) 
{ 
    //ll C[n + 1][k + 1]; 
    vector<vector<ll>> C(n+1,vector<ll>(k+1));
    ll i, j; 
  
    // Caculate value of Binomial Coefficient 
    // in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previosly 
            // stored values 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

ll marbles(ll n, ll k){
    //Find n-1 C r-1
    // cout<<"n: "<<n <<"r :"<<k;
    return binomialCoeff2(n-1,k-1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll k,n;
        cin>>n>>k;
        cout<<marbles(n,k)<<endl;
    }
    return 0;
}