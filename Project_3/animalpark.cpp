#include <iostream>
#include <string>
#include <cassert>
using namespace std;
int kittensLeft(string animalparkString);	//declaring all the functions used in the program
int CATSLeft(string animalparkString);
int puppiesLeft(string animalparkString);
int DOGSLeft(string animalparkString);
int adultsLeft(string animalparkString);
int childrenLeft(string animalparkString);
int dogsLeft(string animalparkString);
int catsLeft(string animalparkString);
int peopleLeft(string animalparkString);
bool isValidAnimalParkString(string animalparkString) {
	bool result = false;	
	char b = 'a';
	char c = 'b';
	char f = 'c';
	const char e = animalparkString.at(0);
	const char end = animalparkString.at(animalparkString.size() - 1);
	for (size_t a = 1; a < (animalparkString.size() - 1); a++) {
		b = animalparkString.at(a);
		f = animalparkString.at(a - 1);
		c = animalparkString.at(a + 1);
		switch (f) {	//the switch case checks if there are any undesirable characters present in the animalparkString
		case 'c':		// and returns true if there are no present.
		case 'C':
		case 'd':
		case 'D':
		case 'p':
		case 'P':
		case '-':
		case '+':
			result = true;
			break;
		case ' ':
			result = false;
			break;
		default:
			result = false;
		}
		if (result == true) {
			if (b == '+' || b == '-') {			//to ensure that every pet is followed by their owner in the string.
				if (f != 'p' && f != 'P') {		//and that every segment ends with an adult or child entering or leaving the park.
					result = false;
				}
			}
			if ((b == 'p' || b == 'P')&&(c=='d'||c=='D'||c=='c'||c=='C')) {	//this ensures that a pet is always followed by its owner.
				result = false;												
			}
			if ((b == '+' || b == '-') && (c == 'p' || c == 'P')) {	//this ensures that a person cannot leave or enter without having a pet with them.
				result = false;
			}
			if (b == 'd' || b == 'D') {			//this if else-if statement ensures that the dogs and cats are not entering or leaving together.
				if (f == 'c' || c == 'c' || c == 'C' || f == 'C') {
					result = false;
				}
			}
			else if (b == 'c' || b == 'C') {
				if (f == 'd' || c == 'd' || f == 'D' || c == 'D') {
					result = false;
				}
			}
			
			
		}
		if (result == false) {
			break;
		}
	}
	if (adultsLeft(animalparkString)<0||childrenLeft(animalparkString)<0||kittensLeft(animalparkString) < 0 || CATSLeft(animalparkString) < 0 || puppiesLeft(animalparkString) < 0 || DOGSLeft(animalparkString) < 0) {
		result = false;				// this if-statement ensures that a pet cannot leave before it has entered.
	}
	if (animalparkString.size() == 1) {	//this if-statement ensures that a pet or owner cannot enter the park alone without either.
		result = false;
	}
	if (e !='D' && e != 'd' && e != 'C' && e != 'c' || (end != 'p' && end != 'P')) { //this ensures that the string always begins with pets
		result = false;																//and the string ends with owners only.
	}
	return(result);
}

int kittensLeft(string animalparkString) {	//the helper function counts the number of kittens are left behind in the park after the string is over.
	int kittensentering = 0;
	int kittensleaving = 0;
	string b = "";
	for (size_t a = 0; a < animalparkString.size(); a++) {	//for-loop walks over string.
		b = animalparkString.at(a);
		while (b != "+" && b != "-") {		//counts kittens in the first segment of the animalparkstring.
			if (b == "c") {
				kittensentering++;
			}
			else {
				break;
			}
			a++;
			b = animalparkString.at(a);
		}
		if (b == "+") {
			while (b != "-" && a < (animalparkString.size() - 1)) {		//counts the number of kittens entering in the animalparkstring after every + char till the next - char.
				a++;
				b = animalparkString.at(a);
				if (b == "c") {
					kittensentering++;
				}
				else if (b == "-") {
					break;
				}
				else {
					continue;
				}
			}
		}
		if (b == "-") {
			while (b != "+" && (a < animalparkString.size() - 1)) {		//counts the number of kittens leaving in the animalparkstring after every - char till the next + char.
				a++;
				b = animalparkString.at(a);
				if (b == "c") {
					kittensleaving++;
				}
				else if (b == "+") {
					break;
				}
				else {
					continue;
				}
			}
		}
	}
		int kittensleft = kittensentering - kittensleaving;			//evaluates the number of ittens left behind in the park after the string is over.
		return (kittensleft);
}

