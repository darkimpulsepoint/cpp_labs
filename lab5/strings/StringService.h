#pragma once
#include <string>
#include <vector>

class StringService {
public:
    static std::string getInsertAfterSubstring(const std::string& filename, const std::string& substring, const std::string& wordToInsert);
    static std::vector<std::string> findUniqueWordsOfLengthInQuestion(const std::string& filename, int length);
    static std::string decompress(const std::string& filename);
};
