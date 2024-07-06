#include "backtesting.h"

BacktestResult backtest(double capital, const std::vector<Data>& data, const std::vector<int>& signals) {
    double position = 0.0;
    double value = capital;

    std::vector<double> portfolioValues;
    std::vector<double> portfolioReturns;

    portfolioValues.reserve(data.size());
    portfolioReturns.reserve(data.size());

    portfolioValues.push_back(capital);
    portfolioReturns.push_back(0.0);

    for (size_t i = 1; i < data.size(); ++i) {
        if (signals[i - 1] == 1) { // Buy signal
            if (capital >= data[i].close) {
                position = capital / data[i].close;
                capital = 0.0;
            }
        } else if (signals[i - 1] == -1) { // Sell signal
            if (position > 0) {
                capital = position * data[i].close;
                position = 0.0;
            }
        }
        value = capital + position * data[i].close;
        portfolioValues.push_back(value);

        double ret = (portfolioValues[i] - portfolioValues[i - 1]) / portfolioValues[i - 1];
        portfolioReturns.push_back(ret);
    }

    BacktestResult result;
    result.portfolioValues = portfolioValues;
    result.portfolioReturns = portfolioReturns;

    return result;
}