int CATSLeft(string animalparkString) {		//the helper function counts the number of adult cats are left behind in the park after the string is over.
	int CATSentering = 0;
	int CATSleaving = 0;
	string b = "";
	for (size_t a = 0; a < animalparkString.size(); a++) {
		b = animalparkString.at(a);
		while (b != "+" && b != "-") {		//counts adult cats entering in the first segment of the string before the first + or - char.
			if ( b == "C") {
				CATSentering++;
			}
			else {
				break;
			}
			a++;
			b = animalparkString.at(a);
		}
		if (b == "+") {
			while (b != "-" && a < (animalparkString.size() - 1)) {	//counts the number of adult cats entering after every + char till the next - char.
				a++;
				b = animalparkString.at(a);
				if (b == "C") {
					CATSentering++;
				}
				else if (b == "-") {
					break;
				}
				else {
					continue;
				}
			}
		}
		if (b == "-") {
			while (b != "+" && (a < animalparkString.size() - 1)) {	//counts the number of adult cats leaving ater every - char till the next + char.
				a++;
				b = animalparkString.at(a);
				if (b == "C") {
					CATSleaving++;
				}
				else if (b == "+") {
					break;
				}
				else {
					continue;
				}
			}
		}
	}
		int CATSleft = CATSentering - CATSleaving;		//evaluates the number of adult cats left behind in the park after the animal string is over.
		return (CATSleft);
}


int catsLeft(string animalparkString) {	//evaluates the total number of cats left behind in the par after the string is over.
	if (isValidAnimalParkString(animalparkString) == true) {	//performs the function only if the animalparkstring passed is correct and follows all rules.
		int catsLeft = 0;
		catsLeft = kittensLeft(animalparkString) + CATSLeft(animalparkString);
		return (catsLeft);
	}
	else {
		return(-1);
	}
}

int puppiesLeft(string animalparkString) {	//the helper function counts the number of puppies are left behind in the park after the string is over.
	int puppiesentering = 0;
	int puppiesleaving = 0;
	string b = "";
	for (size_t a = 0; a < animalparkString.size(); a++) {	//for-loop walks over animalparkstring.
		b = animalparkString.at(a);
		while (b != "+" && b != "-") {		//counts number of puppies entering the park before the fist + or - char in the animalparkstring.
			if (b == "d") {
				puppiesentering++;
			}
			else {
				break;
			}
			a++;
			b = animalparkString.at(a);
		}
		if (b == "+") {		//counts number of puppies entering the park after every + char till every - char.
			while (b != "-" && a < (animalparkString.size() - 1)) {
				a++;
				b = animalparkString.at(a);
				if (b == "d") {
					puppiesentering++;
				}
				else if (b == "-") {
					break;
				}
				else {
					continue;
				}
			}
		}
		if (b == "-") {		//counts number of puppies leaving the park after every - char till every + char.
			while (b != "+" && a < (animalparkString.size() - 1)) {
				a++;
				b = animalparkString.at(a);
				if (b == "d") {
					puppiesleaving++;
				}
				else if (b == "+") {
					break;
				}
				else {
					continue;
				}
			}
		}
	}
		int puppiesleft = puppiesentering - puppiesleaving;		//evaluates the number of puppies left behind in the park after the animalparkstring is over.
		return (puppiesleft);
	
}

