#include "Image.h"

class Bitmap : public Image
{
    std::string m_Buffer{};
public:
    using Image::Image;
    void Display() override;
    void Load() override;
    void Load(const std::string& fileName) override;
};
