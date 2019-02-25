#include<bits/stdc++.h>
#define ll long long

using namespace std;

int noOfDig(ll n){
    int count = 0;
    while(n>0){
        count++;
        n /= 10;
        //cout<<"N is"<<n<<endl;
    }
    return count;
}

int main(){

    ll n;
    cin>>n;
    int count = noOfDig(n);
    int ans = 0;

    //cout<<count<<endl;

    ans = (1<<count) - 1;
    //cout<<"Earlier ans"<<ans<<endl;
    int unit = 0;
    while(n>0){
        int dig = n%10;
        if(dig == 7){
            ans += 1<<unit;
        }
        n /= 10;
        unit++;
    }

    cout<<ans<<endl;


    return 0;
    
}