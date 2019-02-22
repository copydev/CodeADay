 #include<bits/stdc++.h>
#define ll long long
#define modulo 1000000007

using namespace std;

// Function to return gcd of a and b 
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
}

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

ll modInverse(ll a, ll m) 
{ 
    ll g = gcd(a, m);  
    return power(a, m-2, m); 
    
} 



int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n ,k ,m;
        cin>>n>>k>>m;

        if(m%2!=0){
            ll t = 1 + (m-1)/2;

            ll num = power(n,t,modulo) - power(n-1,t,modulo);

            ll den = power(n,t,modulo);

            ll g = gcd(num,den);

            num /= g;

            den /= g;

            // cout<<num<<endl;

            // cout<<den<<endl;


            ll ans = (num * modInverse(den,modulo))%modulo;

            ans = (ans + modulo)%modulo;

            cout<<ans<<endl;
        }
        else{
            ll t = m/2;

            ll num = (((power(n,t,modulo) - power(n-1,t,modulo))*(n + k))%modulo + power(n-1,t,modulo))%modulo;

            

            ll den =  (power(n,t,modulo)*(n+k))%modulo;

            

            ll g = gcd(num,den);

            num /= g;

            den /= g;

            // cout<<num<<endl;

            // cout<<den<<endl;

            ll ans = (num * modInverse(den,modulo))%modulo;

            ans = (ans + modulo)%modulo;

            cout<<ans<<endl;

        }

    }



    return 0;

}