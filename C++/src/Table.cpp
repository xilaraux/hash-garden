#include <string>
#include <cmath>
#include "Table.h"

template <typename V>
map::Map<V>::Map() {
	_table = new_table();
}

template <typename V>
map::Map<V>::~Map() {
	del_table();
}

template <typename V>
map::item<V>* map::Map<V>::new_item(const std::string* k, const V* v) {
	map::item<V>* i = new map::item<V>;

	// Only POD types allowed
	memcpy(i->key, k, sizeof(k));
	memcpy(i->value, v, sizeof(v));

	return i;
}

template <typename V>
map::table<V>* map::Map<V>::new_table() {
	map::table<V>* t = new map::table<V>;

	t->size = 53;
	t->count = 0;
	t->items = new map::item<V>[t->size];

	return t;
}

template <typename V>
void map::Map<V>::del_table() {
	delete[] _table->items;
	delete _table;
}

template <typename V>
int map::Map<V>::hash(const std::string* s, const int a, const int m) {
	long hash = 0;
	const int len_s = strlen(s);

	for (int i = 0; i < len_s; i++) {
		hash += (long)std::pow(a, len_s - (i + 1)) * s[i];
		hash = hash % m;
	}

	return (int)hash;
}

template <typename V>
int map::Map<V>::get_hash(const std::string* s, const int num_buckets, const int attempt) {
	const int hash_a = hash(s, 1, num_buckets);
	const int hash_b = hash(s, 2, num_buckets);

	return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}
