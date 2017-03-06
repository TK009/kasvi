
#include "StreamConnector.h"
//#include <cstring.h>

StreamConnector::StreamConnector() : m_currentInput(nullptr), m_lengthRemaining(0)
{
}


//StreamConnector::setOutputBufferSize(int size) {
//
//}

bool StreamConnector::provideInput(const char* start, size_t length){
    if (!available()) {
        m_lengthRemaining = length;
        m_currentInput = start;
    }
}
bool StreamConnector::provideInput(const char* string){
    provideInput(string, strlen(string));
}

int StreamConnector::available() {
    return m_lengthRemaining;
}
int StreamConnector::read() {
    if (m_lengthRemaining > 0) {
        m_lengthRemaining--;
        return *m_currentInput++;
    }
    return -1;
}
int StreamConnector::peek() {
    if (m_lengthRemaining > 0)
        return *m_currentInput;
    else
        return -1;
}

// TODO write interface
size_t StreamConnector::write(uint8_t) {
    return 1;
}
// TODO write interface
size_t StreamConnector::write(const uint8_t *buffer, size_t size) {
    (void) buffer;
    return size;
}
