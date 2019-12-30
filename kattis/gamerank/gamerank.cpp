#include <bits/stdc++.h>
using namespace std;

int currRank = 25;
int currStars = 0;
int conseqWins = 0;

int get_stars(){
	if (currRank >= 21)	return 2;
	if (currRank >= 16)	return 3;
	if (currRank >= 11)	return 4;
	if (currRank >= 1)		return 5;
	assert(false);
}

void addStar(){
	if (currStars == get_stars()){
		--currRank;
		currStars = 0;
	}
	++currStars;
}

void addWin(){
	int curStarsWon= 1;
	++conseqWins;
	if (conseqWins >= 3 and currRank >= 6)
		curStarsWon++;

	for (int i = 0; i < curStarsWon; ++i){
		addStar();
	}
}

void loseStar(){
	if (currStars == 0){
		if (currRank == 20)	return;
		++currRank;
		currStars = get_stars();
	}
	--currStars;
}

void addLoss(){
	conseqWins = 0;
	if (currRank <= 20)	loseStar();
}

int main(){
	string seq;
	cin >> seq;
	for (char res : seq){
		assert(1 <= currRank and currRank <= 25);
		if (res == 'W')	addWin();
		else			addLoss();
		if (currRank == 0)	break;
	}

	if (currRank > 0){
		cout << currRank << endl;
	}
	else{
		cout << "Legend" << endl;
	}

	return 0;
}
