#pragma once
#include "IMPL/LCGenericObjectImpl.h"
#include "Buffer.h"
//From an original class/code by Laurent Mirabito
class LMGeneric: public IMPL::LCGenericObjectImpl
{
public:
    LMGeneric(){};
    std::vector<int>& getIntVector()
    {
        return _intVec;
    }
    int* getIntBuffer()
    {
        return _intVec.empty() ? nullptr : &_intVec[0];
    }
    uint8_t* getCharBuffer()
    {
        return (uint8_t*) getIntBuffer();
    }
    unsigned int nBytes()
    {
        return getNInt()*sizeof(int32_t);   //4 bytes for each int
    }
    Buffer getBuffer()
    {
        return Buffer(getCharBuffer(),nBytes());
    }
};
