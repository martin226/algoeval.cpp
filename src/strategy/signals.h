#ifndef SIGNALS_H
#define SIGNALS_H

#include <vector>

std::vector<int> generateRSISignals(const std::vector<double>& rsi, double overboughtThreshold, double oversoldThreshold);
std::vector<int> generateMACDSignals(const std::vector<double>& macd, int signalPeriod);

#endif // SIGNALS_H