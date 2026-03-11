#pragma once
#include "Card.h"
#include "ScoringStrategy.h"
#include <vector>

class ScoringSystem {
private:
    // Fungsi mengubah rank kartu menjadi nilai Chip (J,Q,K = 10, Ace = 11)
    int getCardValue(Rank rank);

public:
    // Fungsi utama untuk menilai kartu yang dimainkan
    int evaluateHand(const std::vector<Card>& playedCards);
};