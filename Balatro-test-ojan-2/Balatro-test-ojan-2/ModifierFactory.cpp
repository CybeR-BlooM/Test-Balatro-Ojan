#include "ModifierFactory.h"
#include "Relic.h"
#include <cstdlib> // Untuk fungsi rand()

IModifier* ModifierFactory::createRelic(int id) {
    // Pabrik akan mengecek ID, lalu membuatkan wujud fisiknya
    if (id == 1) {
        return new FlatBonusRelic();
    }
    else {
        return new MultiplierRelic(); // Default jika ID bukan 1
    }
}

IModifier* ModifierFactory::createRandomRelic() {
    // Menghasilkan angka acak antara 1 atau 2
    int randomId = (rand() % 2) + 1;
    return createRelic(randomId);
}