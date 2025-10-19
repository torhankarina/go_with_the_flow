#pragma once
#include <vector>
#include <map>

class HeatFlow {
public:
    HeatFlow(float initial_temperature, int sections, float K, const std::map<int, float>& sources);

    void tick();
    const std::vector<float>& get_temperatures() const;

private:
    int sections_;
    float K_;
    std::map<int, float> sources_;
    std::vector<float> temperatures_;
};
