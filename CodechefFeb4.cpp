#include<iostream>

using namespace std;

int main(){
    
    long long t;
    cin>>t;

    while(t--){

        long long n;
        cin>>n;
        long long a[n];

        long long sum = 0;

        for(long long i =0;i<n;i++){

            cin>> a[i];

            sum  += a[i] - 1;

        }

        sum += 1;

        cout<<sum<<endl;

    }


    return 0;

}