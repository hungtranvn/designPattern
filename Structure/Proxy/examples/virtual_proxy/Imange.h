#include <string>

class Image
{
    std::tring m_fileName;
protected:
    void SetFileName(const std::string& fileName);
public:
    Image() = default;
    Image(const std::string& fileName);
    virtual ~Image() = default;
    virtual void Display() = 0;
    virtual void Load() = 0;
    virtual void Load(const std::string& fileName) = 0;
};
