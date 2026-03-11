#include "ScoringSystem.h"
#include <iostream>

int ScoringSystem::getCardValue(Rank rank) {
    int value = static_cast<int>(rank);
    if (value >= 11 && value <= 13) return 10; // Jack, Queen, King bernilai 10
    if (value == 14) return 11;                // Ace bernilai 11
    return value;                              // Angka 2-10 bernilai angkanya sendiri
}

int ScoringSystem::evaluateHand(const std::vector<Card>& playedCards) {
    if (playedCards.empty()) return 0;

    int totalCardChips = 0;
    for (const auto& card : playedCards) {
        totalCardChips += getCardValue(card.getRank());
    }

    IScoringStrategy* strategy = nullptr;

    // Deteksi Flush (Semua suit sama)
    bool isFlush = true;
    Suit firstSuit = playedCards[0].getSuit();
    for (const auto& card : playedCards) {
        if (card.getSuit() != firstSuit) {
            isFlush = false; break;
        }
    }

    // Deteksi Pair (Ada 2 angka sama)
    bool isPair = false;
    for (size_t i = 0; i < playedCards.size(); ++i) {
        for (size_t j = i + 1; j < playedCards.size(); ++j) {
            if (playedCards[i].getRank() == playedCards[j].getRank()) {
                isPair = true; break;
            }
        }
    }

    // Pilih strategi berdasarkan deteksi (Prioritas dari kombinasi tersulit)
    if (isFlush && playedCards.size() >= 5) {
        strategy = new FlushStrategy();
    }
    else if (isPair) {
        strategy = new PairStrategy();
    }
    else {
        strategy = new HighCardStrategy();
    }

    // Terapkan Rumus
    int baseChips = 0;
    int multiplier = 0;
    strategy->applyScore(baseChips, multiplier);

    std::cout << "--> Kombinasi Terdeteksi: [" << strategy->getHandName() << "]\n";

    int finalScore = (baseChips + totalCardChips) * multiplier;
    std::cout << "--> Perhitungan: (" << baseChips << " Base Chips + " << totalCardChips << " Card Chips) x " << multiplier << " Mult\n";

    delete strategy; // Bersihkan memori
    return finalScore;
}