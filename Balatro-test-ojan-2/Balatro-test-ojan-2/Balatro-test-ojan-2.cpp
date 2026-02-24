// Balatro-test-ojan-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Card.h" // Jangan lupa panggil header Card yang sudah kita buat

int main() {
    // 1. Kita coba buat satu kartu: As Sekop (Ace of Spades)
    Card myCard(Rank::Ace, Suit::Spades);

    // 2. Kita coba buat kartu lain: 8 Hati (Eight of Hearts)
    Card anotherCard(Rank::Eight, Suit::Hearts);

    // 3. Print ke layar untuk testing
    std::cout << "Kartu pertama saya: " << myCard.toString() << "\n";
    std::cout << "Kartu kedua saya: " << anotherCard.toString() << "\n";

    // Menahan layar console agar tidak langsung tertutup (khusus Windows)
    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
