#include "Relic.h"
#include <iostream>

// --- Implementasi Relic 1 ---
std::string FlatBonusRelic::getName() const {
    return "Batu Permata (+50 Chips)";
}

void FlatBonusRelic::applyEffect(int& currentChips, int& currentMultiplier) {
    currentChips += 50; // Menambahkan 50 Chips secara langsung
    std::cout << "  [Efek Relic] " << getName() << " menyala!\n";
}

// --- Implementasi Relic 2 ---
std::string MultiplierRelic::getName() const {
    return "Cincin Kuno (x2 Mult)";
}

void MultiplierRelic::applyEffect(int& currentChips, int& currentMultiplier) {
    currentMultiplier *= 2; // Mengalikan Multiplier dengan 2
    std::cout << "  [Efek Relic] " << getName() << " menyala!\n";
}