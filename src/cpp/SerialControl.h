#pragma once
#define MAX_BUFFER_SIZE 255

#include <stdio.h>   /* Standard input/output definitions */
#include <unistd.h>
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <string>

namespace SerialControl {
    bool connect(std::string & portName);
    void disconnect();
    bool readData(std::string & messageBuffer);
    bool writeData(std::string & message);
}