#pragma once
#include "IModifier.h"

class ModifierFactory {
public:
    // Fungsi ini akan mencetak Relic berdasarkan ID yang diminta
    static IModifier* createRelic(int id);

    // Fungsi bantuan untuk mencetak Relic secara acak (berguna untuk Toko nanti)
    static IModifier* createRandomRelic();
};