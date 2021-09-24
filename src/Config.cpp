#include <Config.hpp>
#include <JsonParser.hpp>

void Config::loadConfig(std::string &filename)
{
    JsonParser parsedInfo(filename);

    init(parsedInfo);
}

int Config::getProtocol() const
{
    return transferProtocol;
}

int Config::getButtonCount() const
{
    return buttonCount;
}

std::string Config::getSoundPathByButtonID(int id)
{
    if (pathById.find(id) != pathById.end())
    {
        return pathById[id];
    }
    //if we get here the button does not exist
    if (!pathById.empty())
    {
        return ("");
    }
    //if we get here the map is empty
    return ("");
}

int Config::getBluetoothPort() const
{
    return bluetoothPort;
}

std::vector<std::string> Config::getPlayers() const
{
    return players;
}

void Config::init(JsonParser info)
{

    for (pt::ptree::value_type &btn : info.getPtree().get_child("buttonID"))
    {
        int val = stoi(btn.first);
        std::string path = btn.second.data();

        pathById.insert(std::make_pair(val, path));
        buttonCount++;
    }

    std::string protocol = info.getPtree().get<std::string>("transferProtocol", "");

    if (protocol == "bluetooth")
    {
        transferProtocol = bluetooth;
    }
    else if (protocol == "netcat")
    {
        transferProtocol = netcat;
    }
    else
    {
        printf("Protocol not found!");
    }

    bluetoothPort = info.getPtree().get<int>("bluetoothPort", 1);

    for (pt::ptree::value_type &element : info.getPtree().get_child("player"))
    {
        players.push_back(element.second.data());
    }
    if (players.size() == 0)
    {
        printf("Players not found!");
    }
}