#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
// #include "block.cpp"
using namespace std;

// Function to load the blockchain from a file
vector<Block> loadBlockchainFromFile(string filename) {
    vector<Block> blockchain;
    try {
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
        } else {
            throw runtime_error("Could not open the blockchain file.");
        }
    } catch (const exception& e) {
        cerr << "An exception occurred while trying to load the blockchain from file: " << e.what() << endl;
    }
    return blockchain;
}

// Function to save the blockchain to a file
void saveBlockchainToFile(vector<Block> blockchain, string filename) {
    try {
        ofstream file(filename);
        if (file.is_open()) {
            for (Block block : blockchain) { // Iterate over each block in the blockchain
                file << block.getBlockNumber() << " " << block.getCurrentBlockHash() << " " << block.getPreviousBlockHash() << " " << block.getTimestamp() << " " << block.getInformation() << endl; // Write the block information to the file
            }
            file.close();
        } else {
            throw runtime_error("Could not open the blockchain file.");
        }
    } catch (const exception& e) {
        cerr << "An exception occurred while trying to save the blockchain to file: " << e.what() << endl;
    }
}