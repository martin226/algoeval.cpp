#ifndef INDICATORS_H
#define INDICATORS_H

#include <vector>

std::vector<double> calculateRSI(const std::vector<double>& closePrices, int period);

#endif // INDICATORS_H