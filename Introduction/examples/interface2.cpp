struct IRead {
  virtual  void Read() = 0;
  virtual ~IRead() = default;
};

struct IWrite {
  virtual void Write() = 0;
  virtual ~IWrite() = default;
};
