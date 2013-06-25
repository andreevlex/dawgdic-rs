#include <dawgdic/dawg-builder.h>

using namespace dawgdic;

#define DAWG(x) ((Dawg*)x)
#define BUILDER(x) ((DawgBuilder*)x)

extern "C" {

#include "cdawgdic.h"

void *dawgdic_builder_new() {
    return new DawgBuilder();
}

void dawgdic_builder_free(void *builder) {
    delete BUILDER(builder);
}

bool dawgdic_builder_insert(const void *builder, const char *string) {
    return BUILDER(builder)->Insert(string);
}

bool dawgdic_builder_insert2(const void *builder, const char *string, const int record) {
    return BUILDER(builder)->Insert(string, record);
}

bool dawgdic_builder_insert3(const void *builder, const char *string, const size_t length, const int record) {
    return BUILDER(builder)->Insert(string, length, record);
}

bool dawgdic_builder_finish(const void *builder, const void *dawg) {
  return BUILDER(builder)->Finish(DAWG(dawg));
}

void dawgdic_builder_clear(const void *builder) {
    BUILDER(builder)->Clear();
}

size_t dawgdic_builder_size(const void *builder) {
    return BUILDER(builder)->size();
}

size_t dawgdic_builder_num_of_transitions(const void *builder) {
    return BUILDER(builder)->num_of_transitions();
}

size_t dawgdic_builder_num_of_states(const void *builder) {
    return BUILDER(builder)->num_of_states();
}

size_t dawgdic_builder_num_of_merged_transitions(const void *builder) {
    return BUILDER(builder)->num_of_merged_transitions();
}

size_t dawgdic_builder_num_of_merged_states(const void *builder) {
    return BUILDER(builder)->num_of_merged_states();
}

size_t dawgdic_builder_num_of_merging_states(const void *builder) {
    return BUILDER(builder)->num_of_merging_states();
}

}
