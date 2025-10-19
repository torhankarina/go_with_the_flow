#pragma once

#include "heat_flow.hpp"

class HeatFlowPrinter {
public:
    HeatFlowPrinter(const HeatFlow& flow);
    void pretty_print() const;

private:
    const HeatFlow& flow_;
};
