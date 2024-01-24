#ifndef NVPOLYSTREAM_H
#define NVPOLYSTREAM_H

#include <fstream>

template <typename T>
struct NVType
{
    T* type() {return static_cast<T*>(this);}

    T* operator()(std::ifstream *strm)
    {
        strm->read((char*)type(), sizeof(T));
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
};

struct doubleVal : public NVType<doubleVal>
{
    double m_value{};
};

struct boolVal : public NVType<boolVal>
{
    bool m_value{};
};

template <size_t N>
struct stringVal : public NVType<stringVal<N>>
{
    char m_value[N];
};



#endif // NVPOLYSTREAM_H
