#ifndef TAGSTRING_H
#define TAGSTRING_H

#include <tuple>
#include <string>
#include <algorithm>

template<size_t N>
struct StringLiteral {
    constexpr StringLiteral(const char (&str)[N]) {
        std::copy_n(str, N, value);
    }

    char value[N];
};

template <StringLiteral L>
struct getType
{
  using type = std::nullptr_t;
};

template<>
struct getType<"string">
{
    using type = std::string;
};

template<>
struct getType<"int">
{
    using type = int;
};

template<>
struct getType<"double">
{
    using type = double;
};

template<>
struct getType<"bool">
{
    using type = bool;
};

#endif // TAGSTRING_H
