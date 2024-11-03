#include "Serializer.h"

std::string Serializer::serialize(const std::map<std::string, std::string>& data) {
    std::string content;

    content += "<" + data.at("objectType") + ">\n";
    for (const auto& [key, value] : data) {
        content += "  <" + key + ">" + value + "</" + key + ">\n";
    }
    content += "</" + data.at("objectType") + ">\n";

    return content; // Return the constructed content
}