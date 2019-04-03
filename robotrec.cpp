#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll calTime(ll x1, ll y1, ll x2, ll y2){
    ll x = x1 - x2;
    if(x<0){
        x*= -1;
    }
    ll y = y1 - y2;
    if(y<0){
        y*= -1;
    }

    return x+y;
}

class Wormhole{
    public:
    ll x1,y1,x2,y2,t;
};

ll X1,Y1,X2,Y2;

ll minTime(Wormhole wormhole[], int visited[],ll n, ll t, ll xs,ll ys){
   // cout<<"xs = "<<xs<<", ys = "<<ys<<" t = "<<t<<endl;
    if(xs == X2 && ys == Y2){
        //cout<<t<<endl;
        return t;
    }

    ll newT = calTime(xs,ys,X2,Y2) + t ;

    for(int i = 0;i<n;i++){
        if(visited[i] != 1){
            visited[i] = 1;
            ll tempt = t+ calTime(xs,ys,wormhole[i].x1,wormhole[i].y1) + wormhole[i].t;
            ll recT = minTime(wormhole,visited,n,tempt,wormhole[i].x2,wormhole[i].y2);
            if(newT > recT){
                newT = recT;
            }
            visited[i] = 0;
        }
    }

    return newT;
}

int main(){
    int t;
    cin>>t;
    for(int i =1;i<=t;i++){
        int n;
        cin>>n;
        Wormhole wormhole[2*n];
        int visited[2*n] = {0};
        cin>>X1>>Y1>>X2>>Y2;

        for(int i =0;i<n;i++){
            cin>>wormhole[i].x1>>wormhole[i].y1>>wormhole[i].x2>>wormhole[i].y2>>wormhole[i].t;
            wormhole[n+i].x1 = wormhole[i].x2;
            wormhole[n+i].y1 = wormhole[i].y2;
            wormhole[n+i].x2 = wormhole[i].x1;
            wormhole[n+i].y2 = wormhole[i].y1;
            wormhole[n+i].t = wormhole[i].t;
        }
        // for(int i =0;i<2*n;i++){
        //     cout<<wormhole[i].x1<<wormhole[i].y1<<wormhole[i].x2<<wormhole[i].y2<<wormhole[i].t;
        //     // wormhole[n+i].x1 = wormhole[i].x2;
        //     // wormhole[n+i].y1 = wormhole[i].y2;
        //     // wormhole[n+1].x2 = wormhole[i].x1;
        //     // wormhole[n+i].y2 = wormhole[i].y1;
        //     // wormhole[n+i].t = wormhole[i].t;
        // }


        cout<<"#"<<i<<" : "<<minTime(wormhole,visited,2*n,0,X1,Y1)<<endl;
    }

    return 0;
}