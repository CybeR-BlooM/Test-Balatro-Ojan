#include "RunSession.h"
#include <iostream>

RunSession::RunSession() {
    currentRound = 1;
    isRunActive = true;
}

void RunSession::startGameLoop() {
    std::cout << "=================================\n";
    std::cout << "   MEMULAI BALATRO RUN (C++)     \n";
    std::cout << "=================================\n";

    currentDeck.shuffleDeck();

    // INVARIANT GAME LOOP: Terus berputar sampai 3 ronde
    while (isRunActive && currentRound <= MAX_ROUNDS) {
        std::cout << "\n--- RONDE " << currentRound << " ---\n";

        playHandPhase();
        computeScorePhase();
        shopPhase();
        nextRoundPhase();
    }

    std::cout << "\n=================================\n";
    std::cout << "          RUN SELESAI            \n";
    std::cout << "=================================\n";
}

void RunSession::playHandPhase() {
    std::cout << "[Fase 1] Membagikan 5 kartu ke pemain...\n";
    playerHand = currentDeck.draw(5); // Ambil 5 kartu dari deck

    std::cout << "Kartu di tangan:\n";
    for (const auto& card : playerHand) {
        std::cout << "  -> " << card.toString() << "\n";
    }
}

void RunSession::computeScorePhase() {
    // Ini akan kita kerjakan di Commit 2
    std::cout << "[Fase 2] Menghitung Skor... (Sistem Skor akan dibuat di commit selanjutnya)\n";
}

void RunSession::shopPhase() {
    // Ini akan kita kerjakan di Commit 5
    std::cout << "[Fase 3] Masuk ke Toko... (Sistem Toko belum tersedia)\n";
}

void RunSession::nextRoundPhase() {
    if (currentRound < MAX_ROUNDS) {
        std::cout << "[Fase 4] Persiapan Ronde Selanjutnya...\n";
    }
    currentRound++;
}