# CppStrings

This repository contains the CppStrings test program.

## Requirements
The program must:
- read a set of strings from a file or standard input.
- handle a "sort" option. Depending on the argument passed to this option (asc|desc) sorts the list of strings in "ascending" or "descending" order.
- handle "unique" option: if given the program must remove duplicates from the list.
- write the resulting list to a file or to the standard output.

## Implementation
CppStrings uses:
- standard C++17 compiler (compiled and tested with gcc-11.2.0 X64 MinGW-W64-builds-5.0.0)
- cxxopts library v3.1.1 (imported directly by cmake file https://github.com/jarro2783/cxxopts.git)


## Usage

**ps. *Please, if you enter string list from standard input: QtCreator output panel handles badly the console input (buggy), so please check the "run in terminal" option to force the program to run in a true terminal and then handle correctly empty string when Enter is hit directly.***

CppStrings [OPTION...]

To get help
```
$CppStrings --help  
```

To read data from file "myinput.txt", sort them ascending and write ouput to "myout.txt"
```
$CppStrings -i myinput.txt -s asc -o myout.txt
```

To read data from standard input, sort them descending, remode duplicates and write standard ouput
```
$CppStrings -s desc -u
```
