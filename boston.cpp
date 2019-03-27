#include<iostream>
#define ll long long

using namespace std;

ll noOfDigit(ll a){
    ll sum = 0;
    while(a != 0){
        sum += a%10;
        a /= 10;
    }
    return sum;
}


ll boston(ll num){
    ll sum = 0;
    ll prime = 2;
    ll sumNum = noOfDigit(num);
    while(num != 1){
        // cout<<"prime"<<prime<<endl;
        // cout<<"sum"<<sum<<endl;
        if(num%prime != 0){
            prime++;
        }
        else{
            sum += noOfDigit(prime);
            num /= prime;
        }
    }

    if(sumNum == sum){
        //cout<<sumNum <<","<<sum<<endl;
        return 1;
    }
    else{
        return 0;
    }
}



int main(){
    ll num;
    cin>> num;
    cout<<boston(num)<<endl;

    return 0;
}