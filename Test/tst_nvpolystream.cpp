#include <catch2/catch_all.hpp>

#define private public
#include "../Utils/nvpolystream.h"
#include <fstream>
#include <tuple>
#include <iostream>

TEST_CASE("POLYSTREAM") {
    std::ofstream *strm{new std::ofstream()};
    strm->open("nvpolystream.txt", std::ios::binary | std::ios::out | std::ios::in);

    if(!strm->is_open())
        std::cout << "file is not open";
    int size = strlen("sajjad hastam");
    strm->write((char*)&size, sizeof(size));
    strm->write("sajjad hastam", strlen("sajjad hastam"));
    int value{1234};
    strm->write((char*)&value, sizeof(int));
    double dValue{1.2345};
    strm->write((char*)&dValue, sizeof(double));

    strm->flush();
    strm->close();
    delete strm;

    std::ifstream *istrm{new std::ifstream()};
    istrm->open("nvpolystream.txt", std::ios::binary | std::ios::out | std::ios::in);

    if(!istrm->is_open())
        std::cout << "file is not open";

    std::tuple<NVType<intVal>, NVType<stringVal<13>>, intVal, doubleVal> d;
    REQUIRE(std::get<0>(d)(istrm)->value() == strlen("sajjad hastam"));
    REQUIRE(std::get<1>(d)(istrm)->value() == std::string("sajjad hastam"));

    istrm->close();

}
#undef private
