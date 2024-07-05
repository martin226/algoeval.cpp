#include "signals.h"
#include "indicators.h"
#include <numeric>
#include <algorithm>

std::vector<int> generateRSISignals(const std::vector<double>& rsi, double overboughtThreshold, double oversoldThreshold) {
    std::vector<int> signals(rsi.size(), 0);

    for (size_t i = 1; i < rsi.size(); ++i) {
        if (rsi[i - 1] < oversoldThreshold && rsi[i] >= oversoldThreshold) {
            signals[i] = 1; // Buy signal
        } else if (rsi[i - 1] > overboughtThreshold && rsi[i] <= overboughtThreshold) {
            signals[i] = -1; // Sell signal
        } else {
            signals[i] = 0; // Hold signal
        }
    }

    return signals;
}

std::vector<int> generateMACDSignals(const std::vector<double>& macd, int signalPeriod) {
    std::vector<int> signals(macd.size(), 0);

    std::vector<double> signalLine = calculateEMA(macd, signalPeriod);

    for (size_t i = 1; i < macd.size(); ++i) {
        if (macd[i - 1] < signalLine[i - 1] && macd[i] >= signalLine[i]) {
            signals[i] = 1; // Buy signal
        } else if (macd[i - 1] > signalLine[i - 1] && macd[i] <= signalLine[i]) {
            signals[i] = -1; // Sell signal
        } else {
            signals[i] = 0; // Hold signal
        }
    }

    return signals;
}