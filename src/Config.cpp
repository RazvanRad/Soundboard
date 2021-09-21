#include <Config.hpp>
#include <JsonParser.hpp>

void Config::loadConfig(std::string filename)
{
    JsonParser parsedInfo(filename);

    pathById = parsedInfo.getConfig();
}
