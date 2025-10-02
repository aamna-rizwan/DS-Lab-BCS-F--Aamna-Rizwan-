#include <iostream>
using namespace std;

const int n=9;
bool valid(int sudoku[n][n],int row,int col, int num );
bool empty(int sudoku[n][n],int &row,int &col);
bool solve(int sudoku[n][n]);


int main() {
 int sudoku[9][9] = {
        {0,0,0, 2,6,0, 7,0,1},
        {6,8,0, 0,7,0, 0,9,0},
        {1,9,0, 0,0,4, 5,0,0},

        {8,2,0, 1,0,0, 0,4,0},
        {0,0,4, 6,0,2, 9,0,0},
        {0,5,0, 0,0,3, 0,2,8},

        {0,0,9, 3,0,0, 0,7,4},
        {0,4,0, 0,5,0, 0,3,6},
        {7,0,3, 0,1,8, 0,0,0}
    };
    cout << "Sudoku :" << endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
     if(solve(sudoku)){
        cout << "\nSolved Sudoku:" << endl;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

}

bool valid(int sudoku[n][n], int row, int col, int num){
    for(int i=0;i<n;i++){
        if(sudoku[row][i]==num){
        return false;
        }
    }
    for(int i=0;i<n;i++){
        if(sudoku[i][col]==num){
            return false;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoku[i+(row-(row%3))][j+(col-(col%3))]==num){
                return false;
            }
        }
    }
    return true;
}
bool empty(int sudoku[n][n], int &row, int &col){
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            if(sudoku[row][col]==0){
                return true;
            }
        }
    }
    return false;
}

bool solve(int sudoku[n][n]){
    int r,c;
    if(!empty(sudoku,r,c)){
        return true;
    }
    for(int num=1;num<10;num++){
        if(valid(sudoku,r,c,num)){
            sudoku[r][c]=num;
            if(solve(sudoku)){
                return true;
                sudoku[r][c]=0;
            }
        }
    }
    return false;
}




