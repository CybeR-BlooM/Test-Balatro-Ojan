#include "Card.h"

// Implementasi Constructor
Card::Card(Rank r, Suit s) {
    rank = r;
    suit = s;
}

// Implementasi Getters
Rank Card::getRank() const {
    return rank;
}

Suit Card::getSuit() const {
    return suit;
}

// Implementasi toString untuk mempermudah kita melihat hasil di Console
std::string Card::toString() const {
    std::string rankStr;
    std::string suitStr;

    // Menentukan string untuk Rank
    switch (rank) {
    case Rank::Jack:  rankStr = "Jack"; break;
    case Rank::Queen: rankStr = "Queen"; break;
    case Rank::King:  rankStr = "King"; break;
    case Rank::Ace:   rankStr = "Ace"; break;
    default:          rankStr = std::to_string(static_cast<int>(rank)); break;
    }

    // Menentukan string untuk Suit
    switch (suit) {
    case Suit::Clubs:    suitStr = "Clubs"; break;
    case Suit::Diamonds: suitStr = "Diamonds"; break;
    case Suit::Hearts:   suitStr = "Hearts"; break;
    case Suit::Spades:   suitStr = "Spades"; break;
    }

    return rankStr + " of " + suitStr; // Contoh hasil: "Ace of Spades"
}