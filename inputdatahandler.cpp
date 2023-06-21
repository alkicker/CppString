#include "inputdatahandler.h"

std::vector<std::string> InputDataHandler::readStringsFromInput(const std::optional<std::filesystem::path> inputFile) const
{
    if (inputFile.has_value())
    {
        return readStringsFromFile(inputFile.value());
    } else
    {
        return readStringsFromStdin();
    }
}

std::vector<std::string> InputDataHandler::readStringsFromStdin() const
{
    std::vector<std::string> strings;
    std::string line;
    std::cout << "Enter the strings to sort one after the other. Validate each string with Enter" << std::endl;
    while (std::getline(std::cin, line))
    {
        if(line == "") // dirty hack for windows
        {
            break;
        }
        strings.push_back(line);
    }
    return strings;
}

std::vector<std::string> InputDataHandler::readStringsFromFile(const std::filesystem::path &filename) const
{
    std::vector<std::string> strings;
    try
    {
        if (!std::filesystem::exists(filename.string()))
        {
            throw std::runtime_error("File not found: " + filename.string());
        }

        std::ifstream file(filename.string());
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open input file " + filename.string());
        }

        std::string line;
        while (std::getline(file, line))
        {
            strings.push_back(line);
        }
    } catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return strings;
}
