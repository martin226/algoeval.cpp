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

std::vector<double> calculateEMA(const std::vector<double>& closePrices, int period) {
    std::vector<double> ema(closePrices.size(), 0.0);

    double multiplier = 2.0 / (period + 1);
    ema[period - 1] = std::accumulate(closePrices.begin(), closePrices.begin() + period, 0.0) / period;

    for (size_t i = period; i < closePrices.size(); ++i) {
        ema[i] = (closePrices[i] - ema[i - 1]) * multiplier + ema[i - 1];
    }

    return ema;
}

std::vector<double> calculateMACD(const std::vector<double>& closePrices, int shortPeriod, int longPeriod) {
    std::vector<double> macd(closePrices.size(), 0.0);
    std::vector<double> emaShort = calculateEMA(closePrices, shortPeriod);
    std::vector<double> emaLong = calculateEMA(closePrices, longPeriod);

    for (size_t i = longPeriod; i < closePrices.size(); ++i) {
        macd[i] = emaShort[i] - emaLong[i];
    }

    return macd;
}

std::vector<double> calculateSMA(const std::vector<double>& closePrices, int period) {
    std::vector<double> sma(closePrices.size(), 0.0);

    for (size_t i = period; i < closePrices.size(); ++i) {
        sma[i] = std::accumulate(closePrices.begin() + i - period, closePrices.begin() + i, 0.0) / period;
    }

    return sma;
}

std::vector<double> calculateZScore(const std::vector<double>& closePrices, int period) {
    std::vector<double> zScore(closePrices.size(), 0.0);

    for (size_t i = period - 1; i < closePrices.size(); ++i) {
        double sum = 0.0;
        for (int j = 0; j < period; ++j) {
            sum += closePrices[i - j];
        }
        double sma = sum / period;

        double stddevSum = 0.0;
        for (int j = 0; j < period; ++j) {
            stddevSum += std::pow(closePrices[i - j] - sma, 2);
        }
        double stddev = std::sqrt(stddevSum / period);

        zScore[i] = (closePrices[i] - sma) / stddev;
    }

    return zScore;
}