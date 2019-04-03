#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int shouldSwap(char str[], int start, int curr){
    for(int i = start;i<curr;i++){
        if(str[i] == str[curr]){
            return 0;
        }
    }
    return 1;
}

void printPerm(char str[], int i, int size){
    // cout<<i<<"i"<<endl;
    // cout<<"i: "<<i<<" Str "<<str<<endl;
    if(str[i+1] == '\0'){
        cout<<str<<endl;
        return;
    }

    sort(str+i,str+size);
    //cout<<str<<"Sort Check with i "<<i <<endl;

    for(int j = i;str[j] != '\0';j++){
        sort(str+i,str+size);
        if(shouldSwap(str,i,j)){
        //cout<<"Swapping i "<<i<<" and str[i] "<<str[i]<<" and j "<<j << "and str[j] "<<str[j]<<endl;
        swap(str[i],str[j]);
        printPerm(str,i+1,size);
        swap(str[i],str[j]);
        }   
    }
}

int main(){
    char str[10];
    cin>>str;
    //cout<<str;
    int size = strlen(str);

    sort(str,str+size);
    //cout<<str<<endl;

    printPerm(str,0,size);

    return 0;
}