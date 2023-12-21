#include <bits/stdc++.h>

using namespace std;

int main(void) { 		
	int N, C;
	
	int table[1001];
	
	table[0] = 1;
	
	int i = 1;
	// make a list;
	for (int a = 2; i < 1001; a++) {
		bool judge = true;
		for (int b = 2; b <= sqrt(a); b++) {
			if (a % b == 0) {
				judge = false;
				break;
			}
		}
		if (judge) {
			table[i] = a;
			i++;
		}
	}
	//bool temp = false;
	//cout << table[1000] << endl;
	//for ( int a = 0 ; a < 10; a++)cout << table[a] << " ";cout << endl;
	label:
	while (cin >> N >> C) {
		/*
		if (temp)
			cout << endl;
		temp = true;
		*/
		cout << N << " " << C << ":";
		
		int max = 1;
		
		for (int a = 0; 1; a++) {
			if (table[a] > N) {
				max = a;
				break;
			}else if (table[a] == N) {
				max = a +1 ;
				break;	
			}
		}
		
		//cout <<"max:"<<max << endl;
		
		
		if (max % 2 == 0) {
			if (max <= 2*C ) {
				for (int a = 0; 1; a++) {
					if (table[a] <= N) {
						cout << " " << table[a];	
					}else
						break;
				}
				cout << endl;
				cout << endl;
				goto label;
			}
			
			int numberofprintf = 2*C;
			
			int mid = max / 2;
			
			mid -= C;
			
			int c = mid;
			
			for (int a = 0; a < numberofprintf; a++) {
				
				cout << " "	 << table[c];
				c++;
			}
			
			cout << endl;
		}else {
			if (max <= 2*C-1 ) {
				for (int a = 0; 1; a++) {
					if (table[a] <= N) {
						cout << " " << table[a];	
					}else 
						break;
				}
				cout << endl;
				cout << endl;
				goto label;
			}
			
			int numberofprintf = 2*C - 1;
			
			int mid = max / 2;
			//cout << "max:" << max << endl;
			//cout << "mid:" << mid << endl;
			
			mid -= C;
			
			int c = mid+1;
			
			for (int a = 0; a < numberofprintf; a++) {
				cout << " " << table[c];
				c++;
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}
