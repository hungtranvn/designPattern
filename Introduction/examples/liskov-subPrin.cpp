/*
 * 
 * */


class Operation {
public:
    virtual int ResultOf(int *begin, int *end){
        //implementation
    }
};
/*This Operation class provides the method ResultOf(). The method accepts a
 * range (*begin and *end) and performs an operation.
 * The operation could be addition, substraction, multiplication ..
 *
 * The clients can create a new operation and override ResultOff method by
 * providing their own implementation.
 * */


/*This is how the operation class might be used by a client.
 * Simply invoke ResultOf() method and get the result.
 * */
void Operate(Operation *op) {
    
    using namespace std;
    
    int arr[5]{};
    auto result = op->ResultOf(begin(arr), end(arr));
    std::cout << result;
}

/*What if we want to add support for a boolean operation?
 * In this case, we perform an operation of the elements of this range, but
 * the result should be boolean.
 * As we know, boolean type is also an integral type, and we can easily
 * return it as a result from the ResultOf function.
 * However, the calling code will not be able to know whether it returns an
 * integer or boolean?
 * */
class BoolOperation : public Operation {
    // return bool
    int ResultOf(int *begin, int *end) override {

    }
};


// Back to the Operate function: need to modify by adding checking typeid
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

/* -> modifying existing code (Operate function) so violating open-closed 
 * principle and violating Liskov-sub principle because child class 
 * BoolOperation can't act as substitute (check type Id) for Operation. 
 * It is different from base class. The base class provides the behaviour 
 * of performing an operation and returning an individual result, but the 
 * boolean operation class not only changed the implementation but also 
 * changed its behaviour because it returns a differnt type.
 * */


/**** Solution? How to add new type without modify existing code?***/
/* Add a base class interface called IOperation and use variant as the
 * returned type.
 * */
using ReturnType = std::variant<int, bool>;

struct IOperation {
    virtual ReturnType ResultOf(int *begin, int *end) = 0;
    virtual ~Operation() = default;
}

/*We will inherit Operation and BoolOperation from the interface
 * */
class Operation : public IOperation {
public:
    virtual ReturnType ResultOf(int *begin, int *end) {
        //implementation 
    }
    // returned type should be integer
}

class BoolOperation : public IOperation {
public:
    ReturnType ResultOf(int *begin, int *end) override {
        //implementation
    }
    // Returned type should be boolean
}

// Client code use the above design
void Operate(IOperation *op) {
    using namespace std;
    int arr[5]{};
    auto result = op->ResultOf(begin(arr), end(arr))
}

// using visitation for type safe access. Client does not have to know what
// type of operation was invoked and what is return type.




/*REF:
 * https://www.bfilipek.com/2018/06/variant.html
 * https://www.bfilipek.com/2018/09/visit-variants.html
 * */
