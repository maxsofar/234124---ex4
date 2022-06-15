#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::runtime_error {
public:
    explicit Exception(const std::string& what) : std::runtime_error(what)
    {}
};

class  DeckFileNotFound : public Exception {
public:
    DeckFileNotFound() : Exception("Deck File Error: File not found")
    {}
};

class  DeckFileFormatError : public  Exception {
public:
    explicit DeckFileFormatError(int lineNumber)
        : Exception("Deck File Error: File format error in line " + std::to_string(lineNumber))
    {}
};

class DeckFileInvalidSize : public Exception {
public:
    DeckFileInvalidSize() : Exception("Deck File Error: Deck size is invalid")
    {}
};
#endif //EX4_EXCEPTION_H
