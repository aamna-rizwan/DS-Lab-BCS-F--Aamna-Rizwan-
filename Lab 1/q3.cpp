#include <iostream>
using namespace std;

class Box{
    int *num;
    public:
    Box(int x){
        num=new int;
        *num=x;
    }
    Box(const Box &b){
        num = new int;
        *num = *b.num;
    }
    /*Box(const Box&b){
        *num =*b.num; shallow copy here , does not alloacte new memory for the integer value of num : uses the same address
    }*/

    Box& operator=(const Box &b){
        num=new int;
        *num=*b.num;
        return *this;
    }
    ~Box(){
        delete num;
    }
    int getNum(){
        return *num;
    }
};
int main(){
    Box b1(40);
    cout << "b1 number : " << b1.getNum();
    Box b2(50);
    cout << "\nb2 number : " << b2.getNum();
    b1=b2; //copy assignment operator - deep copy
    cout << "\nb1 number : " << b1.getNum();
    Box b3 = b2;  //copy constructor - also deep copy
    cout << "\nb3 number : " << b3.getNum();
  
}
