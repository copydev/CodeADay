#include<iostream>
#define ll long long

using namespace std;

int check(ll A[], int n, int index,ll sum,ll ele){
    cout<<"Sum: "<<sum<<"ele: "<<ele<<endl;
    if(sum == 0 && ele!=0){
        return 1;
    }
    if(index == n){
        return 0;
    }

    int ans;
    ans = check(A,n,index+1,sum,ele);
    
    if(ans == 1){
        return 1;
    }

    ele++;
    sum += A[index];

    ans = check(A,n,index+1,sum,ele);
    return ans;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll A[n];
        for(int i = 0;i<n;i++){
            cin>>A[i];
        }

        int ans = check(A,n,0,0,0);
        if(ans == 1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}