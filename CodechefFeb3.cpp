#include<iostream>

using namespace std;

int main(){
    int t,n;
    cin>>t;

    for(int z = 0;z<t;z++){
        cin>>n;
        int a[n],d[n];

        for(int i = 0;i< n;i++){
            cin>>a[i];
        }

        for(int i =0;i< n;i++){
            cin>>d[i];
        }

        int ans = -1;

        if(d[0] > (a[1]+a[n-1])){
            ans = d[0];
        }

        if(d[n-1] > (a[0]+a[n-2])){
            if(ans < d[n-1]){
                ans = d[n-1];
            }
        }

        for(int i = 1; i <n-1;i++){
            if(d[i]>(a[i-1]+a[i+1])){
                if(ans < d[i]){
                    ans = d[i];
                }
            }
        }

        cout<<ans<<endl;
    }
}