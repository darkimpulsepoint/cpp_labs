#pragma once
#include <string>

class FileReader {

public:
    static std::string read(const std::string& filename);
};


class empty_file: public std::exception
{
public:
    empty_file(const std::string& message = "file is empty"): message{message}
    {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};