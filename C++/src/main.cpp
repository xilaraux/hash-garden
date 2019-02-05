#include <iostream>
#include "Table.cpp"

using std::cout;
using std::cin;
using std::endl;

using std::string;

int hash(const std::string* s, const int a, const int m) {
	long hash = 0;
	const int len_s = s->length();

	for (int i = 0; i < len_s; i++) {
		hash += (long)std::pow(a, len_s - (i + 1)) * s->at(i);
		hash = hash % m;
	}

	return (int)hash;
}


int get_hash(const std::string* s, const int num_buckets, const int attempt) {
	const int hash_a = hash(s, 1, num_buckets);
	const int hash_b = hash(s, 2, num_buckets);

	return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

int main() {
	// map::Map<int>* m = new map::Map<int>();
	
	// delete m;

	string a = "hello";

	cout << a << '\t' << get_hash(&a, 10, 0) << endl;

	a = "not hello";

	cout << a << '\t' << get_hash(&a, 10, 0) << endl;

	a = "not hello1";

	cout << a << '\t' << get_hash(&a, 10, 0) << endl;

	char tmp;
	cin >> tmp;
	return 0;
}
