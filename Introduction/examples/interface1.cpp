struct IFile {
    virtual void Read() = 0;
    virtual void Write() = 0;
    virtual ~IFile() = default;
};