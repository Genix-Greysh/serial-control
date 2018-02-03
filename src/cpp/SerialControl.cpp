#include "SerialControl.h"

int fd;
bool isConnected = false;
char msgBuffer [MAX_BUFFER_SIZE];

bool SerialControl::connect(std::string & portName) {
    fd = open(portName.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    switch(fd) {
        case -1 : perror("open_port: Unable to open /dev/ttyf1 - ");
                  return false;
                  break;
        default : fcntl(fd, F_SETFL, 0); isConnected= true; break;
    }
    return 1;
}

bool SerialControl::readData(std::string & messageBuffer) {
    fcntl(fd, F_SETFL, FNDELAY);
    const int result = read(fd, &msgBuffer, MAX_BUFFER_SIZE);
    
    if(result == 0) return 0;
    
    messageBuffer = msgBuffer;
    return 1;
}

bool SerialControl::writeData(std::string & message) {
    const int result = write(fd, message.c_str(), MAX_BUFFER_SIZE);
    return result != -1;
}

void SerialControl::disconnect() {
    if(isConnected) close(fd);
}
