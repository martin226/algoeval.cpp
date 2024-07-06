#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

namespace algoeval {
    struct Data {
        std::string date;
        double open;
        double high;
        double low;
        double close;
        int volume;
    };

    std::vector<Data> readCSV(const std::string& filename);
}

#endif // DATA_H