#ifndef SIGNALS_H
#define SIGNALS_H

#include <vector>

std::vector<int> generateRSISignals(const std::vector<double>& rsi, double overboughtThreshold, double oversoldThreshold);
std::vector<int> generateMACDSignals(const std::vector<double>& macd, int signalPeriod);
std::vector<int> generateSMACSignals(const std::vector<double>& smaShort, const std::vector<double>& smaLong);
std::vector<int> generateZScoreSignals(const std::vector<double>& zScore, double buyThreshold, double sellThreshold);

#endif // SIGNALS_H