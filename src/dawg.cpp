#include <dawgdic/dawg.h>

using namespace dawgdic;

#define DAWG(x) ((Dawg*)x)

extern "C" {

#include "cdawgdic.h"

void *dawgdic_dawg_new() {
    return new Dawg();
}

void dawgdic_dawg_free(void *dawg) {
    delete DAWG(dawg);
}

void dawgdic_dawg_clear(const void *dawg) {
    DAWG(dawg)->Clear();
}

void dawgdic_dawg_swap(void *dawg1, void *dawg2) {
    DAWG(dawg1)->Swap(DAWG(dawg2));
}

unsigned int dawgdic_dawg_child(const void *dawg, unsigned int index) {
    return DAWG(dawg)->child(index);
}

unsigned int dawgdic_dawg_sibling(const void *dawg, unsigned int index) {
    return DAWG(dawg)->sibling(index);
}

int dawgdic_dawg_value(const void *dawg, unsigned int index) {
    return DAWG(dawg)->value(index);
}

bool dawgdic_dawg_is_leaf(const void *dawg, unsigned int index) {
    return DAWG(dawg)->is_leaf(index);
}

unsigned char dawgdic_dawg_label(const void *dawg, unsigned int index) {
    return DAWG(dawg)->label(index);
}

bool dawgdic_dawg_is_merging(const void *dawg, unsigned int index) {
    return DAWG(dawg)->is_merging(index);
}

size_t dawgdic_dawg_size(const void *dawg) {
    return DAWG(dawg)->size();
}

size_t dawgdic_dawg_num_of_transitions(const void *dawg) {
    return DAWG(dawg)->num_of_transitions();
}

size_t dawgdic_dawg_num_of_states(const void *dawg) {
    return DAWG(dawg)->num_of_states();
}

size_t dawgdic_dawg_num_of_merged_transitions(const void *dawg) {
    return DAWG(dawg)->num_of_merged_transitions();
}

size_t dawgdic_dawg_num_of_merged_states(const void *dawg) {
    return DAWG(dawg)->num_of_merged_states();
}

size_t dawgdic_dawg_num_of_merging_states(const void *dawg) {
    return DAWG(dawg)->num_of_merging_states();
}

}
