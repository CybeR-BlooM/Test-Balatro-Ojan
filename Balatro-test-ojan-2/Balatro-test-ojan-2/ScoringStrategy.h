#pragma once
#include "Card.h"
#include <string>

// INTERFACE: Aturan baku untuk semua rumus skor
class IScoringStrategy {
public:
    virtual ~IScoringStrategy() = default;

    // Fungsi ini wajib ada di setiap rumus kombinasi
    virtual void applyScore(int& baseChips, int& multiplier) = 0;
    virtual std::string getHandName() const = 0;
};

// STRATEGI 1: High Card (Kartu Acak biasa)
class HighCardStrategy : public IScoringStrategy {
public:
    void applyScore(int& baseChips, int& multiplier) override;
    std::string getHandName() const override;
};

// STRATEGI 2: Pair (Dua kartu dengan angka sama)
class PairStrategy : public IScoringStrategy {
public:
    void applyScore(int& baseChips, int& multiplier) override;
    std::string getHandName() const override;
};

// STRATEGI 3: Flush (Semua kartu memiliki simbol/suit yang sama)
class FlushStrategy : public IScoringStrategy {
public:
    void applyScore(int& baseChips, int& multiplier) override;
    std::string getHandName() const override;
};