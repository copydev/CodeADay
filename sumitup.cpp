#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define ll long long

using namespace std;

set<vector<ll>> answers;

void printSum(ll N, vector<ll> A, ll T, ll index, ll sum,vector<ll> output){
    if(sum>T){
        return;
    }
    if(sum == T){
        
        // for(ll i =0;i<output.size();i++){
        //     cout<<output[i]<<" ";
        // }
        // cout<<endl;
        answers.insert(output);
        return;
    }
    if(index == N){
        return;
    }

    output.push_back(A[index]);
    printSum(N,A,T,index+1,sum + A[index],output);
    output.pop_back();
    printSum(N,A,T,index+1,sum,output);
    return;
}

int main(){
    ll N,T;
    vector<ll>A, output;
    cin>>N;
    set<ll> temp;

    for(ll i =0;i<N;i++){
        ll t;
        cin>>t;
        // temp.insert(t);
        A.push_back(t);
    }

    // vector<ll> A(temp.begin(),temp.end());
    sort(A.begin(),A.end());   

    cin>>T;

    N = A.size();

    printSum(N,A,T,0,0,output);
    vector<vector<ll>> ans(answers.begin(),answers.end());

    for(int i = 0;i<ans.size();i++){
        vector<ll> z = ans[i];
        for(int j = 0;j<z.size();j++){
            cout<<z[j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}