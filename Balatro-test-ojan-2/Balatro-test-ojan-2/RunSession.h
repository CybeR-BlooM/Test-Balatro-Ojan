#pragma once
#include "DeckCard.h"
#include "ScoringSystem.h" // Tambahan baru untuk memanggil mesin penilai
#include <vector>

class RunSession {
private:
    DeckCard currentDeck;
    int currentRound;
    const int MAX_ROUNDS = 3; // Syarat minimum 3 ronde
    bool isRunActive;

    std::vector<Card> playerHand;  // Menyimpan kartu di tangan pemain
    std::vector<Card> playedCards; // Tambahan baru: Menyimpan kartu yang dipilih untuk dilempar ke meja
    ScoringSystem scorer;          // Tambahan baru: Mesin penilai kartu (Strategy Pattern)

    // 4 Fase Invariant yang tidak boleh diubah urutannya
    void playHandPhase();
    void computeScorePhase();
    void shopPhase();
    void nextRoundPhase();

public:
    RunSession();
    void startGameLoop();
};