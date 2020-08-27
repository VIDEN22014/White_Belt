#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		// �������� ������ s � �����
		sorted_string.push_back(s);
		sort(sorted_string.begin(), sorted_string.end());
	}
	vector<string> GetSortedStrings() {
		// �������� ����� �� ���� ����������� ����� � ��������������� �������
		return sorted_string;
	}
private:
	// ��������� ����
	vector<string> sorted_string;
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	SortedStrings strings;
	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);
	strings.AddString("second");
	PrintSortedStrings(strings);
	return 0;
}