int DOGSLeft(string animalparkString) {	//the helper function counts the number of adult dogs are left behind in the park after the string is over.
	int DOGSentering = 0;
	int DOGSleaving = 0;
	string b = "";
	for (size_t a = 0; a < animalparkString.size(); a++) {	//for-loop walks over animalparkstring
		b = animalparkString.at(a);
		while (b != "+" && b != "-") {	//counts number of adult dogs entering the park before the fist + or - char in the animalparkstring.
			if (b == "D") {
				DOGSentering++;
			}
			else {
				break;
			}
			a++;
			b = animalparkString.at(a);
		}
		if (b == "+") {		//counts number of adult dogs entering the park after every + char till every - char.
			while (b != "-" && a < (animalparkString.size() - 1)) {
				a++;
				b = animalparkString.at(a);
				if (b == "D") {
					DOGSentering++;
				}
				else if (b == "-") {
					break;
				}
				else {
					continue;
				}
			}
		}
		if (b == "-") {		//counts number of adult dogs leaving the park after every - char till every + char.
			while (b != "+" && a < (animalparkString.size() - 1)) {
				a++;
				b = animalparkString.at(a);
				if (b == "D") {
					DOGSleaving++;
				}
				else if (b == "+") {
					break;
				}
				else {
					continue;
				}
			}
		}
	}
	int DOGSleft = DOGSentering - DOGSleaving;
	return (DOGSleft);
}


int dogsLeft(string animalparkString) {	//evaluates the total number of cats left behind in the par after the string is over.
	if(isValidAnimalParkString(animalparkString)==true){		//performs the function only if the animalparkstring passed is correct and follows all rules.
		int dogsLeft = puppiesLeft(animalparkString) + DOGSLeft(animalparkString);
		return(dogsLeft);
	}
	else {
		return(-1);
	}
}
int childrenLeft(string animalparkString) {	//the helper function counts the number of children are left behind in the park after the string is over.
	int childrenentering = 0;
	int childrenleaving = 0;
	char b = ' ';
	for (size_t a = 0; a < animalparkString.size(); a++) {
		b = animalparkString.at(a);
		if (a == 0) {
			while (b != '+' && b != '-' && (a < animalparkString.size() - 1)) {	//counts number of children entering the park before the fist + or - char in the animalparkstring.
				a++;
				b = animalparkString.at(a);
				if (b == 'p') {
					childrenentering++;
					continue;
				}
				else if (b == '+' || b == '-') {
					break;
				}
				else {
					continue;
				}
				a++;
				b = animalparkString.at(a);
			}
		}
		if (b == 'p') {	//counts children when the string has a segment begins with - and ends with + as the for loop increments a by 1 and so the program misses the + char.
			while (b != '-' && (a < animalparkString.size())) {
				childrenentering++;
				if (a < animalparkString.size() - 1) {
					a++;
					b = animalparkString.at(a);
					continue;
				}
				else {
					break;
				}
			}
		}
		if (b == '+') {		//counts number of children entering the park after every + char till every - char.
			while (b != '-' && (a < animalparkString.size() - 1)) {	
				a++;
				b = animalparkString.at(a);
				if (b == 'p') {
					childrenentering++;
				}
				else if (b == '-') {
					break;
				}
				else {
					continue;
				}
			}
		}
		if (b == '-') {	//counts number of children leaving the park after every - char till every + char.
			while (b != '+' && (a < animalparkString.size() - 1)) {
				a++;
				b = animalparkString.at(a);
				if (b == 'p') {
					childrenleaving++;
					continue;
				}
				else if (b == '+') {
					break;
				}
				else {
					continue;
				}
			}
		}
	}
		int childrenleft = childrenentering - childrenleaving;
		return (childrenleft);
}

