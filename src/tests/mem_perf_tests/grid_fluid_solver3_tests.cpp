// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "mem_perf_tests.h"
#include <jet/grid_fluid_solver3.h>
#include <jet/timer.h>
#include <gtest/gtest.h>

using namespace jet;

TEST(GridFluidSolver3, Memory) {
    const size_t n = 300;

    const size_t mem0 = getCurrentRSS();

    auto solver = GridFluidSolver3::builder()
        .withResolution({n, n, n})
        .makeShared();

    const size_t mem1 = getCurrentRSS();

    const auto msg1 = makeReadableByteSize(mem1 - mem0);

    JET_PRINT_INFO(
        "Start mem. usage: %f %s.\n",
        msg1.first,
        msg1.second.c_str());

    solver->update(Frame(1, 0.01));

    const size_t mem2 = getCurrentRSS();

    const auto msg2 = makeReadableByteSize(mem2 - mem0);

    JET_PRINT_INFO(
        "Single update mem. usage: %f %s.\n",
        msg2.first,
        msg2.second.c_str());
}
