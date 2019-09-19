#include <iostream>
using namespace std;

int main(){
	int bestGrade = -1000;
	int bestStudent = 0;
	for (int i = 0; i < 5; ++i){
		int grade = 0;
		for (int j = 0; j < 4; ++j){
			int g;
			cin >> g;
			grade += g;
		}
		if (grade > bestGrade){
			bestGrade = grade;
			bestStudent = i + 1;
		}
	}

	cout << bestStudent << " " << bestGrade << endl;

	return 0;
}
