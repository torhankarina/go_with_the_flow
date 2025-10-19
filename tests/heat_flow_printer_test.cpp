#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/heat_flow.hpp"
#include "../src/heat_flow_printer.hpp"


TEST_CASE( "HeatFlowPrinter test" ) {
    std::map<int, float> sources;
    sources[0] = 100.0f;
    HeatFlow flow(10.0f, 5, 0.1f, sources);
    HeatFlowPrinter printer(flow);

    flow.tick();
    REQUIRE_NOTHROW(printer.pretty_print());
}
