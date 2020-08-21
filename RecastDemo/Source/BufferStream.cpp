#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BufferStream.h"

BufferStream::BufferStream(char* buffer, int size)
{
    _buffer = buffer;
    _size = size;
    _offset = 0;
}

int BufferStream::Read(void* output, int len)
{
    if(_size - _offset < len)
    {
        return -1;
    }

    memcpy(output, _buffer + _offset, len);
    _offset += len;
    return len;
}

int BufferStream::Read(void* output, int size, int count)
{
    if(_size - _offset < size * count)
    {
        return -1;
    }

    memcpy(output, _buffer + _offset, size * count);
    _offset += size * count;
    return count;
}

int BufferStream::GetSize()
{
    return _size;
}

int BufferStream::GetRemainSize()
{
    return _size - _offset;
}

int BufferStream::AdjustOffset(int delta)
{
    _offset += delta;
    if (_offset < 0)
    {
        _offset = 0;
    }
    else if (_offset > _size)
    {
        _offset = _size;
    }
    return _offset;
}


