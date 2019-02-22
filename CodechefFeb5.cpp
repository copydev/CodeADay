#include<bits/stdc++.h>

using namespace std;

long long alphaAt(char ch){
    long long index = ch - 'A';
    return index;
}

int main(){

    long long t;
    cin>>t;

    while(t--){
        long long alpha[26] = {0};
        long long totChars = 0;
        string input;

        //getline(cin,input);
        cin>>input;
        //Check if it needed one more false input for getline

        for(long long i =0;i<input.size();i++){

            alpha[alphaAt(input.at(i))]++;
            totChars++;

        }

        sort(alpha, alpha+26, greater<long long>());

        long long cost = 2147483600; //Insert Max value

        for(long long i =0;i<26;i++){
            long long consideringChars = i+1;
            if(totChars>= consideringChars && totChars%consideringChars == 0){

                long long balance = totChars/consideringChars;
                long long up = 0,down = 0;

                for(long long i =0;i<consideringChars;i++){

                    if(alpha[i] > balance){

                        up += alpha[i] - balance;
                    }
                    if(alpha[i] < balance){

                        down += balance - alpha[i];
                    }

                }

                long long specificCost = up > down ? up: down;

                if(specificCost<cost){
                    cost = specificCost;
                }

            }


        }

        cout<<cost<<endl;

    }



}