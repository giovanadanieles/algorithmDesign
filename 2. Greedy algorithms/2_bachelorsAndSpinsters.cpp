#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* const argv[]){
	int bachelors, spinsters, aux, youngest, caseNumber = 1;

	while(cin >> bachelors >> spinsters && bachelors != 0 && spinsters != 0){
		youngest = INT_MAX;

		for(int i = 0; i < bachelors; i++){
			cin >> aux;

			if(aux < youngest) youngest = aux; 
		}

		for(int i = 0; i < spinsters; i++) cin >> aux;

		cout << "Case " << caseNumber << ": ";
		if(bachelors <= spinsters) cout << 0 << endl;
		else cout << bachelors - spinsters << " " << youngest << endl;

		caseNumber++;
	}

	return 0;
}
