/*
============================================================================
Name        : Karl Schaller
Date        : 09/13/2019
Course      : CIS2107 Comp Sys & Low-Level Program
Homework    : Lab 03 ATM Machine
Problem     : Write a program for an ATM machine (balance, withdrawal, deposition, quit)
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

void balance();
void withdraw();
void deposit();
void quit();
void receipt();

int accountBalance;
unsigned int totalWithdraws;
unsigned int totalDeposits;
unsigned int numTransactions;

int main(void) {

	int input;
	unsigned int attempts;

	totalWithdraws = 0;
	totalDeposits = 0;
	numTransactions = 0;

	//============================================================================
	// LOG ON WITH PIN
	//============================================================================
	puts("Welcome to the CIS2107 ATM!\n");
	printf("%s", "Please enter your 4-digit PIN: ");
	scanf("%d", &input);
	attempts = 1;
	while(input != 3014) {
		if (attempts == 3) // program shuts down after 3 attempts
					exit(0);
		printf("%s%d%s", "Incorrect PIN. Please enter your 4-digit PIN (you have ",
				3-attempts, " attempts remaining): "); // ask for PIN and display remaining attempts
		scanf("%d", &input);
		attempts++;
	}
	accountBalance = 5000; // Nana has a balance of $5000

	//============================================================================
	// CHOOSE TRANSACTION
	//============================================================================
	puts("\n\nWelcome Nana.\n");
	while (1) {
		puts("The types of ATM transactions are:");
		puts("\t1.  Balance");
		puts("\t2.  Cash withdrawal");
		puts("\t3.  Cash deposition");
		puts("\t4.  Quit\n");
		printf("%s", "Which transaction would you like: ");
		scanf("%d", &input);
		switch (input) {
			case 1: balance();
				break;
			case 2: withdraw();
				break;
			case 3: deposit();
				break;
			case 4: quit();
				break;
			default: puts("\nPlease enter a valid number.");
		}
	}

}

void balance() {
	printf("%s%d%s", "\nYour balance is: $", accountBalance, ".00");
	numTransactions++;
	receipt();
}

void withdraw() {
	float input;
	input = 0;

	if (totalWithdraws >= 1000) // check withdraw limit
		puts("\nYou have already withdrawn the daily limit of $1000!");
	else if (accountBalance == 0) // check account balance
		puts("\nThere is no money in the account left to withdraw!");
	else {
		while (input <= 0 || (((int)(input*100))%2000) != 0 || (input+totalWithdraws) >= 1000 || (accountBalance-input) < 0) {
			printf("%s", "\nHow much would you like to withdraw: $");
			scanf("%f", &input);

			// check for invalid inputs and withdraw limit
			if (input <= 0 )
				puts("Invalid withdraw amount");
			if ((((int)(input*100))%2000) != 0)
				puts("You can only withdraw in multiples of 20s (20, 40, 60, 80...)");
			if ((input+totalWithdraws) >= 1000) {
				puts("This value exceeds the daily withdraw limit of $1000!");
				printf("%s%d%s", "You have already withdrawn $", totalWithdraws, "\n");
			if ((accountBalance-input) < 0)
				puts("The account does not have that much money to withdraw!");
			}
		}
		// process withdraw
		accountBalance -= input;
		totalWithdraws += input;
		numTransactions++;
		puts("Withdrawing...");
		receipt();
	}
}

void deposit() {
	float input;
	input = 0;

	if (totalDeposits >= 10000) // check deposit limit
		puts("\nYou have already deposited the daily limit of $10000!");
	else {
		while (input <= 0 || (((int)(input*100))%100) != 0 || (input+totalDeposits) >= 10000) {
			printf("%s", "\nHow much would you like to deposit: $");
			scanf("%f", &input);

			// check for invalid inputs and deposit limit
			if (input <= 0 )
				puts("Invalid deposit amount");
			if ((((int)(input*100))%100) != 0)
				puts("You can only deposit paper bills (no change)");
			if ((input+totalDeposits) >= 10000) {
				puts("This value exceeds the daily deposit limit of $10000!");
				printf("%s%d", "You have already deposited $", totalDeposits);
			}
		}
		// process deposit
		accountBalance += input;
		totalDeposits += input;
		numTransactions++;
		puts("Depositing...");
		receipt();
	}
}

void quit() {
	printf("%s%d%s", "\nYou made a total of ", numTransactions, " transactions."); // display total transactions made
	puts("\nLogging off...");
	puts("Thank you for using the CIS2107 ATM!");
	exit(0);
}

void receipt() {
	int input;
	input = 0;

	while (input != 1 && input != 2)
	{
		puts("\nWould you like a receipt?");
		puts("\t1.  Yes");
		puts("\t2.  No");
		printf("%s", "Enter: ");
		scanf("%d", &input);
		switch (input)
		{
			case 1: puts("Receipt printing...\n");
				break;
			case 2: puts("Thank you for your transaction.\n");
				break;
			default: puts("\nPlease enter a valid number.");
		}
	}
}
