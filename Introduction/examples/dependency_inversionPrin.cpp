class ImageReader {
public:
    virtual void Decode() = 0;
    virtual ~ImageReader() = default;
};

class BitmapReader : public ImageReader {
public:
    void Decode() {}
};

class ImageViewer {
    BitmapReader *m_Reader{};
public:
    void Display(){}
};

/*
 * ImageViewer is tightly coupled with BitmapReader (a concrete class)
 * 
 * In the future, if more ImageReader are added, then you will not able to
 * use them easily in ImageViewer. You will have to modify ImageViewer to
 * add more reader. This violate dependency inversion and open-closed
 * principles. BitmapReader is dependent on concrete class and not the
 * abstraction of the BitmapReader.
 *
 * The abstraction of BitmapReader is ImageReader
 * */

class ImageViewer {
    ImageReader *m_Reader{};
public:
    void Display(){}
};

/*
 * providing an interface rather than implementation
 * using dependency inversion principle, we reduce the dependency on
 * specific reader class.
 * */

