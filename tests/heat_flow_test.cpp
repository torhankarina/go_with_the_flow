#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/heat_flow.hpp"

TEST_CASE("HeatFlow tick updates temperatures") {
    std::map<int, float> sources;
    sources[0] = 100.0f;
    HeatFlow flow(10.0f, 3, 0.1f, sources);

    flow.tick();
    auto temps = flow.get_temperatures();

 REQUIRE(temps[0] == 100.0f);
 REQUIRE(abs(temps[1] - 19.0f) < 0.01);
 REQUIRE(abs(temps[2] - 10.0f) < 0.01);
 }
