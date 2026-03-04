#include "DeckCard.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

DeckCard::DeckCard() {
    // Mengisi deck dengan 52 kartu standar secara otomatis
    for (int s = static_cast<int>(Suit::Clubs); s <= static_cast<int>(Suit::Spades); ++s) {
        for (int r = static_cast<int>(Rank::Two); r <= static_cast<int>(Rank::Ace); ++r) {
            cards.push_back(Card(static_cast<Rank>(r), static_cast<Suit>(s)));
        }
    }
}

void DeckCard::shuffleDeck() {
    // Mengacak kartu menggunakan waktu komputer agar benar-benar acak
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    std::cout << "[SISTEM] Deck berhasil diacak (Berisi 52 Kartu).\n";
}

std::vector<Card> DeckCard::draw(int count) {
    std::vector<Card> drawnCards;
    for (int i = 0; i < count && !cards.empty(); ++i) {
        drawnCards.push_back(cards.back()); // Ambil kartu paling atas
        cards.pop_back();                   // Hapus kartu dari tumpukan
    }
    return drawnCards;
}

int DeckCard::getRemainingCards() const {
    return static_cast<int>(cards.size());
}