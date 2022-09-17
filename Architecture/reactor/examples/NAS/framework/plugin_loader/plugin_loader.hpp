#ifndef RD70_PLUGIN_LOADER
#define RD70_PLUGIN_LOADER

#include <iostream>
#include <vector>
#include <memory>

#include "command.hpp"
#include "factory.hpp"
#include "dispatcher.hpp"

namespace ilrd
{

using createCmd_f = std::shared_ptr<Command> (*)(void *sendData_);
using cmdFact_t = Factory<std::shared_ptr<Command>, char, void *>;

class PluginLoader
{
public:
    PluginLoader();
    ~PluginLoader();

    // Generated CCtor;
    // Generated assignment operator;

    void Notify(std::string pluginPath_);
    void NotifyDeath();
    void LoadPlugin(std::string pluginPath_);
    void CloseHandles();
    static void CloseHandle(void *handle_);

    Callback<std::string, PluginLoader> m_callback;

private:
    void CheckHandle(void *handle_);
    std::string GetFileExtension(std::string path_);
    void AddToCmdFactory(char key_, createCmd_f createCmdPtr_);

    cmdFact_t *m_cmdFact;
    std::vector<void *> m_handles;
};

} // namespace ilrd

#endif // RD70_PLUGIN_LOADER