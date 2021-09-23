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
}

JsonParser::JsonParser() {}

pt::ptree& JsonParser::getPtree()
{
    return root;
}
