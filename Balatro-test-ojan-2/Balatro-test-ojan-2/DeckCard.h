#pragma once
#include "Card.h"
#include <vector>

class DeckCard {
private:
    std::vector<Card> cards; // Tempat menyimpan tumpukan kartu

public:
    DeckCard(); // Constructor
    void shuffleDeck(); // Fungsi acak kartu
    std::vector<Card> draw(int count); // Fungsi ambil kartu
    int getRemainingCards() const; // Cek sisa kartu
};