#include <iostream>
using namespace std;

int main(){
    bool available=false;
    int row;
    cout << "Enter number of rows (catefories)\n";
    cin >> row;
    int **id = new int*[row];
    int *books = new int[row];
    for(int i=0;i<row;i++){
        cout << "Enter number of books for Category : " << i+1 << endl;
        cin >> books[i];
    }
    for(int i=0;i<row;i++){
        id[i]=new int[books[i]];
    }
    for(int i=0;i<row;i++){
        cout << "Category : " << i+1 << endl;
        for(int j=0;j<books[i];j++){
            cout << "Enter book ID for book " << j+1 << endl;
            cin >> id[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<books[i];j++){
            cout <<"Category "<< row << " : "<<id[i][j] << " ";
        }cout << endl;
    }
     int search;
    cout << "enter id to search\n";
    cin >> search;
    for(int i=0;i<row;i++){
        for(int j=0;j<books[i];j++){
            if(search == id[i][j]){
                available = true;
                cout << "Book Available and belongs to Category " << i+1 << endl;
            }
        }
    }
    if(available==false){
        cout << "book not found!\n";
    }

    for(int i=0;i<row;i++){
        delete[] id[i];
    }delete[] id;
    delete[] books;

}
