#include "heat_flow.hpp"

HeatFlow::HeatFlow(float initial_temperature, int sections, float K, const std::map<int, float>& sources)
    : sections_(sections), K_(K), sources_(sources), temperatures_(sections, initial_temperature) {
  for (const auto& [pos, temp] : sources_) {
    if (pos >= 0 && pos < sections_) {
      temperatures_[pos] = temp;
    }
  }
}

void HeatFlow::tick() {
  std::vector<float> new_temps = temperatures_;

  for (int i = 0; i < sections_; ++i) {
    if (sources_.count(i)) {
      new_temps[i] = sources_.at(i);
    } else {
      float left = (i > 0) ? temperatures_[i - 1] : temperatures_[i];
      float right = (i < sections_ - 1) ? temperatures_[i + 1] : temperatures_[i];
      new_temps[i] = temperatures_[i] + K_ * (right - 2 * temperatures_[i] + left);
    }
  }

  temperatures_ = new_temps;
}

const std::vector<float>& HeatFlow::get_temperatures() const {
  return temperatures_;
}
