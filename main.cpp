// Coder/Developer: Karson Johnson & Sam Hendricks
// Class: COP 2006-80599, Fall 2024
// Date: NOV 13, 2024
// Description: C++ Program to help a user manage a bank account with loans
// FINAL PROJECT
#include <iostream>
#include <vector>
#include <string>
void menuOption();
   int main() {
       //checks what menu option a user selected
       int menuSelect;
       int loanAmount = 0;
       //var for if a user loan exists
       int loanYN = 0;
       //placeholder var used through switch statement
       int placeholdINT;
       int balance = 0;
       double loanInterest = 0;
       std::vector<std::string> history;
       std::cout << "Welcome to the money tracker!\n";
       std::cout << "Please enter a number 1-5 corresponding to the option you wish to select\n";
       while (true) {
           //calls function to display menu options
           menuOption();
           std::cin >> menuSelect;
           //switch statement to provide additional outputs based on users numerical input
           switch(menuSelect) {
               //deposit case
               case 1: {
                   std::cout << "How much money do you wish to deposit?\n";
                   std::cin >> placeholdINT;
                   if(placeholdINT > 0) {
                       balance = balance + placeholdINT;
                       //changes string to int
                       std::string placeholdSTRING = std::to_string(placeholdINT);
                       //adds string to history
                       history.push_back("Deposit : " + placeholdSTRING);
                       std::cout << "You have deposited $" << placeholdSTRING << "!\n";
                       break;
                   }
                   else {
                       std::cout << "You can not deposit a negative number\n";
                   }
               }
               //withdraw case
               case 2: {
                   std::cout << "How much money do you wish to withdraw?\n";
                   std::cin >> placeholdINT;
                   if(placeholdINT < balance) {
                       balance = balance - placeholdINT;
                       //change string to int
                       std::string placeholdSTRING = std::to_string(placeholdINT);
                       //add string to history
                       history.push_back("Withdraw : " + placeholdSTRING);
                       std::cout << "You have withdrew $" << placeholdSTRING << "!\n";
                   }
                   else {
                       //basic error handling
                       std::cout << "You can not withdraw more than your balance\n";
                   }
                   break;
               }
               //loan case
               case 3: {
                   //check if user currently has a loan
                   if (loanYN == 1) {
                       //loan menu
                       std::cout << "You have an outstanding loan for $" << loanAmount << "\n";
                       std::cout << "1 - Pay off\n"
                                 << "2 - View payments\n"
                                 << "3 - View loan\n"
                                 << "4 - Go back\n";
                       std::cin >> menuSelect;
                       switch (menuSelect) {
                           //pay loan case
                           case 1: {
                               std::cout << "How much money do you wish to pay?\n";
                               std::cin >> placeholdINT;
                               //if statements for error handling and payed loan case
                               if (placeholdINT < loanAmount) {
                                   loanAmount = loanAmount - placeholdINT;
                                   std::cout << "You have payed $" << placeholdINT << "!\n";
                                   //subtracts payment from balance
                                   balance = balance - placeholdINT;
                                   break;
                               }
                               if (placeholdINT == loanAmount) {
                                   loanYN = 0;
                                   std::cout << "You have payed your loan!\n";
                                   balance = balance - placeholdINT;
                                   break;
                               }
                               if (placeholdINT > loanAmount) {
                                   std::cout << "You can not pay more than your loan\n";
                                   break;
                               }
                               break;
                           }
                           //check next month payment case
                           case 2: {
                               std::cout << "At " << loanInterest << " percent interest, your next monthly payment to break even will be ";


                               std::cout << loanAmount * (loanInterest / 1200) << "\n";
                               break;
                           }
                           //check loan amount case
                           case 3: {
                               std::cout << "You currently have a loan for " << loanAmount << " dollars\n";
                               break;
                           }
                           //go back case
                           case 4:
                               break;
                       }
                   }
                   else {
                       while(true) {
                           menuSelect = 0;
                           std::cout << "You currently have no loans\n"
                                 << "1 - Create loan\n"
                                 << "2 - Go back\n";
                           std::cin >> menuSelect;
                           //create loan case
                           if(menuSelect == 1) {
                               std::cout << "How much money do you wish to loan?\n";
                               std::cin >> loanAmount;
                               std::cout << "What interest rate in percent?\n";
                               std::cin >> loanInterest;
                               //adds loan to balance
                               balance = balance + loanAmount;
                               loanYN = 1;
                               break;
                           }
                           //go back case
                           if(menuSelect == 2) {
                               break;
                           }
                       }
                       break;
                   }
                   break;
               }
               //check balance case
               case 4: {
                   std::cout << "Your current balance is $" << balance << "\n";
                   while (true) {
                       //yes/no variable
                       int YN;
                       //confirms that the user is ready to continue
                       std::cout << "Enter 1 to continue";
                       std::cin >> YN;
                       if (YN == 1)
                           break;
                   }
                   break;
               }
               //display history case
               //for loop to display all history for deposits and withdraws
               case 5: for (int i = 0; i < history.size(); i++)
                   std::cout << history[i] << "\n";
               while (true) {
                   int YN;
                   //confirm if user wants to continue
                   std::cout << "Enter 1 to continue";
                   std::cin >> YN;
                   if (YN == 1)
                       break;
               }
               break;


           }
       }
   }
//function for proof of understanding
void menuOption() {
       std::cout << "1 - Deposit\n"
                 << "2 - Withdraw\n"
                 << "3 - Loans\n"
                 << "4 - View balance\n"
                 << "5 - View history\n";
}



