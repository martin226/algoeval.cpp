#ifndef INDICATORS_H
#define INDICATORS_H

#include <vector>

namespace algoeval {
    std::vector<double> calculateRSI(const std::vector<double>& closePrices, int period);
    std::vector<double> calculateEMA(const std::vector<double>& closePrices, int period);
    std::vector<double> calculateMACD(const std::vector<double>& closePrices, int shortPeriod, int longPeriod);
    std::vector<double> calculateSMA(const std::vector<double>& closePrices, int period);
    std::vector<double> calculateZScore(const std::vector<double>& closePrices, int period);
}

#endif // INDICATORS_H