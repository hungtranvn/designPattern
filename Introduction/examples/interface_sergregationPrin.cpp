// Before
struct IFile {
    virtual void Read() = 0;
    virtual void Write() = 0;
    virtual ~IFile() = default;
};
// Most clients do not use all functions, but some of may only want to read
// or write

// After
struct IRead {
    virtual  void Read() = 0;
    virtual ~IRead() = default;
};

struct IWrite {
    virtual void Write() = 0;
    virtual ~IWrite() = default;
};
