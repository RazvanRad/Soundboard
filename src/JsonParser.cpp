#include "JsonParser.h"
JsonParser::JsonParser(const std::string &filename)
{
    if (filename.length() > 0)
    {
        pt::read_json(filename, root);
        initButtonIdToPath();
    }
    else
    {
        JsonParser();
    }
}

std::string JsonParser::getSoundPathByButtonID(int id)
{
    if (pathById.find(id) != pathById.end())
    {
        return pathById[id];
    }

    if (pathById.empty())
    {
        throw 2000001;
    }

    throw 2000000;
}

int JsonParser::getProtocol() const
{
    return transferProtocol;
}

JsonParser::JsonParser()
{
    pt::read_json("default.json", root);
    initButtonIdToPath();
}

void JsonParser::initButtonIdToPath()
{
    for (pt::ptree::value_type &btn : root.get_child("buttonID"))
    {
        int val = stoi(btn.first);
        std::string path = btn.second.data();

        pathById.insert(std::make_pair(val, path));
        buttonCount++;
    }
}

int JsonParser::getButtonCount() const
{
    return buttonCount;
}