#include <cmath>
#include <iomanip>
#include <iostream>

#include "rdtsc.h"

using namespace std;

namespace SSE {
extern "C" {
    float Exp2f(float x);
}
}

double __attribute__((always_inline)) Benchmark(float (*f)(float), size_t num_trials) {
    uint64_t cycles = rdtsc();
    for (size_t i = 0; i < num_trials; ++i) {
        f((float)i);
    }
    return (double)(rdtsc() - cycles) / (double)num_trials;
}

int main() {
    const size_t num_trials = 100 * 1000 * 1000;

    printf("Benchmarks\n");
    double std_exp2f_cycles = Benchmark(std::exp2f, num_trials);
    double sse_exp2f_cycles = Benchmark(SSE::Exp2f, num_trials);
    printf("std::exp2f: %lf cycles\n", std_exp2f_cycles);
    printf("SSE::Exp2f: %lf cycles\n", sse_exp2f_cycles);
    printf("Speedup of %lfX\n", std_exp2f_cycles  / sse_exp2f_cycles);

    return 0;
}
