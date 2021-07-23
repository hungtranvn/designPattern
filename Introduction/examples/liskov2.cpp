#include <iostream>
#include <variant>
#include <memory>

using ReturnType = std::variant<int, bool>;

struct IOperation {
    virtual ReturnType ResultOf(int *begin, int *end) = 0;
    virtual ~IOperation() = default;
};

class Operation : public IOperation {
public:
    virtual ReturnType ResultOf(int *begin, int *end) {
        int r = 0;
        for(auto it = begin; it != end; ++it)
            r += *it;
        return r;
    }
};

class BoolOperation : public IOperation {
public:
    ReturnType ResultOf(int *begin, int *end) override {
        bool r = 0;
        for(auto it = begin; it != end; ++it)
            r += *it;
        return r;
    }
};

struct Visitor {
    void operator()(int i) {std::cout << "int type\n";}
    void operator()(bool b) {std::cout << "bool type\n";}
};

// Client code use the above design
void Operate(IOperation *op) {
    using namespace std;
    int arr[5]{0,1,2,3,4};
    auto result = op->ResultOf(begin(arr), end(arr));
    //std::cout << result << std::endl;
    std::visit(Visitor(), result);
}

int main() {
    //std::unique_ptr<IOperation> oPtr(new Operation());
    IOperation *oPtrI;
    oPtrI = new Operation();
    Operate(oPtrI);
    
    IOperation *oPtrB;
    oPtrB = new BoolOperation();
    Operate(oPtrB);
    
    //delete oPtrI;
    //delete oPtrB;

    return 0;
}

//std::begin() return an iterator pointing to the first element
