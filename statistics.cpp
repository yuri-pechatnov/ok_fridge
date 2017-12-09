#include "statistics.h"

#include "fridge.h"

const static float FRIDGE_VOLUME = 100;


Statistics::Statistics(Fridge& fridge)
    : fridge(fridge)
{
}

integer Statistics::getFullness() {
    float usedVolume = 0;
    for (auto product : fridge.products) {
        usedVolume += product->amount;
    }
    return usedVolume / FRIDGE_VOLUME;
}
