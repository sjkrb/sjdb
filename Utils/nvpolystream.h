#ifndef NVPOLYSTREAM_H
#define NVPOLYSTREAM_H

#include <fstream>
#include <iostream>

template <typename T>
struct NVType
{
    T* type() {return static_cast<T*>(this);}

    T* operator()(std::ifstream *strm)
    {
        type()->operator()(strm);
        return type();
    }

    auto value()
    {
        return type()->m_value;
    }

    void setValue(auto newValue)
    {
        type()->m_value = newValue;
    }
};

struct intVal : public NVType<intVal>
{
    int m_value{};

    intVal* operator()(std::ifstream *strm)
    {
        strm->read((char*)this, sizeof(intVal));
        return type();
    }
};

struct doubleVal : public NVType<doubleVal>
{
    double m_value{};

    doubleVal* operator()(std::ifstream *strm)
    {
        strm->read((char*)this, sizeof(doubleVal));
        return this;
    }
};

struct boolVal : public NVType<boolVal>
{
    bool m_value{};

    boolVal* operator()(std::ifstream *strm)
    {
        strm->read((char*)this, sizeof(boolVal));
        return this;
    }
};

template <size_t N>
struct stringVal : public NVType<stringVal<N>>
{
    char m_value[N];

    stringVal* operator()(std::ifstream *strm)
    {
        strm->read((char*)this, N);
        return this;
    }
};



#endif // NVPOLYSTREAM_H
