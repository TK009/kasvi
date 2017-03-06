#ifndef STREAM_CONNECTOR_H
#define STREAM_CONNECTOR_H

#include <Arduino.h>

class StreamConnector : public Stream
{
public:
    StreamConnector();
    //setOutputBufferSize(int);
    //setInputBufferSize(int);
    bool provideInput(const char* start, size_t length);
    bool provideInput(const char* string);
    //provideInput(const String& string);
    //provideInput(Stream& s);
    int available();

    size_t write(uint8_t);
    size_t write(const uint8_t*, size_t);
    int read();

    int peek();
    void flush() {};

protected:

private:
    const char* m_currentInput;
    size_t m_lengthRemaining;
    
};



#endif
