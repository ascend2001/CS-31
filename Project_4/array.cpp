#include <iostream>
#include <string>
#include <cassert>
#include <cmath>;
using namespace std;

bool hasDuplicates(const string array[], int n);		//declaring all the functions at the beginning of the code so that I can call on any function in any order while defining them.
int countSs(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties);
bool isInDecreasingOrder(const string array[], int n);
bool matchingValuesTogether(const string array[], int n);
int divide(string array[], int n, string divider);
int locateMaximum(const string array[], int n) {
	string b = " ";
	string c = " ";
	int indexMax = n-1;
	if (n <= 0) {
		return(-1);
	}
	for (int i = n-1; i >-1; i--) {			//a backwards for-loop is used to traverse the elements of the array.
		b = array[i];
		c = array[indexMax];
		if (b >=c) {
			indexMax = i;				//only if a greater element is found will the indexMax variable switch to that position ensuring that once the array is completely traversed, the greatest element is returned.
		}
	}
	return(indexMax);
}

bool hasDuplicates(const string array[], int n) {
	string b = " ";
	string c = " ";
	int count = 0;
	bool result = false;
	if (n <= 0) {
		result = false;
	}
	else {
		for (int i = 0; i < n; i++) {				//the two for loops ensure that for every element, the inner loop runs throughout the entire list comparing it to all the remaining elements.
			b = array[i];
			for (int j = i+1; j < n; j++) {
				c = array[j];
				if (b == c) {
					result = true;
					break;
				}
			}
			if (result == true) {
				break;
			}
		}
	}
	return(result);
}

int countSs(const string array[], int n) {
	int count = 0;
	string b = " ";
	char c = ' ';
	for (int i = 0; i < n; i++) {
		b = array[i];
		for (size_t j = 0; j < b.length(); j++) {			// the inner for loop traverses every element of every element of the array to find an s or S character.
			c = b.at(j);
			if (c == 's' || c == 'S') {
				count++;
			}
		}
	}
	return(count);
}

int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties) {	
	int placeholdercounter = 0;
	if (amount > n) {							//to handle shifting greater than the number of elements in the list.
		placeholdercounter = n;
		for (int i = 0; i < n; i++) {
			array[i] = placeholderToFillEmpties;
		}
	}
	else if (n <= 0) {						//to handle incorrect inputs.
		placeholdercounter = 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			int k = i - amount;
			if (k < 0) {				//it counts the number of elements that have been removed from the list as that will always be equal to the spots taken over by the placeholder string.
				placeholdercounter++;
			}
			else {						//it swaps the places of the last few elements with those that are being removed due to shifting.
				array[k] = array[i];
			}
		}
		for (int a = 1; a <= placeholdercounter; a++) {		//it assigns the empty places with the value of the placeholder string.
			array[n - a] = placeholderToFillEmpties;
		}
	}
	
	return(placeholdercounter);
}

bool isInDecreasingOrder(const string array[], int n) {
	bool result = false;
	string b = " ";
	string c = " ";
	if (n <= 0) {					//to handle irregular inputs.
		result = false;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			b = array[i];
			c = array[i + 1];
			if (c > b) {					//this statement ensures the result is only false when the program conditions are violated which are that no subsequent element can be greater than the preceding one.
				result = false;
				break;
			}
			else {
				result = true;				//if no condition is violated, then the result is true.
			}
		}
	}
	return(result);
}

bool matchingValuesTogether(const string array[], int n) {
	string b = " ";
	string c = " ";
	bool result = false;
	if (n <= 0) {
		result = false;
	}
	if (hasDuplicates(array, n) == true) {			//this ensures that the function only checks the array if it has duplicates by running it through a previous function.
		for (int i = 0; i < n-1; i++) {
			b = array[i];
			c = array[i + 1];
			if (b == c) {
				result = true;
			}

		}
	}
	else {
		result = true;
	}
	return(result);
}

