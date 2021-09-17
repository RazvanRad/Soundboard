#include "jsonParser.h"
JsonParser::JsonParser(const std::string &filename)
{
    pt::read_json(filename, root);
    initButtonIdToPath();
}

std::string JsonParser::getSoundPathByButtonID(int id)
{
    return pathById[id];
}

int JsonParser::getProtocol()
{
    return transferProtocol;
}

JsonParser::JsonParser()
{
    pt::read_json("default.json", root);
}

void JsonParser::initButtonIdToPath()
{
    for (pt::ptree::value_type &btn : root.get_child("buttonID"))
    {
        int val = stoi(btn.first);
        std::string path = btn.second.data();

        pathById.insert(std::make_pair(val, path));
    }
}