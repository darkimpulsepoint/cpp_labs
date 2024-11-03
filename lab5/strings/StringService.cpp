#include "StringService.h"
#include "FileReader.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

std::string StringService::getInsertAfterSubstring(const std::string& filename, const std::string& substring, const std::string& wordToInsert) {
    std::string text = FileReader::read(filename);

    if (substring.empty()) {return text;}

    std::string result;
    size_t position = 0;

    while (position < text.size()) {
        size_t nextSpace = text.find(' ', position);
        std::string word;

        if (nextSpace == std::string::npos) {
            word = text.substr(position);
            position = text.size();
        } else {
            word = text.substr(position, nextSpace - position);
            position = nextSpace + 1;
        }

        result += word;
        if (word.size() >= substring.size() && word.compare(word.size() - substring.size(), substring.size(), substring) == 0) {
            result += wordToInsert;
        }
        if (position < text.size()) {
            result += " ";
        }
    }

    return result;
}

std::vector<std::string> StringService::findUniqueWordsOfLengthInQuestion(const std::string& filename, int length) {
    std::string text = FileReader::read(filename);
    std::set<std::string> uniqueWords;
    std::string::size_type start = 0, end;

    while ((end = text.find_first_of(".!?", start)) != std::string::npos) {
        std::string sentence = text.substr(start, end - start + 1);
        if (sentence.find('?') != std::string::npos) {
            std::stringstream wordStream(sentence);
            std::string word;

            while (wordStream >> word) {
                word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

                boost::to_lower(word);

                if (word.length() == length) {
                    uniqueWords.insert(word);
                }
            }
        }
        start = end + 1;
    }

    if (start < text.size()) {
        std::string sentence = text.substr(start);
        if (sentence.find('?') != std::string::npos) {
            std::stringstream wordStream(sentence);
            std::string word;

            while (wordStream >> word) {
                word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

                boost::to_lower(word);

                if (word.length() == length) {
                    uniqueWords.insert(word);
                }
            }
        }
    }

    return std::vector<std::string>(uniqueWords.begin(), uniqueWords.end());
}

std::string StringService::decompress(const std::string& filename) {
    std::string compressed = FileReader::read(filename);
    std::string decompressed = "";
    size_t i = 0;

    while (i < compressed.size()) {
        char ch = compressed[i];

        i++;
        if (i < compressed.size() && isdigit(compressed[i])) {
            int count = 0;
            while (i < compressed.size() && isdigit(compressed[i])) {
                count = count * 10 + (compressed[i] - '0');
                i++;
            }
            decompressed.append(count, ch);
        }
    }

    return decompressed;
}