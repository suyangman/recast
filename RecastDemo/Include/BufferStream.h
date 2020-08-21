#pragma once

class BufferStream
{
    public:
        BufferStream(char* buffer, int size);
        int Read(void* output, int len);
        int Read(void* output, int size, int count);

        int GetSize();
        int GetRemainSize();
        int AdjustOffset(int delta);

    private:
        char* _buffer;
        int   _size;
        int   _offset;
};
