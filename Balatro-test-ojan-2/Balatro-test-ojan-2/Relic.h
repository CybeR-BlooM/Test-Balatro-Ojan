#pragma once
#include "IModifier.h"

// RELIC 1: Batu Permata (Menambah +50 Base Chips)
class FlatBonusRelic : public IModifier {
public:
    std::string getName() const override;
    void applyEffect(int& currentChips, int& currentMultiplier) override;
};

// RELIC 2: Cincin Kuno (Mengalikan Multiplier x2)
class MultiplierRelic : public IModifier {
public:
    std::string getName() const override;
    void applyEffect(int& currentChips, int& currentMultiplier) override;
};