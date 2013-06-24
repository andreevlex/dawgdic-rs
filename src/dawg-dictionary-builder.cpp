#include <dawgdic/dictionary-builder.h>

using namespace dawgdic;

#define DAWG(x) ((Dawg*)x)
#define DICTIONARY(x) ((Dictionary*)x)

extern "C" {

#include "dawgdic/cdawgdic.h"

bool dawgdic_dictionary_builder_build(const void *dawg, const void *dictionary) {
    return DictionaryBuilder::Build(*DAWG(dawg), DICTIONARY(dictionary));
}

}
