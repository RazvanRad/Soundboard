#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <string>
#include <vector>
#include <map>

namespace pt = boost::property_tree;

class JsonParser
{
public:
    //call using json file name
    JsonParser(const std::string &filename);

    std::string getSoundPathByButtonID(int id);

    int getProtocol();

private:
    JsonParser();
    void initButtonIdToPath();
    //map[2] = "path/to/sound2"
    std::map<int, std::string> pathById;
    pt::ptree root;
    //0 = bluetooth
    //1 = netcat
    int transferProtocol = 0;
};
#endif