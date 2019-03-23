//gray similar code - codechef

#include<iostream>
#include<vector>
#define ll unsigned long long

using namespace std;

int main(){
    ll n, ans;
    cin>> n;
    vector<ll> A;
    ans =0;
    for(ll i = 0;i<n;i++){
        cin>> ans;
        A.push_back(ans);
    }

    if(n >= 130){
        cout<<"Yes"<<endl;
    }
    else{
        for(ll i =0;i<n;i++){
            for(ll j = i +1; j<n;j++){
                for(ll k =j+1;k<n;k++){
                    for(ll l = k+1; l<n;l++){
                        
                       if(A[i]^A[j]^A[k]^A[l]){
                           cout<<"Yes"<<endl;
                           return 0;
                       }
                    }
                }
            }
        }
        cout<<"No"<<endl;

    }

    return 0;

}
