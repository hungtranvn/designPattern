class Notes {
public:
    void Add() {}
    void Remove() {}
    void Display() {}
};

/*We want to modify Add function because we want to add a functionality.
 * The functionality is that if a note with an ! mark, it should be placed
 * on the top of the list
 * */

// First way: a naive implementation -> modify the Add() function and add
// the condition.
class Notes {
public:
    void Add() {
        // if (contains('!')){
        // ...
        // }
    }
    
    void Remove() {
    
    }

    void Display() {

    }
};
//The above implementation violates open-closed principle.


// Second way: flow open-closed principle
// + Making the Add() function is virtual
// + Want to change the Add() behaviour, add a new class and override the
// Add() function.
class Notes {
public:
    virtual void Add() {}

    void Remove() {}

    void Display() {}
};

class TaggedNotes : public Notes {
public:
    void Add() override {
        // if (contains('!'))
        // {
        // 
        // }
    }
}
