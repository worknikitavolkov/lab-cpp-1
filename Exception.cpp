#include "Exception.h"

/* Definitions for Exception */
Exception::Exception(string error) : m_errorMessage(error), m_nameOfLogFile("errors_log.txt") {}

const char* Exception::getDescription() const {
    return m_errorMessage.c_str();
}

void Exception::outputToLogFile() const {
    ofstream log(m_nameOfLogFile, ios::app);
    time_t now = time(0);
    string dt = ctime(&now);
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    
    if (log.is_open()) {
        log << dt << " | " << getDescription() << endl;
        log.close();
    }
}

/* Definitions for InvalidChoice */
InvalidChoice::InvalidChoice(string error) : Exception(error) {}

/* Definitions for ArrayException */
ArrayException::ArrayException(string error) : Exception(error) {}

/* Definitions for NotSquareException */
NotSquareException::NotSquareException(string error) : Exception(error) {}

/* Definitions for ReachedMaxPerimeterException */
ReachedMaxPerimeterException::ReachedMaxPerimeterException(string error) : Exception(error) {}
