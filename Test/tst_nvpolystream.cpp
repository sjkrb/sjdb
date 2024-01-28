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

    std::tuple<NVType<intVal>, NVType<stringVal<13>>, NVType<intVal>, NVType<doubleVal>> d;
    REQUIRE(std::get<0>(d)(istrm)->value() == strlen("sajjad hastam"));
    REQUIRE(std::strncmp(std::get<1>(d)(istrm)->value() , "sajjad hastam", strlen("sajjad hastam")) == 0);
    REQUIRE(std::get<2>(d)(istrm)->value() == 1234);
    REQUIRE(std::get<3>(d)(istrm)->value() == 1.2345);

    istrm->close();

}
#undef private