int divide(string array[], int n, string divider) { //also wtf is going on with this??
	string b = " ";
	string temp = " ";
	int result = 0;
	int smallies = 0;
	int biggies = 0;
	int count = 0;
	if (divider > array[locateMaximum(array, n)]) {			//to handle irregular inputs.
		result = 0;
	}
	else {
		while (count < n) {
			for (int i = 0; i < n; i++) {
				b = array[i];
				if (b <= divider&& i!=smallies) {		//smallies variable ensures that every element smaller than the divide are placed one after the other and not superpositioned.
					temp = array[0 + smallies];
					array[0 + smallies] = b;
					array[i] = temp;
					i -= 1;
					count++;
					smallies++;
				}
				else if (b <= divider && i==smallies) {		//this condition checks that if it is less than divide and placed right after the next element less than the divide, then it is left alone.
					count++;
					smallies++;
				}
				else {
					temp = array[n - 1-biggies];			//biggies variable ensures that every element greater than the divide are placed one after the other and not superpositioned
					array[n -1- biggies] = b;
					array[i] = temp;
					i -= 1;
					biggies++;
					count++;
				}
				if (count == n) {			//once all the elements of the list are checked it is broken out of the for loop.
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		b = array[i];
		if (b > divider) {
			result = i;
			break;
		}
	}

	return(result);
}


int main() {
	cout.setf(ios::boolalpha);
	string s = " ";
	int amount = 0;
	int n = 0;
	string divider = " ";
	string array[100];
	string array2[100];
	string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon" };
	string test0[4] = { "@","?",">","&" };
	string test1[3] = {"\r","\n"," "};
	string test2[4] = { " ","\a","		"," " };
	string alphanumeric[5] = { "3","?","E","E\n","E\n"};
	string test3[4] = { "		s","//sS","#\n","___S" };
	string increasing_decreasing[6] = { ""," ","#","5",")","." };
	string decreasing_increasing[6] = { "~","w","W",";","]","l" };
	string onlydecreasing[6] = { "}","x","Xavier","Howard","Hilton","+-+-+-+-+" };
	string onlyincreasing[6] = { "#%!@$@","#){})}","Welsh","zygote","}}}~}","~}{}{{}"};
	string alternatingincreasing_decreasing[5] = { "Xavier","Howard","zygote","Welsh","~{}{}~{}" };
	string matchingValuestogether[6] = { "@(#&^(@#","@(#&^(@#","OOWDGO","\n\a\r\t","		ye","___	" };
	string matchingValuesSeparate[6] = { "DEREKKKK","^)@&^#))@(*#^@)","SETEVN","DEREKKKK","DEREKKKKK" };
	string nomatchingvalues[6]= { "@FG*&R)","@FG*&R(","992030009764","9920300042400","<>,.<>,.","}{{}{{{}{}" };
	string equalDivider[4] = { "Estrogen","Slaphappy","donutholes","{}" };
	cout << "enter the size of an array" << endl;
	cin >> n;
	cin.ignore(INT_MAX, '\n');
	for (int j = 0; j < n; j++) {
		cout << "Please enter " << j << " element of the array\n";
		getline(cin, array[j]);
	}
	for (int j = 0; j < n; j++) {
		cout << "Please enter " << j << " element of the array\n";
		getline(cin, array2[j]);
	}
	cout << "enter the amount of shifting : " << endl;
	cin >> amount;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter a placeholder string : " << endl;
	getline(cin, s);
	cout << "Enter the divider string : " << endl;
	getline(cin, divider);
	cout << locateMaximum(array, n) << endl;
	cout << hasDuplicates(array, n) << endl;
	cout << countSs(array, n) << endl;
	cout << isInDecreasingOrder(array, n) << endl;
	cout << matchingValuesTogether(array, n) << endl;
	cout << divide(array, n, divider) << endl;
	for (int k = 0; k < n; k++) {
		cout << array[k] << endl;
 	}
	cout << shiftLeft(array2, n, amount, s) << endl;
	for (int k = 0; k < n; k++) {
		cout << array2[k] << endl;
	}
	assert(locateMaximum(folks,8) == 4);
	assert(hasDuplicates(folks, 8) == true);
	assert(hasDuplicates(folks, 5) == false);
	assert(countSs(folks, 5) == 2);
	assert(isInDecreasingOrder(folks, 8) == false);
	assert(isInDecreasingOrder(folks, 2) == true);
	assert(matchingValuesTogether(folks, 5) == true);
	assert(matchingValuesTogether(folks, 8) == false);
	assert(locateMaximum(test0, 4) == 0);
	assert(locateMaximum(test0, 0) == -1);
	assert(locateMaximum(test1, 3) == 2);
	assert(hasDuplicates(test0, 4) == false);
	assert(hasDuplicates(test0, 0) == false);
	assert(hasDuplicates(test1, 3) == false);
	assert(hasDuplicates(test0, 1) == false);
	assert(hasDuplicates(test2, 4) == true);
	assert(locateMaximum(test2, -1) == -1);
	assert(hasDuplicates(test2, -8) == false);
	assert(locateMaximum(alphanumeric, 5) == 3);
	assert(hasDuplicates(alphanumeric, 5) == true);
	assert(countSs(test0, 4) == 0);
	assert(countSs(test1, 3) == 0);
	assert(countSs(test3, 4) == 4);
	assert(isInDecreasingOrder(increasing_decreasing, 6) == false);
	assert(isInDecreasingOrder(decreasing_increasing, 5) == false);
	assert(isInDecreasingOrder(onlydecreasing, 6) == true);
	assert(isInDecreasingOrder(onlyincreasing, 6) == false);
	assert(isInDecreasingOrder(alternatingincreasing_decreasing, 5) == false);
	assert(matchingValuesTogether(matchingValuestogether, 6) == true);
	assert(matchingValuesTogether(nomatchingvalues, 6) == true);
	assert(matchingValuesTogether(matchingValuesSeparate, 5) == false);
	assert(divide(alternatingincreasing_decreasing, 5, "!!!!!") == 0);
	assert(divide(nomatchingvalues, 6, "~~~~~~~~~~") == 0);
	assert(divide(onlydecreasing, 6, "GOAT") == 1);
	assert(divide(equalDivider, 4, "donutholes") == 3);
	assert(divide(folks,8,"alphabet")==0 );
	assert(shiftLeft(test0, 4, 5, "lever") == 4);
	assert(shiftLeft(alphanumeric, 5, -1, "lever") == 0);
	assert(shiftLeft(folks, 5, 3, "foo") == 3);
	for (int k = 0; k < n; k++) {
		cout << folks[k] << endl;
	}
	return (0);
}
