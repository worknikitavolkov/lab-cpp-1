#pragma once

#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Exception {
    protected:
        string m_errorMessage;
        string m_nameOfLogFile;
    public:
        Exception(string error);
        const char* getDescription() const;
        void outputToLogFile() const;
};

class InvalidChoice : public Exception {
    public:
        InvalidChoice(string error);
};

class ArrayException : public Exception {
    public:
        ArrayException(string error);
};

class NotSquareException : public Exception {
    public:
        NotSquareException(string error);
};

class ReachedMaxPerimeterException : public Exception {
    public:
        ReachedMaxPerimeterException(string error);
};