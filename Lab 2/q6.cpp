#include <iostream>
using namespace std;

class SafePointer {
    int *ptr;
public:
    SafePointer() {
        ptr = nullptr;
    }
    SafePointer(int val) {
        ptr = new int(val);
    }
    void setValue(int value) {
        if (!ptr) {
            ptr = new int(value);  
        } else {
            *ptr = value;
        }
    }
    int getValue() {
            return *ptr;
    }
    void release() {
        ptr = nullptr; 
        cout << "released\n";
    }
    ~SafePointer() {
        delete ptr;
    }
};

int main() {
    SafePointer s[5];  

    cout << "Enter marks:\n";
    for (int i = 0; i < 5; i++) {
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        s[i].setValue(mark);
    }

    cout << "Marks:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ": " << s[i].getValue() << endl;
    }
    cout << "release marks of student 3\n";
    s[2].release();
}

