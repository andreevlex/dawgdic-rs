#include <dawgdic/dictionary.h>

#include <iostream>
#include <fstream>
#include <ios>

using namespace dawgdic;
using std::ios;
using std::ifstream;
using std::ofstream;

#define DICT(x) ((Dictionary*)x)

extern "C" {

#include "cdawgdic.h"

void *dawgdic_dictionary_new() {
    return new Dictionary();
}

void dawgdic_dictionary_free(void *dict) {
    delete DICT(dict);
}

void dawgdic_dictionary_clear(const void *dict) {
    DICT(dict)->Clear();
}

void dawgdic_dictionary_shrink(const void *dict) {
    DICT(dict)->Shrink();
}

void dawgdic_dictionary_swap(void *dict1, void *dict2) {
    DICT(dict1)->Swap(DICT(dict2));
}

bool dawgdic_dictionary_fread(const void *dict, const char *filename) {
    ifstream file;
    file.open(filename, ios::binary);
    if (!file.is_open()) return false;
    bool success = DICT(dict)->Read(&file);
    file.close();
    return success;
}

bool dawgdic_dictionary_fwrite(const void *dict, const char *filename) {
    ofstream file;
    file.open(filename, ios::binary);
    if (!file.is_open()) return false;
    bool success = DICT(dict)->Write(&file);
    file.close();
    return success;
}

bool dawgdic_dictionary_contains(const void *dict, const char *key) {
    return DICT(dict)->Contains(key);
}

bool dawgdic_dictionary_contains2(const void *dict, const char *key, const size_t length) {
    return DICT(dict)->Contains(key, length);
}

int dawgdic_dictionary_find(const void *dict, const char *key) {
    return DICT(dict)->Find(key);
}

int dawgdic_dictionary_find2(const void *dict, const char *key, const size_t length) {
    return DICT(dict)->Find(key, length);
}

bool dawgdic_dictionary_find3(const void *dict, const char *key, int *value) {
    return DICT(dict)->Find(key, value);
}

bool dawgdic_dictionary_find4(const void *dict, const char *key, const size_t length, int *value) {
    return DICT(dict)->Find(key, length, value);
}

bool dawgdic_dictionary_follow(const void *dict, const char label, unsigned int *index) {
    return DICT(dict)->Follow(label, index);
}

bool dawgdic_dictionary_follow2(const void *dict, const char *s, unsigned int *index) {
    return DICT(dict)->Follow(s, index);
}

bool dawgdic_dictionary_follow3(const void *dict, const char *s, unsigned int *index, size_t *count) {
    return DICT(dict)->Follow(s, index, count);
}

bool dawgdic_dictionary_follow4(const void *dict, const char *s, const size_t length, unsigned int *index) {
    return DICT(dict)->Follow(s, length, index);
}

bool dawgdic_dictionary_follow5(const void *dict, const char *s, const size_t length, unsigned int *index, size_t *count) {
    return DICT(dict)->Follow(s, length, index, count);
}

size_t dawgdic_dictionary_size(const void *dict) {
    return DICT(dict)->size();
}

size_t dawgdic_dictionary_total_size(const void *dict) {
    return DICT(dict)->total_size();
}

size_t dawgdic_dictionary_file_size(const void *dict) {
    return DICT(dict)->file_size();
}

}
