#include <JsonParser.hpp>

JsonParser::JsonParser(const std::string &filename)
{
    if (filename.length() > 0)
    {
        pt::read_json(filename, root);
    }
    else
    {
        printf("No file name given to json parser");

        pt::read_json("default.json", root);
    }
    init();
}

JsonParser::JsonParser() {}

void JsonParser::init()
{

    for (pt::ptree::value_type &btn : root.get_child("buttonID"))
    {
        int val = stoi(btn.first);
        std::string path = btn.second.data();

        data.pathById.insert(std::make_pair(val, path));
        data.buttonCount++;
    }

    std::string protocol = root.get<std::string>("transferProtocol", "");

    if (protocol == "bluetooth")
    {
        data.transferProtocol = bluetooth;
    }
    else if (protocol == "netcat")
    {
        data.transferProtocol = netcat;
    }
    else
    {
        printf("Protocol not found!");
    }

    data.bluetoothPort = root.get<int>("bluetoothPort", 1);
}

ConfigData JsonParser::getConfigData()
{
    return data;
}