#include "heat_flow_printer.hpp"
#include <iostream>
#include <iomanip>

HeatFlowPrinter::HeatFlowPrinter(const HeatFlow& flow)
    : flow_(flow) {}

void HeatFlowPrinter::pretty_print() const {
   const auto& temps = flow_.get_temperatures();

   std::cout << "+";
   for (size_t i = 0; i < temps.size(); ++i) {
      std::cout << "--------+";
   }
   std::cout << "\n|";

   for (float temp : temps) {
      std::cout << std::setw(7) << std::fixed << std::setprecision(1) << temp << " |";
   }

   std::cout << "\n+";
   for (size_t i = 0; i < temps.size(); ++i) {
      std::cout << "--------+";
   }
   std::cout << "\n";
}
