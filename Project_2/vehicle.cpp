#include <iostream>
#include <string>
using namespace std;
int main() {
	string model = "a"; // initializing and declaring the data types for the inputs
	string kind = "";
	string color = "";
	int wheel = 0;
	string leather = "";
	string autopilot = "";
	int x = 0;

	cout << "Which vehicle would you like to order?\n "; // creating the interface of the configurator
	cin >> model;										// by printing questions and asking for inputs.
	cin.ignore(INT_MAX, '\n');			//to ignore the newline esccape sequence left behind by >> so that getline can work
	cout << "Which kind would you like?\n ";
	getline(cin, kind);					//since Long Range is a possible input, the extraction operator cannot be used as it has more than one word.
	cout << "Which exterior color would you like?\n ";
	cin >> color;						//to account for any whitespace-polluted input.
	cin.ignore(INT_MAX, '\n');
	cout << "Which wheels would you like?\n ";
	cin >> wheel;
	cin.ignore(INT_MAX, '\n');
	cout << "Want leather interior?\n ";
	cin >> leather;
	cin.ignore(INT_MAX, '\n');
	cout << "Want Auto-Pilot?\n ";
	cin >> autopilot;
	cin.ignore(INT_MAX, '\n');

	if (model == "3") {						// using conditional if-else statements to create guarded action for the assignment of the
		if (kind == "Long Range") {			//appropriate prices to the variable x
			x = 47990;
		}
		else if (kind == "Performance") {
			x = 55990;
		}
		else {
			cout << "Error - Incorrect kind choice.\n";
			return(-1);								//to mark that the program failed when this choice is invoked.
		}
		if (color == "White") {							//using if-else statements to add the appropriate price to x based on the chosen color.
			x = x;
		}
		else if (color == "Black") {
			x += 500;
		}
		else if (color == "Blue" || color == "Grey") {
			x += 1000;
		}
		else if (color == "Red") {
			x += 1500;
		}
		else {
			cout << "Error - Incorrect color choice.\n";
			return (-2);								//to mark that the program failed when this choice is invoked.
		}
		switch (wheel) {					//switch statements are used to create conditional statements that take less space than if-else
		case 18:							//statements and can be used as color is of the integral data type. 
			x = x;
			break;
		case 19:
			x += 1500;
			break;
		default:
			cout << "Error - Incorrect wheel choice.\n";
			return(-3);					//to mark that the program failed when this choice is invoked.					
		}
		if (leather == "Yes") {			//to create conditional if-else statements to ensure an appropriate price is added based 
			x += 1000;					//on the leather input
		}
		else if (leather == "No") {
			x = x;
		}
		else {
			cout << "Error - Incorrect leather choice.\n";
			return(-4);					//to mark that the program failed when this choice is invoked.
		}
		if (autopilot == "Yes") {	//to create conditional if-else statements to ensure an appropriate price is added based on the
			x += 6000;				//autopilot input
		}
		else if (autopilot == "No") {
			x = x;
		}
		else {
			cout << "Error - Incorrect autopilot choice.\n";
			return(-5);				//to mark that the program failed when this choice is invoked.
		}
	}
	else if (model == "S") {			// using conditional if-else statements to create guarded action for the assignment of the
		if (kind == "Long Range") {		//appropriate prices to the variable x
			x = 79990;
		}
		else if (kind == "Performance") {
			x = 99990;
		}
		else {
			cout << "Error - Incorrect kind choice.\n";
			return(1);			//to mark that the program failed when this choice is invoked.
		}
		if (color == "White") {		//using if-else statements to add the appropriate price to x based on the chosen color
			x = x;
		}
		else if (color == "Black") {
			x += 1000;
		}
		else if (color == "Blue" || color == "Grey") {
			x += 1500;
		}
		else if (color == "Red") {
			x += 2500;
		}
		else {
			cout << "Error - Incorrect color choice.\n";
			return(2);		//to mark that the program failed when this choice is invoked.
		}
		switch (wheel) {	//switch statements are used to create conditional statements that take less space than if-else
		case 19:			//statements and can be used as color is of the integral data type.
			x = x;
			break;
		case 21:
			x += 4500;
			break;
		default:
			cout << "Error - Incorrect wheel choice.\n";
			return(3);		//to mark that the program failed when this choice is invoked.
		}
		if (leather == "Yes") {		//to create conditional if-else statements to ensure an appropriate price is added based
			x += 1000;				//on the leather input
		}
		else if (leather == "No") {
			x = x;
		}
		else {
			cout << "Error - Incorrect leather choice.\n";
			return(4);		//to mark that the program failed when this choice is invoked.
		}
		if (autopilot == "Yes") {		//to create conditional if-else statements to ensure an appropriate price is added based on the
			x += 6000;					//autopilot input
		}
		else if (autopilot == "No") {
			x = x;
		}
		else {
			cout << "Error - Incorrect autopilot choice.\n";
			return(5);		//to mark that the program failed when this choice is invoked.
		}
	}
	else if (model == "X") {			// using conditional if-else statements to create guarded action for the assignment of the
		if (kind == "Long Range") {		//appropriate prices to the variable x
			x = 84990;
		}
		else if (kind == "Performance") {
			x = 104990;
		}
		else {
			cout << "Error - Incorrect kind choice.\n";
			return(6);		//to mark that the program failed when this choice is invoked.
		}
		if (color == "White") {		//using if-else statements to add the appropriate price to x based on the chosen color
			x = x;
		}
		else if (color == "Black") {
			x += 1000;
		}
		else if (color == "Blue" || color == "Grey") {
			x += 1500;
		}
		else if (color == "Red") {
			x += 2500;
		}
		else {
			cout << "Error - Incorrect color choice.\n";
			return(-6);		//to mark that the program failed when this choice is invoked.
		}
		switch (wheel) {	//switch statements are used to create conditional statements that take less space than if-else
		case 20:			//statements and can be used as color is of the integral data type.
			x = x;
			break;
		case 22:
			x += 5500;
			break;
		default:
			cout << "Error - Incorrect wheel choice.\n";
			return(7);		//to mark that the program failed when this choice is invoked.
		}
		if (leather == "Yes") {		//to create conditional if-else statements to ensure an appropriate price is added based
			x += 1000;				//on the leather input
		}
		else if (leather == "No") {
			x = x;
		}
		else {
			cout << "Error - Incorrect leather choice.\n";
			return(-7);		//to mark that the program failed when this choice is invoked.
		}
		if (autopilot == "Yes") {		//to create conditional if-else statements to ensure an appropriate price is added based on the
			x += 6000;					//autopilot input
		}
		else if (autopilot == "No") {
			x = x;
		}
		else {
			cout << "Error - Incorrect autopilot choice.\n";
			return(8);		//to mark that the program failed when this choice is invoked.
		}
	}
	else {		// using conditional if-else statements to show the program what to do once an incorrect input is assigned.
		cout << "Error - Incorrect model choice.\n";
		return(-8);		//to mark that the program failed when this choice is invoked.
	}
	cout << "Enjoy your new $" << x << ".00 " << color << " Model " << model << "!" << endl;
	return (0);		//to mark that the program is completed when this line is reached.
}