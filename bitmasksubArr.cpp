#include<bits/stdc++.h>

using namespace std;

//Using usual method
int check(int m,int n, int note[], int i, int sum){
    if(sum == m){
        return 1;
    }
    if(i>=n || note[i] >m || sum>m){
        return 0;
    }

    int ans1 = check(m,n,note,i+1,sum);
    int ans2 = check(m,n,note,i+1,sum+note[i]);

    return (ans1 == 1 || ans2 == 1);

}

int checkCombination(int m,int n,int note[],int noOfCombinations){

    //int ans =0;

    for(int i = 1;i<=noOfCombinations;i++){

        int sum = 0;
        int index = i;

        for(int j = 0;j<n;j++){

            //cout<<sum<<endl;

            if(sum > m){
                break;
            }

            if(index == 0){
                break;
            }
            int ans = index&1;
            if(ans == 1){
                sum += note[j];
            }

            index = index>>1;
        }

        if(sum == m){
            return 1;
        }

    }

    return 0;

}

int checkBinary(int m ,int n, int note[]){

    int noOfCombinations = pow(2,n) - 1;

    int ans = checkCombination(m,n,note,noOfCombinations);

    return ans;

}



int main(){
    int n;
    cin>> n;

    while(n--){
        int n,m;
        cin>>n>>m;

        int note[n];

        for(int i=0;i<n;i++){
            cin>>note[i];
        }

        //sort(note,note+n);

        int ans = checkBinary(m,n,note);
        if(ans == 1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
