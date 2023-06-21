#include <vector>

#include "inputdatahandler.h"
#include "outputdatahandler.h"
#include "commandlineprocessor.h"
#include "stringlistprocessor.h"

int main(int argc, char* argv[])
{
    InputDataHandler inputHandler;
    OutputDataHandler outputHandler;
    StringListProcessor listProcessor;

    CommandLineProcessor cmdLineProcessor;
    CommandLineOptions cmdOptions = cmdLineProcessor.parseCommandLine(argc, argv);

    //The variable strings serves as data model. No need to create a complete class to
    //act as datamodel for this simple exercise
    std::vector<std::string> strings = inputHandler.readStringsFromInput(cmdOptions.inputFile);

    switch(cmdOptions.sortOption)
    {
        case SortOptions::SO_ASC:
            listProcessor.sortStringsAscending(strings);
            break;

        case SortOptions::SO_DESC:
            listProcessor.sortStringsDescending(strings);
            break;

        default: // to avoid warning on some compilers
            break;
    }

    // Remove duplicates if the unique option is enabled
    // The test about sortOption is redundant because we force user to provide a sort option
    // during param parsing, but since the uniqueness algo works on sorted vectors only
    // this test adds a bit of robustness
    if ((cmdOptions.uniqueOption) && (cmdOptions.sortOption != SortOptions::SO_NONE)) {
        listProcessor.removeDuplicates(strings);
    }

    outputHandler.outputStrings(strings, cmdOptions.outputFile);

    return 0;
}
