#ifndef RSI_STRATEGY_H
#define RSI_STRATEGY_H

#include <vector>
#include "../Data.h"

std::vector<double> calculateRSI(const std::vector<Data>& data, int period);
std::vector<int> generateRSISignals(const std::vector<double>& rsi, double overboughtThreshold, double oversoldThreshold);

#endif // RSI_STRATEGY_H