#include<iostream>

#define ll long long

using namespace std;

ll hcf(ll a, ll b){
    if(a==0 || b ==0){
        return 1;
    }

    if(a == b){
        return a;
    }

    if(a>b){
        return hcf(a-b,b);
    }
    else{
        return hcf(a,b-a);
    }

}


int main(){
    int T;
    ll N,A,B,K;
    ll qA, qB, qNo, total;
    cin>> T;

    for(int i =0;i<T;i++){
        total = 0;
        cin>>N>>A>>B>>K;

        // if(A==B){
        //     cout<<"Lose"<<endl;
        //     continue;
        // }


        qA = N/A;
        qB = N/B;

        qNo = N/((A*B)/hcf(A,B));

        total = qA + qB - 2*qNo;

        if(total >= K){
            cout<<"Win"<<endl;
        }
        else{
            cout<<"Lose"<<endl;
        }


    }


    return 0;

}