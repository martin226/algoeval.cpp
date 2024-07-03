#include "RSIStrategy.h"
#include <numeric>
#include <algorithm>
#include <cmath>

std::vector<double> calculateRSI(const std::vector<Data>& data, int period) {
    std::vector<double> rsi(data.size(), 0.0);
    std::vector<double> gains(data.size(), 0.0);
    std::vector<double> losses(data.size(), 0.0);

    for (size_t i = 1; i < data.size(); ++i) {
        double change = data[i].close - data[i - 1].close;
        gains[i] = std::max(change, 0.0);
        losses[i] = std::max(-change, 0.0);
    }

    double avgGain = std::accumulate(gains.begin(), gains.begin() + period, 0.0) / period;
    double avgLoss = std::accumulate(losses.begin(), losses.begin() + period, 0.0) / period;

    for (size_t i = period; i < data.size(); ++i) {
        avgGain = (avgGain * (period - 1) + gains[i]) / period;
        avgLoss = (avgLoss * (period - 1) + losses[i]) / period;

        if (avgLoss == 0) {
            rsi[i] = 100;
        } else {
            rsi[i] = 100 - 100 / (1 + avgGain / avgLoss);
        }
    }

    return rsi;
}

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