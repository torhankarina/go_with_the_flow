#include "src/heat_flow.hpp"
#include "src/heat_flow_printer.hpp"
#include <map>
#include <iostream>

int main() {
  float initial_temperature; //for example 10
  int number_of_sections; //for example 5
  float K=0.1; // usually less than one so let it be 0.1

  std::cout << "Enter initial temperature of the rod: ";
  std::cin >> initial_temperature;

  std::cout << "Enter number of sections in the rod: ";
  std::cin >> number_of_sections;

  std::map<int, float> sources_and_sinks;

  sources_and_sinks[0] = 100.0f;

  HeatFlow flow(initial_temperature, number_of_sections, K, sources_and_sinks);
  HeatFlowPrinter printer(flow);

  int steps;
  std::cout << "Enter number of time steps to simulate: ";
  std::cin >> steps;

  for (int i = 0; i < steps; ++i) {
    flow.tick();
    printer.pretty_print();
  }

  return 0;
}