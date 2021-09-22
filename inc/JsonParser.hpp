#ifndef SOUNDBOARD_JSONPARSER_H
#define SOUNDBOARD_JSONPARSER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <map>
#include <string>
#include <vector>

namespace pt = boost::property_tree;

enum TransferProtocol
{
    bluetooth,
    netcat
};

struct ConfigData
{
    std::map<int, std::string> pathById;
    int transferProtocol = -1;
    int buttonCount = -1;
    int bluetoothPort = -1;
};


class JsonParser
{
public:
    JsonParser(const std::string &filename);

    ConfigData getConfigData();

private:
    JsonParser();
    void init();

    pt::ptree root;
    ConfigData data;
};
#endif