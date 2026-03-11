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
    playedCards.clear();              // Bersihkan meja dari kartu ronde sebelumnya

    std::cout << "Kartu di tangan:\n";
    for (size_t i = 0; i < playerHand.size(); ++i) {
        // Menampilkan nomor [1] sampai [5] di depan kartu agar pemain bisa memilih
        std::cout << "  [" << i + 1 << "] " << playerHand[i].toString() << "\n";
    }

    // --- BAGIAN INTERAKTIF PEMILIHAN KARTU ---
    std::cout << "\nPilih kartu yang ingin dimainkan!\n";
    std::cout << "Ketik nomor kartu (pisahkan dengan spasi), lalu ketik 0 jika sudah selesai memilih.\n";
    std::cout << "Contoh ketik: 1 3 4 0 (Lalu tekan Enter)\n";
    std::cout << "Pilihanmu: ";

    int choice;
    // std::cin akan terus membaca angka yang diketik sampai kamu mengetik angka 0
    while (std::cin >> choice && choice != 0) {
        // Validasi agar pilihan tidak keluar dari batas kartu (1 sampai 5)
        if (choice > 0 && choice <= playerHand.size()) {
            playedCards.push_back(playerHand[choice - 1]);
        }
        else {
            std::cout << "Nomor " << choice << " tidak valid, diabaikan.\n";
        }
    }

    std::cout << "\nKamu memainkan " << playedCards.size() << " kartu ke meja.\n";
}

void RunSession::computeScorePhase() {
    std::cout << "[Fase 2] Menghitung Skor...\n";

    // Cek jika pemain tiba-tiba mengetik 0 tanpa memilih kartu apa pun
    if (playedCards.empty()) {
        std::cout << "Tidak ada kartu yang dimainkan. Skor: 0\n";
        return;
    }

    // Memanggil ScoringSystem untuk menilai kombinasi kartu di meja
    int score = scorer.evaluateHand(playedCards);
    std::cout << "============== SKOR RONDE INI: " << score << " ==============\n";
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