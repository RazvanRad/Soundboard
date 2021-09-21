#include "JsonParser.h"

JsonParser::JsonParser(const std::string &filename)
{
    if (filename.length() > 0)
    {
        pt::read_json(filename, root);
        init();
    }
    else
    {
        JsonParser();
    }
}
std::map<int,std::string> JsonParser::getConfig() const
{
    return pathById;
}
std::string JsonParser::getSoundPathByButtonID(int id)
{
    if (pathById.find(id) != pathById.end())
    {
        return pathById[id];
    }
    //if we get here the button does not exist
    if (!pathById.empty())
    {
        return("");
        
    }
    //if we get here the map is empty
    return("");
}

int JsonParser::getProtocol() const
{
    return transferProtocol;
}

JsonParser::JsonParser()
{
    pt::read_json("default.json", root);
    init();
}

void JsonParser::init()
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