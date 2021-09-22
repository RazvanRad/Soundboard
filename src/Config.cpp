#include <Config.hpp>
#include <JsonParser.hpp>

void Config::loadConfig(std::string &filename)
{
    JsonParser parsedInfo(filename);
    data = parsedInfo.getConfigData();
}

int Config::getProtocol() const
{
    return data.transferProtocol;
}

int Config::getButtonCount() const
{
    return data.buttonCount;
}

std::string Config::getSoundPathByButtonID(int id)
{
    if (data.pathById.find(id) != data.pathById.end())
    {
        return data.pathById[id];
    }
    //if we get here the button does not exist
    if (!data.pathById.empty())
    {
        return ("");
    }
    //if we get here the map is empty
    return ("");
}

int Config::getBluetoothPort() const
{
    return data.bluetoothPort;
}

std::vector<std::string> Config::getPlayers() const
{
    return data.players;
}