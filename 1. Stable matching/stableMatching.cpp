// Time complexity: O(N^2)
// Space complexity: O(N^2)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getPreferences(int numberOfMarriages){
	int index, value;
	vector<vector<int>> preferences(numberOfMarriages, vector<int>(numberOfMarriages, -1));

	for(int i = 0; i < numberOfMarriages; i++){
		vector<int> person(numberOfMarriages, -1);

		cin >> index;

		for(int j = 0; j < numberOfMarriages; j++){
			cin >> value;
			person[j] = value-1; // zero based
		}

		preferences[index-1] = person;
	}

	return preferences;
}

bool prefersARatherThanB(vector<vector<int>> womenPref, int woman, int manA, int manB){
	for(unsigned int i = 0; i < womenPref[0].size(); i++){
		if(womenPref[woman][i] == manA) return true;
		if(womenPref[woman][i] == manB) return false;
	}

	return false;
}

vector<int> stableMarry(vector<vector<int>> womenPref, vector<vector<int>> menPref){
	int freeManCount = (int)menPref.size();

	vector<bool> isManFree(menPref.size(), true);
	vector<int> womanIsMarriedTo(womenPref.size(), -1);

	while(freeManCount > 0){
		// Picking the first available man
		int man;
		for(man = 0; man < (int)menPref.size(); man++){
			if(isManFree[man] == true) break;
		}

		// Iterating through women according to the free man's preference
		for(int i = 0; i < (int)menPref.size() && isManFree[man] == true; i++){
			int woman = menPref[man][i];

			// She's not married
			if(womanIsMarriedTo[woman] == -1){
				womanIsMarriedTo[woman] = man;
				isManFree[man] = false;

				freeManCount--;
			}
			else{
				// Finding the current husband
				int curHusband = womanIsMarriedTo[woman];

				// If she prefers the new husband suitor, let's swap
				if(prefersARatherThanB(womenPref, woman, man, curHusband)){
					womanIsMarriedTo[woman] = man;

					isManFree[man] = false;
					isManFree[curHusband] = true;
				}
			}
		}
	}

	return womanIsMarriedTo;
}

int main(int argc, char* const argv[]){
	int testCases, numberOfMarriages;
	vector<int> marriages;
	vector<vector<int>> womenPref, menPref;

	cin >> testCases;

	for(int i = 0; i < testCases; i++){
		cin >> numberOfMarriages;

		womenPref = getPreferences(numberOfMarriages);
		menPref = getPreferences(numberOfMarriages);

		marriages = stableMarry(womenPref, menPref);

		vector<int> reverseMarriages = vector<int>(numberOfMarriages);
		for(unsigned int i = 0; i < marriages.size(); i++){
			reverseMarriages[marriages[i]] = i;
		}

		for(unsigned int man = 0; man < marriages.size(); man++){
			cout << man + 1 << " " << reverseMarriages[man] + 1 << endl;
		}
	}

	return 0;
}
