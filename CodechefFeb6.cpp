#include<bits/stdc++.h>
#define ll long long
#define ten9 1000000000

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        // Taking distance from origin

        ll xLow, yLow, xHigh, yHigh;
        ll origin, xMax, yMax, Max;

        ll xMid;

        ll tmp;

        //Q1
        cout<<"Q 0 0"<<endl;
        cin>>origin;

        //Q2
        cout<<"Q "<<ten9<<" 0"<<endl;
        cin>>xMax;

        xMid = (ten9-(xMax-origin))/2;

        //Q3
        //to find y
        cout<<"Q "<<xMid<<" 0"<<endl;

        cin>>yLow;

        xLow = origin - yLow;

        //Q4
        //to find yHigh
        cout<<"Q "<<xMid<<" "<<ten9<<endl;

        cin>>tmp;

        yHigh = ten9 - tmp;

        //Q5 
        //to find Max
        cout<<"Q "<<ten9<<" "<<ten9<<endl;
        cin>>Max;

        xHigh = 2 * ten9 - yHigh - Max;

        cout << "A "<<xLow<<" "<<yLow<<" "<<xHigh<<" "<<yHigh<<endl;

        int ans;
        cin>>ans;

    }


    return 0;

}