#pragma once
#include <string>

// Enum untuk jenis kartu (Suit)
enum class Suit {
    Clubs,    // Keriting
    Diamonds, // Wajik
    Hearts,   // Hati
    Spades    // Sekop
};

// Enum untuk angka kartu (Rank) - Kita mulai dari 2
enum class Rank {
    Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King, Ace
};

class Card {
private:
    Rank rank;
    Suit suit;

public:
    // Constructor (Fungsi yang dipanggil pertama kali saat kartu dibuat)
    Card(Rank r, Suit s);

    // Getters (Read-only properties)
    Rank getRank() const;
    Suit getSuit() const;

    // Fungsi tambahan untuk mencetak nama kartu ke layar saat testing
    std::string toString() const;
};