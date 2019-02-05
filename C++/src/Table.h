#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <string>

namespace map {

	template <typename V>
	struct item {
		std::string key;
		V value;
	};

	template <typename V>
	struct table {
		int size;
		int count;
		item<V>* items;
	};

	template <typename V>
	class Map {
	public:
		Map();

		~Map();
		/*
		V search(K k);

		void delete(K k);

		void insert(K k, V v);
		*/
	private:
		table<V>* _table;
		
		static table<V>* new_table();
		static item<V>* new_item(const std::string*, const V*);

		void del_table();

		static int hash(const std::string* s, const int a, const int m);
		static int get_hash(const std::string* s, const int num_buckets, const int attempt);
	};

}

#endif