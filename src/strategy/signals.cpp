#include "signals.h"
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