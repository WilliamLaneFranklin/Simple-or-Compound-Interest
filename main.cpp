#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


//function prototypes
void welcomeStatement();
void displayChoices();
int readOption();
double getDataInput();
int getCompoundingPeriod();
double executeOption(int userChoice, double principalAmount, double interestRate, double timeYears);
void displayTotals(double principalAmount, double interestAccrued);
void endingMessage();


int main(){
	welcomeStatement();

	cout << fixed << setprecision(2);

	int userChoice = 0;
	double principalAmount = 0.00;
	double interestRate = 0.00;
	double timeYears = 0.00;
	double interestAccrued = 0.00;

	do{
		displayChoices();
		userChoice = readOption();
		if (userChoice == 1 || userChoice == 2){
		cout << "Enter a principal amount: ";
		principalAmount = getDataInput();
		cout << "Enter an interest rate: ";
		interestRate = getDataInput() / 100;
		cout << "Enter the time in years: ";
		timeYears = getDataInput();
		interestAccrued = executeOption(userChoice, principalAmount, interestRate, timeYears);	
		displayTotals(principalAmount, interestAccrued);
		}
	}while (userChoice != 3);
	endingMessage();
	return 0;
}


void welcomeStatement(){
	cout << '\n' << "Welcome to my Interest Calculation program!" << endl;
}


void displayChoices(){
	cout << '\n' << "What would you like to do today?" << endl;
	cout << "Pick an option from below." << endl;
	cout << "1. Simple Interest" << endl;
	cout << "2. Compound Interest" << endl;
	cout << "3. Quit" << endl;
}


int readOption(){
	int userChoice = 0;
	cin >> userChoice;
	while (userChoice < 1 || userChoice > 3){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid option! Please choose 1-3" <<  endl;
		cin >> userChoice;
	}
	return userChoice;
}


double getDataInput(){
	double dataInput = 0.00;
	cin >> dataInput;
	while (!cin || dataInput < 0.00){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input! Please try again: " << endl;
		cin >> dataInput;
	}
	return dataInput;
}


int getCompoundingPeriod(){
	int compoundingPeriod = 0;
	cout << "Enter the number of compounding period: ";
	cin >> compoundingPeriod;
	while (!cin || compoundingPeriod < 0){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid number of compounding period: " << endl;
		cin >> compoundingPeriod;
	}
	return compoundingPeriod;
}


double executeOption(int userChoice, double principalAmount, double interestRate, double timeYears){
	double interestAccrued = 0.00;
	double compoundingPeriod = 0.00;
	if (userChoice == 2){
		compoundingPeriod = getCompoundingPeriod();
		interestAccrued = (principalAmount * pow((1 + interestRate/compoundingPeriod), (compoundingPeriod * timeYears))) - principalAmount;
	}
	else{
		interestAccrued = (principalAmount * interestRate * timeYears);
	}
	return interestAccrued;
}


void displayTotals(double principalAmount, double interestAccrued){
	cout << '\n' << "Interest accrued: $" << interestAccrued << endl;
	cout << "Total Accrued Amount (principal + interest): $" << principalAmount + interestAccrued << endl;
}


void endingMessage(){
	cout << "Thank you for using my program!" << endl;
}
