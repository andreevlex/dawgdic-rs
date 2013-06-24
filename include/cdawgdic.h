#ifndef DAWGDIC_CDAWGDIC_H
#define DAWGDIC_CDAWGDIC_H

/* dawg */
void *dawgdic_dawg_new();
void dawgdic_dawg_free(void *);

/* dawg-builder */
void *dawgdic_builder_new();
void dawgdic_builder_free(void *);
bool dawgdic_builder_insert(const void *, const char *);
bool dawgdic_builder_insert2(const void *, const char *, const int);
bool dawgdic_builder_insert3(const void *, const char *, const size_t, const int);
size_t dawgdic_builder_size(const void *);
bool dawgdic_builder_finish(const void *, const void *);
void dawgdic_builder_clear(const void *);

/* dictionary */
void *dawgdic_dictionary_new();
void dawgdic_dictionary_free(void *);
void dawgdic_dictionary_clear(const void *);
bool dawgdic_dictionary_fread(const void *, const char *);
bool dawgdic_dictionary_fwrite(const void *, const char *);
bool dawgdic_dictionary_contains(const void *, const char *);
int dawgdic_dictionary_find(const void *, const char *);
bool dawgdic_dictionary_follow(const void *, const char, unsigned int *);
bool dawgdic_dictionary_follow2(const void *, const char *, unsigned int *);
bool dawgdic_dictionary_follow3(const void *, const char *, unsigned int *, size_t *);
bool dawgdic_dictionary_follow4(const void *, const char *, const size_t, unsigned int *);
bool dawgdic_dictionary_follow5(const void *, const char *, const size_t, unsigned int *, size_t *);
size_t dawgdic_dictionary_size(const void *);
size_t dawgdic_dictionary_total_size(const void *);
size_t dawgdic_dictionary_file_size(const void *);

/* dictionary-builder */
bool dawgdic_dictionary_builder_build(const void *, const void *);

#endif // DAWGDIC_CDAWGDIC_H
