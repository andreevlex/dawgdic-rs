#include <dawgdic/dawg.h>

using namespace dawgdic;

#define DAWG(x) ((Dawg*)x)

extern "C" {

#include "dawgdic/cdawgdic.h"

void *dawgdic_dawg_new() {
    return new Dawg();
}

void dawgdic_dawg_free(void *dawg) {
    delete DAWG(dawg);
}

}
