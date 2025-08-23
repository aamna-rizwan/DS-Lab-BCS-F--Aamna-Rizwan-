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
    b1=b2;
    cout << "\nb1 number : " << b1.getNum();
    Box b3 = b2;
    cout << "\nb3 number : " << b3.getNum();
  
}
