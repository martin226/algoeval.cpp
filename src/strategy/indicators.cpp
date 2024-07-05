#include "indicators.h"
#include <numeric>
#include <algorithm>

std::vector<double> calculateRSI(const std::vector<double>& closePrices, int period) {
    std::vector<double> rsi(closePrices.size(), 0.0);
    std::vector<double> gains(closePrices.size(), 0.0);
    std::vector<double> losses(closePrices.size(), 0.0);

    for (size_t i = 1; i < closePrices.size(); ++i) {
        double change = closePrices[i] - closePrices[i - 1];
        gains[i] = std::max(change, 0.0);
        losses[i] = std::max(-change, 0.0);
    }

    double avgGain = std::accumulate(gains.begin(), gains.begin() + period, 0.0) / period;
    double avgLoss = std::accumulate(losses.begin(), losses.begin() + period, 0.0) / period;

    for (size_t i = period; i < closePrices.size(); ++i) {
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