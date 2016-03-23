#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct DataRecord {
	int lineNumber;
	int value;
	bool operator==(const DataRecord&);
};

bool DRgreater(const DataRecord&, const DataRecord&);

int main() {
	vector<DataRecord> recordArray;
	vector<DataRecord>::iterator result;
	DataRecord goal = {24, 3}, tmp;
	ifstream fin("raw1.dat");
	int n, t;

	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> t;
		tmp.value = t; tmp.lineNumber = i;
		recordArray.push_back(tmp);
	}

	cout << "Raw Data: \n";
	for (int i = 0; i < recordArray.size(); i++)
		cout << "[" << recordArray[i].lineNumber << "] "
			<< recordArray[i].value << endl;

	sort(recordArray.begin(), recordArray.end(), DRgreater);

	cout << "Sorted Data: \n";
	for (int i = 0; i < recordArray.size(); i++)
		cout << "[" << recordArray[i].lineNumber << "] "
			<< recordArray[i].value << endl;

	result = find(recordArray.begin(), recordArray.end(), goal);

	if (result < recordArray.end())
		cout << "Find " << result->lineNumber
			<< ", " << result->value << endl;
	else cout << "Not found.\n";


	return 0;
}

bool DRgreater(const DataRecord &dr1, const DataRecord &dr2) {
	return dr1.value > dr2.value;
}

bool DataRecord::operator==(const DataRecord& y) {
	return (value == y.value && lineNumber == y.lineNumber);
}
