#ifndef BACKTESTING_H
#define BACKTESTING_H

#include "data.h"
#include <vector>

namespace algoeval {
    class Backtest {
        private:
            std::vector<Data> data;
            std::vector<int> signals;
            std::vector<double> portfolioValues;
            std::vector<double> portfolioReturns;
        public:
            void setData(const std::vector<Data>& data);
            void setSignals(const std::vector<int>& signals);
            std::vector<double> getPortfolioValues() const;
            std::vector<double> getPortfolioReturns() const;
            void backtest(double capital);
    };
}

#endif // BACKTESTING_H