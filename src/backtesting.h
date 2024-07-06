#ifndef BACKTESTING_H
#define BACKTESTING_H

#include "data.h"
#include <vector>

struct BacktestResult {
    std::vector<double> portfolioValues;
    std::vector<double> portfolioReturns;
};

BacktestResult backtest(double capital, const std::vector<Data>& data, const std::vector<int>& signals);

#endif // BACKTESTING_H