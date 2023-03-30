#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>

class Block {
public:
    Block(int blockNumber, const std::string& previousBlockHash, const std::string& information);

    int getBlockNumber() const;
    std::string getCurrentBlockHash() const;
    std::string getPreviousBlockHash() const;
    time_t getTimestamp() const;
    std::string getInformation() const;
    void setCurrentTime();
    void setTimestamp(time_t timestamp);
    void printBlock() const;

private:
    int blockNumber_;
    std::string currentBlockHash_;
    std::string previousBlockHash_;
    time_t timestamp_;
    std::string information_;

    std::string generateRandomString(int length);
};

#endif