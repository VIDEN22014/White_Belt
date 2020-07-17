#include <iostream>
#include	 <vector>
#include <string>
#include <map>

using namespace std;


int main() {

	int lineSize;
	cin >> lineSize;

	string pair1, pair2;
	map<char, int> pair1Map;
	map<char, int> pair2Map;

	for (int i = 0; i < lineSize; i++)
	{
		pair1Map.clear();
		pair2Map.clear();

		cin >> pair1 >> pair2;
		for (const auto& i : pair1)
		{
			pair1Map[i]++;
		}

		for (const auto& i : pair2)
		{
			pair2Map[i]++;
		}

		if (pair1Map == pair2Map) cout << "YES"<<endl;
		else cout << "NO"<<endl;
	}


	return 0;
}