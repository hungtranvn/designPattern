#include <memory>
#include <fstream>

#include "logger.hpp"
#include "singleton.hpp"
#include "config_loader.hpp"
#include "new_file_notifier.hpp"

namespace ilrd
{

using namespace std;

ConfigLoader::ConfigLoader()
    : m_callback(this, &ConfigLoader::Notify, &ConfigLoader::NotifyDeath)
{
    Singleton<NewFileNotifier>::Instance()->Register(&m_callback);
}

void ConfigLoader::Notify(string configFilePath)
{
    string relevantFileExt = "ini";

    if (0 == relevantFileExt.compare(GetFileExtension(configFilePath)))
    {
        LoadINIFile(configFilePath);
    }
}

void ConfigLoader::NotifyDeath()
{
    Singleton<NewFileNotifier>::Instance()->Unregister(&m_callback);
}

void ConfigLoader::LoadINIFile(string configFilePath)
{
    string fileExt("ini");

    cout << "ConfigLoader, in function: " << __func__ << endl;

    if (0 == fileExt.compare(GetFileExtension(configFilePath)))
    {
        ifstream iniFile(configFilePath.c_str());
        string currLine;
        string logPathKey("LOGGER_PATH");
        Logger *logger = GetLoggerSingleton();

        while (getline(iniFile, currLine))
        {
            if (0 == (currLine.compare(0, logPathKey.size(), logPathKey)))
            {
                string::size_type pos = currLine.find('=');
                if (currLine.npos != pos)
                {
                    string newLoggerOutputPath(currLine.substr(pos + 1));
                    logger->Log(Logger::DEBUG,
                                string("*.ini File changed logger output to: " + 
                                newLoggerOutputPath));
                    
                    cout << "\n*.ini File changed logger output to: " << 
                                                    newLoggerOutputPath << endl;
                    
                    logger->SetOutput(shared_ptr<ostream>(
                        new ofstream(newLoggerOutputPath.c_str(), ios::out)));
                }
            }
        }
    }  
}

string ConfigLoader::GetFileExtension(string path)
{
    size_t found = path.find_last_of(".");

    return (path.substr(found + 1));
}

} // namespace ilrd