int adultsLeft(string animalparkString) {	//the helper function counts the number of adult are left behind in the park after the string is over.
	int adultsentering = 0;
	int adultsleaving = 0;
	char b = ' ';
	for (size_t a = 0; a < animalparkString.size(); a++) {
		b = animalparkString.at(a);
		if (a == 0) {
			while (b != '+' && b != '-' && (a < animalparkString.size() - 1)) {	//counts number of adults entering the park before the fist + or - char in the animalparkstring.
				a++;
				b = animalparkString.at(a);
				if (b == 'P') {	//counts children when the string has a segment begins with - and ends with + as the for loop increments a by 1 and so the program misses the + char.
					adultsentering++;
					continue;
				}
				else if (b == '+' || b == '-') {
					break;
				}
				else {
					continue;
				}
				a++;
				b = animalparkString.at(a);
			}
		}
		if (b == 'P') {
			while (b != '-' && (a < animalparkString.size())) {
				adultsentering++;
				if (a < animalparkString.size() - 1) {
					a++;
					b = animalparkString.at(a);
					continue;
				}
				else {
					break;
				}
			}
		}
		if (b == '+') {		//counts number of adults entering the park after every + char till every - char.
			while (b != '-' && (a < animalparkString.size() - 1)) {
				a++;
				b = animalparkString.at(a);
				if (b == 'P') {
					adultsentering++;
				}
				else if (b == '-') {
					break;
				}
				else {
					continue;
				}
			}
		}
		if (b == '-') {		//counts number of adults leaving the park after every - char till every + char.
			while (b != '+' && (a < animalparkString.size() - 1)) {
				a++;
				b = animalparkString.at(a);
				if (b == 'P') {
					adultsleaving++;
					continue;
				}
				else if (b == '+') {
					break;
				}
				else {
					continue;
				}
			}
		}
	}
		int adultsleft = adultsentering - adultsleaving;
		return (adultsleft);
}

int peopleLeft(string animalparkString) { //evaluates the total number of people left behind in the par after the string is over.
	if(isValidAnimalParkString(animalparkString)==true){	//performs the function only if the animalparkstring passed is correct and follows all rules.
		int pepsLeft = childrenLeft(animalparkString) + adultsLeft(animalparkString);
		return(pepsLeft);
	}
	else {
		return(-1);
	}
}
int main() {
	cout.setf(ios::boolalpha);
	string animalparkString = "";
	cout << "enter an animal park string :  \n";
	cin >> animalparkString;
	if (isValidAnimalParkString(animalparkString) == true) {
		cout << "The given animal string is " << isValidAnimalParkString(animalparkString) << endl;
		cout << "The number of cats left in the park: " << catsLeft(animalparkString) << endl;
		cout << "The number of dogs left in the park : " << dogsLeft(animalparkString) << endl;
		cout << "The number of people left in the park : " << peopleLeft(animalparkString) << endl;
	}
	else {
		cout << "The given animal string is " << isValidAnimalParkString(animalparkString) << endl;
		cout << "cats" << catsLeft(animalparkString) << endl;
		cout << "dogs" << dogsLeft(animalparkString) << endl;
		cout << "people" << peopleLeft(animalparkString) << endl;
			return(-1);
	}
	assert(isValidAnimalParkString("DP+CP+cp+dp-Dp-Cp-dP-cP") == true);
	assert(isValidAnimalParkString("asdf1ABC000:2-55 ") == false);
	assert(isValidAnimalParkString("+dp+cp") == false);
	assert(isValidAnimalParkString("-dp+dp") == false);
	assert(isValidAnimalParkString("ddDP+ccCP-") == false);
	assert(isValidAnimalParkString("ddDP+cccP+") == false);
	assert(isValidAnimalParkString("cCcDP") == false);
	assert(isValidAnimalParkString("dddddPcccccP") == false);
	assert(isValidAnimalParkString("cp+P-cpP") == false);
	assert(isValidAnimalParkString("cpP-P") == false);
	assert(isValidAnimalParkString("cP+dP-cdPP") == false);
	assert(isValidAnimalParkString("DP + CP + cp + dp - Dp - Cp - dP - cP") == false);
	assert(isValidAnimalParkString("dp-CP") == false);

	return(0);
}