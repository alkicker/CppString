#ifndef COMMANDLINEPROCESSOR_H
#define COMMANDLINEPROCESSOR_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <cxxopts.hpp>


enum SortOptions {SO_NONE, SO_ASC, SO_DESC};

struct CommandLineOptions
{
    SortOptions sortOption = SortOptions::SO_NONE;
    bool uniqueOption;
    std::optional<std::filesystem::path> inputFile;
    std::optional<std::filesystem::path> outputFile;
};

class CommandLineProcessor {
public:
    CommandLineProcessor() {}
    CommandLineOptions parseCommandLine(int argc, char* argv[]);
};

#endif // COMMANDLINEPROCESSOR_H
