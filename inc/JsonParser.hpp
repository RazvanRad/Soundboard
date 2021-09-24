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
/**
 * Used by Config
 * 
 */
class JsonParser
{
public:
    /**
     * @brief Opens the file and parses the Json
     */
    JsonParser(const std::string &filename);
    
    pt::ptree& getPtree();
private:
    JsonParser(); 
    
    pt::ptree root;
};
#endif