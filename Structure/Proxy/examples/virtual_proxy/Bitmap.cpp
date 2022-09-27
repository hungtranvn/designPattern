#include "Bitmap.h"

void Bitmap::Display()
{
    std::cout << m_buffer;
}

void Bitmap::Load()
{
    m_buffer.clear();
    std::ifstream file{GetFileName()};
    
    if(!file)
    {
        throw std::runtime_error{"Failed to open file"};
    }

    using namespace std::chrono_literals;
    std::string line{};
    std::cout << "Loading bitmap[";
    
    while(std::getline(file, line))
    {
        m_buffer += line + '\n';
        std::this_thread::sleep_for(100ms);
        std::cout << '.';
    }
    std::cout << "] Done!\n";
}

void Bitmap::Load(const std::string& fileName)
{
    SetFileName(fileName);
    Load();
}
