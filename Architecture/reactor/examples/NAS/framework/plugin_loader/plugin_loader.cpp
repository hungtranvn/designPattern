#include <dlfcn.h>
#include <unistd.h>
#include <algorithm>

#include "plugin_loader.hpp"
#include "singleton.hpp"
#include "logger.hpp"
#include "new_file_notifier.hpp"

namespace ilrd
{

using namespace std;

using getKey_f = char (*)();

PluginLoader::PluginLoader()
    : m_callback(this, &PluginLoader::Notify, &PluginLoader::NotifyDeath),
      m_cmdFact(Singleton<cmdFact_t>::Instance())
{
    Singleton<NewFileNotifier>::Instance()->Register(&m_callback);
}

PluginLoader::~PluginLoader()
{
    CloseHandles();
}

void PluginLoader::Notify(string pluginPath)
{
    string relevantFileExt = "so";

    if (0 == relevantFileExt.compare(GetFileExtension(pluginPath)))
    {
        LoadPlugin(pluginPath);
    }
}

void PluginLoader::NotifyDeath()
{
    Singleton<NewFileNotifier>::Instance()->Unregister(&m_callback);
}

void PluginLoader::LoadPlugin(string pluginPath)
{   
    Logger *logger = GetLoggerSingleton();

    sleep(1);

    void *handle = dlopen((pluginPath).c_str(), RTLD_LAZY);
    CheckHandle(handle);
    logger->Log(Logger::INFO, pluginPath + " was opened successfully");

    // Get key
    getKey_f getCmdKey = reinterpret_cast<getKey_f>(dlsym(handle, "GetKey"));
    if (nullptr == getCmdKey)
    {
        string err(dlerror());
        logger->Log(Logger::ERROR, err);
        cerr << err << endl;
    }
    
    char key = getCmdKey();
    
    // Get function pointer
    createCmd_f createCmdPtr = reinterpret_cast<createCmd_f>(dlsym(handle, 
                                                                "CreateCmd"));
    if (nullptr == createCmdPtr)
    {
        string err(dlerror());
        logger->Log(Logger::ERROR, err);
        cerr << err << endl;
    }
    else
    {
        AddToCmdFactory(key, createCmdPtr);
    }    
}

void PluginLoader::AddToCmdFactory(char key, createCmd_f createCmdPtr)
{
    m_cmdFact->Add(key, createCmdPtr);
        GetLoggerSingleton()->Log(Logger::INFO, "Function with key " + 
                        to_string((int)key) + " was added to command factory");
}

void PluginLoader::CheckHandle(void *handle)
{
    if (!handle)
    {
        string err(dlerror());
        GetLoggerSingleton()->Log(Logger::ERROR, err);
        cerr << "\nFunction: " << __func__ << err << endl;
        perror(err.c_str());
    }
}

void PluginLoader::CloseHandle(void *handle)
{
    dlclose(handle);
}

void PluginLoader::CloseHandles()
{
    for_each(m_handles.begin(), m_handles.end(), [](void *handle) {
        dlclose(handle);
    });
}

string PluginLoader::GetFileExtension(string path)
{
    size_t found = path.find_last_of(".");

    return (path.substr(found + 1));
}

} // namespace ilrd
