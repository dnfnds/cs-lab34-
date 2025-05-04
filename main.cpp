#include <iostream>
#include <vector>
#include "histogram.h"
#include "text.h"
#include "svg.h"
using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

Input input_data() {
    Input in;
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    in.numbers.resize(number_count);
    cerr << "Enter numbers: ";
    for (size_t i = 0; i < number_count; i++) {
        cin >> in.numbers[i];
    }

    cerr << "Enter bin count: ";
    cin >> in.bin_count;
    return in;
}

int main() {
    auto in = input_data();
    auto bins = make_histogram(in.numbers, in.bin_count);
    show_histogram_svg(bins);
    return 0;
}

