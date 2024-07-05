#ifndef INDICATORS_H
#define INDICATORS_H

#include <vector>

std::vector<double> calculateRSI(const std::vector<double>& closePrices, int period);
std::vector<double> calculateEMA(const std::vector<double>& closePrices, int period);
std::vector<double> calculateMACD(const std::vector<double>& closePrices, int shortPeriod, int longPeriod);

#endif // INDICATORS_H