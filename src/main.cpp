// Include necessary libraries and header files
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "block.cpp" // Include the Block class implementation file
using namespace std; // Using the standard namespace


// Define an enumeration type for the available commands
enum Command { MAN, SHOW_BLOCKCHAIN, ADD_CASE, ADD_TRANSACTION, INVALID, EXIT };

// Function to show available commands to the user
void showManual(){
    cout << "Available commands: " << endl;
    cout << "man \t\t Show commands" << endl;
    cout << "blockchain show Show all records in blockchain" << endl;
    cout << "case add \t Add a patient case to blockchain"<< endl;
    cout << "transaction add\t Add a payment transaction to blockchain" << endl;
}

// Function to load the blockchain from a file
vector<Block> loadBlockchainFromFile(string filename) {
    vector<Block> blockchain;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        int blockNumber = 0;
        string previousBlockHash = "";
        while (getline(file, line)) {
            string information = line;
            Block block(++blockNumber, previousBlockHash, information); // Create a new Block object with the current line of information
            blockchain.push_back(block); // Add the new Block object to the blockchain vector
            previousBlockHash = block.getCurrentBlockHash(); // Update the previous block hash with the current block hash
        }
        file.close();
        }
    return blockchain;
    }

// Function to save the blockchain to a file
void saveBlockchainToFile(vector<Block> blockchain, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (Block block : blockchain) { // Iterate over each block in the blockchain
            file << block.getBlockNumber() << " " << block.getCurrentBlockHash() << " " << block.getPreviousBlockHash() << " " << block.getTimestamp() << " " << block.getInformation() << endl; // Write the block information to the file
        }
        file.close();
    }
}

// Main function
int main() {
    string filename = "blockchain"; // Define the filename to use for the blockchain file
    vector<Block> blockchain = loadBlockchainFromFile(filename); // Load the blockchain from the file

    // Introduce user to program and commands
    cout << "********************* MEDICAL BLOCKCHAIN *********************" << endl;
    showManual();

    while (true) {
        string commandStr;
        cout << "> ";
        getline(cin, commandStr);

        //Set command Enum
        Command command = INVALID;
        if (commandStr == "man") {
            command = MAN;
        }
        else if (commandStr == "blockchain show") {
            command = SHOW_BLOCKCHAIN;
        } else if (commandStr == "case add") {
            command = ADD_CASE;
        } else if (commandStr == "transaction add") {
            command = ADD_TRANSACTION;
        } else if (commandStr == "exit") {
            command = EXIT;
        }

        //Run function according to user command Enum
        switch (command) {
            case MAN: {
                showManual();
                break;
            }
            case SHOW_BLOCKCHAIN: { //Run command to show blockchain
                cout << "Blockchain: " << endl;
                for (Block block : blockchain) {
                    block.printBlock();
                }
                break;
            }
            case ADD_CASE: { // Run command to add case to blockchain
                string patientID;
                string patientName;
                string sickness;
                string medicineCollectionType;

                cout << "Patient ID: ";
                getline(cin, patientID);

                cout << "Patient Name: ";
                getline(cin, patientName);

                cout << "Sickness: ";
                getline(cin, sickness);

                cout << "Medicine Collection Type: ";
                getline(cin, medicineCollectionType);

                string information = "Patient ID: " + patientID + " | Patient Name: " + patientName + " | Sickness: " + sickness + " | Medicine Collection Type: " + medicineCollectionType;

                if (blockchain.empty()) {
                    Block firstBlock(0, "", information);
                    blockchain.push_back(firstBlock);
                    firstBlock.printBlock();
                } else {
                    Block previousBlock = blockchain.back();
                    Block newBlock(previousBlock.getBlockNumber() + 1, previousBlock.getCurrentBlockHash(), information);
                    blockchain.push_back(newBlock);
                    newBlock.printBlock();
                }
                break;
            }
            case ADD_TRANSACTION: {// Run command to add transaction to blockchain
                string transactionID;
                string outpatientCreditBalance;
                string inpatientCreditBalance;
                string disease;
                string paymentType;
                string outpatientVisitingLimit;

                cout << "Transaction ID: ";
                getline(cin, transactionID);

                cout << "Outpatient Credit Balance: ";
                getline(cin, outpatientCreditBalance);

                cout << "Inpatient Credit Balance: ";
                getline(cin, inpatientCreditBalance);

                cout << "Disease: ";
                getline(cin, disease);

                cout << "Payment type: ";
                getline(cin, paymentType);

                cout << "Outpatient visiting limit: ";
                getline(cin, outpatientVisitingLimit);

                string information = "Transaction ID: " + transactionID + " | Outpatient Credit Balance: " + outpatientCreditBalance + " | Inpatient Credit Balance: " + inpatientCreditBalance + " | Disease: " + disease + " | Payment type: " + paymentType + " | Outpatient visiting limit: " + outpatientVisitingLimit;

                if (blockchain.empty()) {
                    Block firstBlock(0, "", information);
                    blockchain.push_back(firstBlock);
                    firstBlock.printBlock();
                } else {
                    Block previousBlock = blockchain.back();
                    Block newBlock(previousBlock.getBlockNumber() + 1, previousBlock.getCurrentBlockHash(), information);
                    blockchain.push_back(newBlock);
                    newBlock.printBlock();
                }
                break;
            }
            case EXIT: {// Run command to exit program
                return 0;
            }

            default:
                cout << "Invalid command" << endl;
                break;
        }
        //Save blockchain to file
        saveBlockchainToFile(blockchain, filename);
    }

    return 0;
}