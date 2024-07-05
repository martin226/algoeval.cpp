#ifndef SIGNALS_H
#define SIGNALS_H

#include <vector>

std::vector<int> generateRSISignals(const std::vector<double>& rsi, double overboughtThreshold, double oversoldThreshold);

#endif // SIGNALS_H