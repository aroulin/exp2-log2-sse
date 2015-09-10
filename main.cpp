#include <cmath>
#include <iomanip>
#include <iostream>

#include "rdtsc.h"

using namespace std;

extern "C" {
    float Exp2(float x);
}

static const size_t num_trials = 1000 * 1000 * 100;

#define PAD left << setw(20) << setfill(' ')
#define TEST(x) cout << PAD << x << PAD << std::exp2(x) << PAD << Exp2(x) << PAD << abs(std::exp2(x) - Exp2(x)) << endl 

int main() {

    TEST(0.0f);
    TEST(3.5f);
    TEST(-1.0f);
    TEST(-2.75f);
    TEST(128.0f);
    TEST(-127.0f);
    TEST(INFINITY);
    TEST(-INFINITY);
    TEST(NAN);

    cout << endl << "Benchmarks" << endl;

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
