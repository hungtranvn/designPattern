#include <iostream>

class Operation {
public:
    virtual int ResultOf(int *begin, int *end){
        int r = 0;
        for(auto it = begin; it != end; ++it)
            r += *it;
        return r;
    }
};

// Client can create new class and override ResultOf method

void Operate(Operation *op) {
    using namespace std;
    
    int arr[5]{};
    auto result = op->ResultOf(begin(arr), end(arr));
    std::cout << result;
}

// If we want to add for supporting boolean operation
class BoolOperation : public Operation {
    // return bool
    int ResultOf(int *begin, int *end) override {

    }
};


void Operate(Operation *op) {
    
    using namespace std;
    
    int arr[5]{};
    auto result = op->ResultOf(begin(arr), end(arr));
    
    if(typeid(*op) == typeid(BoolOperation)) {
        //assume bool
    }
    else {
        //assume int
    }
}
