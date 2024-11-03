#include "FractionService.h"

void FractionService::modifyFractions(std::vector<Fraction>& fractions) {
    for (size_t i = 0; i < fractions.size(); i += 2) {
        if (i + 1 < fractions.size()) {
            fractions[i] = fractions[i] + fractions[i + 1];
        }
    }
}