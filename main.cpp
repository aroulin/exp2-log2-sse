#include <cmath>
#include <iostream>

#include "rdtsc.h"

using namespace std;

extern "C" {
    float Exp2(float x);
}

static const size_t num_trials = 1000 * 1000 * 100;

int main() {
    cout << "Exp2 Benchmarks" << endl;

    cout << "Quick test: std::exp2(3.5f) = " << std::exp2(3.5) << ", Exp2(3.5f) = " << Exp2(3.5f) << endl;

    uint64_t exp2_cycles = rdtsc();
    for (size_t i = 0; i < num_trials; ++i) {
        std::exp2((float)i);
    }
    exp2_cycles = rdtsc() - exp2_cycles;
    cout << "std::exp2: " << (double)exp2_cycles / (double)num_trials << " cycles" << endl;

    uint64_t Exp2_cycles = rdtsc();
    for (size_t i = 0; i < num_trials; ++i) {
        Exp2((float)i);
    }
    Exp2_cycles = rdtsc() - Exp2_cycles;
    cout << "Exp2: " << (double)Exp2_cycles / (double)num_trials << " cycles" << endl;
    cout << "Speedup of " << (double)exp2_cycles  / (double)Exp2_cycles << "X" << endl;

    return 0;
}
