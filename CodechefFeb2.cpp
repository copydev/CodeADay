#include<iostream>
#include<string>

using namespace std;

#define ll long long

int alphaIndex(char ch){
    int a = 'a';
    int c = ch;
    int index = c - a;
    return index;
}

int main(){
    int T,N;
    cin>>T;

    for(int i =0;i<T;i++){

        ll alphabets[26] = {0};
        cin>>N;
        for(int j =0;j<N+1;j++){
            string str;
            int checkAlpha[26] = {0};
            getline(cin,str);

            for(int k =0;k<str.size();k++){
                int index = alphaIndex(str.at(k));
                //cout<<index<<endl;
                if(checkAlpha[index] == 0){
                    alphabets[index]++;
                    checkAlpha[index] = 1;
                }
            }
        }

        int ans = 0;

        for(int j =0;j<26;j++){
            //cout<<alphabets[j]<<endl;
            if(alphabets[j]==N){
                ans++;
            }
        }

        cout<<ans<<endl;
    }


    return 0;

}