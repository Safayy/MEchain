#include <iostream>
using namespace std;

// Define an enumeration type for the available commands
enum Command { MAN, SHOW_BLOCKCHAIN, ADD_CASE, ADD_TRANSACTION, INVALID, EXIT };

// Function to show available commands to the user
void showManual(){
    cout << "Available commands: " << endl;
    cout << "man / help \t  Show commands" << endl;
    cout << "blockchain show Show all records in blockchain" << endl;
    cout << "case add \t Add a patient case to blockchain"<< endl;
    cout << "transaction add\t Add a payment transaction to blockchain" << endl;
}