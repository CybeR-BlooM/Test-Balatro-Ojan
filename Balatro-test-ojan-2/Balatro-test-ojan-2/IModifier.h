#pragma once
#include <string>

// INTERFACE: Cetak biru untuk semua kartu sakti (Relic / Rune / Aura)
class IModifier {
public:
    // Virtual destructor wajib ada untuk class interface di C++ agar memori aman
    virtual ~IModifier() = default;

    // Fungsi wajib 1: Setiap kartu sakti harus punya nama
    virtual std::string getName() const = 0;

    // Fungsi wajib 2: Setiap kartu sakti harus bisa memanipulasi Skor.
    // Perhatikan tanda '&' (Reference). Ini berarti modifier akan mengubah
    // angka Chips dan Multiplier asli milik pemain secara langsung!
    virtual void applyEffect(int& currentChips, int& currentMultiplier) = 0;
};