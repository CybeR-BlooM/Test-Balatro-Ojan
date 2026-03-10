#include "ScoringStrategy.h"

// --- HIGH CARD ---
void HighCardStrategy::applyScore(int& baseChips, int& multiplier) {
    baseChips = 5;
    multiplier = 1;
}
std::string HighCardStrategy::getHandName() const { return "High Card"; }

// --- PAIR ---
void PairStrategy::applyScore(int& baseChips, int& multiplier) {
    baseChips = 10;
    multiplier = 2;
}
std::string PairStrategy::getHandName() const { return "Pair"; }

// --- FLUSH ---
void FlushStrategy::applyScore(int& baseChips, int& multiplier) {
    baseChips = 35;
    multiplier = 4;
}
std::string FlushStrategy::getHandName() const { return "Flush"; }