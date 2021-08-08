class ImageReader {
public:
  virtual void Decode() = 0;
  virtual ~ImageReader() = default;
};
