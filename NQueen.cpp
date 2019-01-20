#include<iostream>

using namespace std;

const int N = 8;

int isSafe(int mat[8][8], int row, int col){

    //cout<<"row"<<row<<"col"<<col<<endl;

    for(int i =0; i< col;i++){
        //Row
        if(mat[row][i] == 1){
            return -1;
        }
    }
    //upper row
    for(int i =row, j= col;i>=0,j>=0;i--,j--){

        if(mat[i][j] == 1){
            return -1;
        }
    }
    //lower row
    for(int i = row, j =col; j>=0,i<N;j--,i++){

        if(mat[i][j] == 1){
            return -1;
        }
    }

    return 1;
}

int checkMatrix(int mat[8][8], int noQ){

    if(noQ >= 8){
        return 1;
    }

    int checkIfPos = -1;
    int possible;

    for(int i =0;i<8;i++){
        checkIfPos = isSafe(mat,i,noQ);
        if(checkIfPos == 1){
            mat[i][noQ] = 1;
            possible = checkMatrix(mat,noQ+1);
            if(possible == -1){
                checkIfPos = -1;
                mat[i][noQ] = 0;
                continue;
            }
            else{
                return 1;
            }
        }
    }

    // for(int i =0;i<8;i++){
    //     for(int j =0;j< 8 ;j++){
    //         cout<<mat[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"----------------------"<<endl;

    return -1;
}

int main(){

    int mat[8][8];

    for(int i =0;i<8;i++){
        for(int j =0;j< 8 ;j++){
            mat[i][j] = 0;
        }
    }

    checkMatrix(mat, 0);

    for(int i =0;i<8;i++){
        for(int j =0;j< 8 ;j++){
            cout<<mat[i][j] <<" ";
        }
        cout<<endl;
    }

    return 0;

}
