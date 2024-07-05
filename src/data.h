#ifndef DATA_H
#define DATA_H

#include <string>

struct Data {
    std::string date;
    double open;
    double high;
    double low;
    double close;
    int volume;
};

#endif // DATA_H