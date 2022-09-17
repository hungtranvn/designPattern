#ifndef RD70_CONFIG_LOADER
#define RD70_CONFIG_LOADER

#include <iostream>

#include "dispatcher.hpp"

namespace ilrd
{

class ConfigLoader
{
public:
    ConfigLoader();

    // Generated Dtor;
    // Generated CCtor;
    // Generated assignment operator;

    void Notify(std::string configFilePath_);
    void NotifyDeath();
    void LoadINIFile(std::string configFilePath_);

    Callback<std::string, ConfigLoader> m_callback;

private:
    std::string GetFileExtension(std::string path_);
};

} // namespace ilrd

#endif // RD70_CONFIG_LOADER