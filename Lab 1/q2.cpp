#include <iostream>
using namespace std;

class Exam{
    string name;
    string date;
    int *score;
    public:
    Exam(string n, string d, int s){
        name=n;
        date=d;
        score= new int;
        *score=s;
    }
    string getName(){
        return name;
    }
    string getDate(){
        return date;
    }
    int getScore(){
       return *score;
    }
    void setName(string n){
        name=n;
    }
    void setDate(string d){
        date=d;
    }
    void setScore(int s){
        *score=s;
    }
    ~Exam(){
        delete score;
    }
};

int main(){
    Exam e1("Aamna", "23rd Aug", 85);
    e1.getName(); e1.getDate(); e1.getScore();
    Exam e2 = e1; //defualt copy constructor
    e2.getName(); e2.getDate(); e2.getScore();
  /*a copy constructor needs to be added as a shallow copy was performed here, e1.score and e2.score both point towards the same
  address hence when we try to delete it , it will give us an error, double delete issue here*/
  /*a deep copy would have different addresses for the values as it allocates a new block of emmory for the copied object, so 
  no double delete*/

  /*ERROR : free(): double free detected in tcache 2
Aborted


=== Code Exited With Errors ===*/

    
    
    
    
    
    
    
    
}
