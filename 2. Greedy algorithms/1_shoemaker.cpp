#include <bits/stdc++.h>
using namespace std;

void findMinTotalFineJobSeq(vector<int> jobs, vector<int> fines){
	vector<pair<float, float>> cost(jobs.size());

	for(unsigned int i = 0; i < jobs.size(); i++){
		cost[i] = {(float)jobs[i] / (float)fines[i], i + 1};
	}

	sort(cost.begin(), cost.end());

	for(unsigned int i = 0; i < cost.size(); i++){
		i != cost.size() - 1 ? cout << cost[i].second << " " : cout << cost[i].second << endl;
	}
}

int main(int argc, char* const argv[]){
	int numTests, numJobs;
	string dummie;
	vector<int> jobs, fines, ans;

	cin >> numTests;

	for(int i = 0; i < numTests; i++){
		getline(cin, dummie);

		cin >> numJobs;

		vector<int> jobs(numJobs), fines(numJobs);

		for(int i = 0; i < numJobs; i++){
			cin >> jobs[i] >> fines[i];
		}

		findMinTotalFineJobSeq(jobs, fines);

		if(numTests > 1 && i != numTests - 1) cout << endl;
	}

	return 0;
}
