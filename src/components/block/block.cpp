struct Block {
    int blockNumber;
    string currentBlockHash;
    string previousBlockHash;
    time_t timestamp;
    string information;
};

Block createNewBlock(int blockNumber, string previousBlockHash, string information) {
    Block newBlock;
    newBlock.blockNumber = blockNumber;
    newBlock.currentBlockHash = generateRandomString(10);
    newBlock.previousBlockHash = previousBlockHash;
    newBlock.timestamp = time(nullptr);
    newBlock.information = information;
    return newBlock;
}