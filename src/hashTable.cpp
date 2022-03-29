#include <iostream>
#include <list>
#include <cstring>

using namespace std;

// Hashtable to implement 905, Jimmy

class HashTable {
	private:
		static const int hashGroups = 10;
		list<pair<int,string>> table[hashGroups]; //List 1, index 0, Index 1...

	public:
		bool isEmpty() const;
		int hashFunction(int key);
		void insertItem(int key, string value);
		void removeItem(int key);
		string searchTable(int key);
		void printTable();

};

bool HashTable::isEmpty() const {
	int sum{};
	for (int i{}; i<hashGroups: i++){
		sum+=table[i].size();
	}
	if (!sum) {
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key) {
	return key % hashGroups; //Key: 905. in return, this function will spit out 5.
}

void HashTable::insertItem(int key string value){
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for(;bItr != end(cell); bItr++){
		if(bItr -> first == key){
			keyExists = true
			bItr -> second = value;
			cout << "[WARNING] Key exist. Value replaced." << endl;
			break;
		}
	}
	if (!keyExists) {
		cell.emplace_back(key, value);
	}
	return;
}

void HashTable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for(; bItr!=end(cell); bItr++) {
		if (bItr ->first==key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] Pai removed." << endl;
			break;
		}
	}

	if (!keyExists){
		cout << "[WARNING] Key not found. Pair not removed." << endl;
	}
	return;
}

void HashTable::printTable() {
	for (int i{}; i<hashGroups; i++){
		if(table[i].size()==0) continue; 

		auto bItr = table[i].begin();
		for(;bItr != table[i].end(); bItr++){
			cout << "[INFO] Key: " << bItr->first << "Value: " << bItr->second << endl;
		} 
	}
	return;
}

int main() {
	HashTable HT;

	if(HT.isEmpty()){
		cout << "Correct asnwer. Good job." << endl;
	} else {
		cout << "Oh oh. We need to check out code!" << endl;
	}

	HT.insertItem(905, "Jimmy");
	HT.insertItem(112, "Kim");
	HT.insertItem(43, "Leo");
	HT.insertItem(12, "Mario");
	HT.insertItem(408, "Dan");
	HT.insertItem(23, "Felix");
	HT.insertItem(723, "George");
	HT.insertItem(723, "Bruce");

	HT.printTable();

	HT.removeItem(43);
	HT.removeItem(211);

	if (HT.isEmpty()){
		cout << "Oh oh. We need to check out code!" << endl;
	}else {
		cout << "Correct asnwer! Good job!" << endl;
	}

	return 0;
}
