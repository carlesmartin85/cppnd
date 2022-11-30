#include <iostream>
#include <memory>
using namespace std;

class myCls{
    public:
    myCls(){cout << "def ctor" << endl;}
    myCls(int i){cout << "ctor int " << endl;}
    ~myCls(){cout << "def dtor" << endl;};
};
int main(){

    {
        // make_unique implementation
        auto sp{make_unique<myCls[]>(3)};
        for (int i = 0; i < 3; i++){sp[i] = myCls(i);}
    }

    cout << "---" << endl;

    {
        // standard pointer implementation
        auto rwptr{new myCls[3]{myCls(1), myCls(2), myCls(3)}};

        delete[] rwptr;
        rwptr = nullptr;
    }

    return 0;
}