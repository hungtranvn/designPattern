#include <Image.h>
void Image::SetFileName(const std::string& fileName)
{
    m_fileName = fileName;
}

Image::Image(const std::string& fileName) : m_fileName{fileName} 
{
    
}

const std::string& Image::GetFileName() const 
{
    return m_fileName;
}
