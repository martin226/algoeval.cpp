#include "backtesting.h"

void Backtest::setData(const std::vector<Data>& data) {
    this->data = data;
}

void Backtest::setSignals(const std::vector<int>& signals) {
    this->signals = signals;
}

std::vector<double> Backtest::getPortfolioValues() const {
    return portfolioValues;
}

std::vector<double> Backtest::getPortfolioReturns() const {
    return portfolioReturns;
}

void Backtest::backtest(double capital) {
    double position = 0.0;
    double value = capital;

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
}
