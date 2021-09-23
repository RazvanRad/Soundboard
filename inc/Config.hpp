#ifndef SOUNDBOARD_CONFIG_H_
#define SOUNDBOARD_CONFIG_H_

#include <map>
#include <string>

#include <JsonParser.hpp>

class Config
{

public:
    void loadConfig(std::string &filename);

    std::string getSoundPathByButtonID(int id);
    int getButtonCount() const;
    int getProtocol() const;
    int getBluetoothPort() const;
    std::vector<std::string> getPlayers() const;

private:
    void init(JsonParser info);

    std::map<int, std::string> pathById;
    int transferProtocol = -1;
    int buttonCount = -1;
    int bluetoothPort = -1;
    std::vector<std::string> players;
};

#endif