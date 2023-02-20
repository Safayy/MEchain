/**In the context of a blockchain application, the main.cpp file would
 *  typically create and manage the blockchain object, and provide an
 *  interface for adding new blocks and retrieving existing ones.
 *  It may also interact with other parts of the system, such as the user
 *  interface or a database.
*/
//Doxygen
//Google Test

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

struct Block {
    int blockNumber;
    string currentBlockHash;
    string previousBlockHash;
    time_t timestamp;
    string information;
};

string generateRandomString(int length) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string randomString = "";
    for (int i = 0; i < length; i++) {
        randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return randomString;
}

Block createNewBlock(int blockNumber, string previousBlockHash, string information) {
    Block newBlock;
    newBlock.blockNumber = blockNumber;
    newBlock.currentBlockHash = generateRandomString(10); // Generate random string for current block hash
    newBlock.previousBlockHash = previousBlockHash;
    newBlock.timestamp = time(nullptr); // Get current time
    newBlock.information = information;
    return newBlock;
}

void printBlock(Block block) {
    cout << "Block " << block.blockNumber << " | " << block.currentBlockHash << " | " << block.previousBlockHash << " | " << ctime(&block.timestamp) << " | " << block.information << endl;
}

int main() {
    vector<Block> blockchain;

    // Create first block with dummy information
    Block firstBlock = createNewBlock(0, "", "Employee ID: 123456 | Name: John Doe | Employment Type: Full-time | Department: IT | Branch: Kuala Lumpur");
    blockchain.push_back(firstBlock);
    printBlock(firstBlock);

    // Create additional blocks with more information
    Block secondBlock = createNewBlock(1, firstBlock.currentBlockHash, "Patient ID: 789012 | Sickness: Flu | Medicine Collection Type: On-demand | Outpatient clinic visit no. since 01/01/2023: 2nd time | Panel clinic name: Klinik Medik");
    blockchain.push_back(secondBlock);
    printBlock(secondBlock);

    Block thirdBlock = createNewBlock(2, secondBlock.currentBlockHash, "Transaction ID: 345678 | Outpatient Credit Balance: RM500.00 | Inpatient Credit Balance: RM10,000.00 | Disease: None | Payment type: Credit card | Outpatient visiting limit: 5 times per month");
    blockchain.push_back(thirdBlock);
    printBlock(thirdBlock);

    return 0;
}