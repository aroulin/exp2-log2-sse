#include <cmath>
#include <iostream>

#include "rdtsc.h"

using namespace std;

static const size_t num_trials = 1000 * 1000 * 1000;

int main() {
    cout << "Exp2 Benchmarks" << endl;

    uint64_t exp2_cycles = rdtsc();
    for (size_t i = 0; i < num_trials; ++i) {
        std::exp2((float)i);
    }
    exp2_cycles = rdtsc() - exp2_cycles;
    cout << "std::exp2: " << (double)exp2_cycles / (double)num_trials << " cycles" << endl;

    return 0;
}