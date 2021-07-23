#include <iostream>

class Operation {
public:
    virtual int ResultOf(int *begin, int *end){
        //implementation
    }
};

void Operate(Operation *op) {
    
    using namespace std;
    
    int arr[5]{};
    auto result = op->ResultOf(begin(arr), end(arr));
    std::cout << result;
}

class BoolOperation : public Operation {
    // return bool
    int ResultOf(int *begin, int *end) override {

    }
};


void Operate(Operation *op) {
    
    using namespace std;
    
    int arr[5]{};
    auto result = op->ResultOf(begin(arr), end(arr));
    
    if(typeid(*op) == typeid(BoolOPeration)) {
        //assume bool
    }
    else {
        //assume int
    }
}
