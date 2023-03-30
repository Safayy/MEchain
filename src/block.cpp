#include "block.h"
#include <iostream>
#include <openssl/sha.h>

Block::Block(int blockNumber, const std::string& previousBlockHash, const std::string& information) :
        blockNumber_(blockNumber),
        previousBlockHash_(previousBlockHash),
        information_(information) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)(previousBlockHash_.c_str()), previousBlockHash_.length(), hash);
    char hashStr[SHA256_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashStr[i*2], "%02x", (unsigned int)hash[i]);
    }
    currentBlockHash_ = std::string(hashStr);
    timestamp_ = time(nullptr);
}

int Block::getBlockNumber() const {
    return blockNumber_;
}

std::string Block::getCurrentBlockHash() const {
    return currentBlockHash_;
}

std::string Block::getPreviousBlockHash() const {
    return previousBlockHash_;
}

time_t Block::getTimestamp() const {
    return timestamp_;
}

std::string Block::getInformation() const {
    return information_;
}

void Block::setCurrentTime() {
    timestamp_ = time(nullptr);
}

void Block::setTimestamp(time_t timestamp) {
    timestamp_ = timestamp;
}

std::string Block::generateRandomString(int length) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string randomString = "";
    for (int i = 0; i < length; i++) {
        randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return randomString;
}

void Block::printBlock() const {
    std::cout << "Block " << getBlockNumber() << " | " << getCurrentBlockHash() << " | " << getPreviousBlockHash() << " | " << getTimestamp() << " | " << getInformation() << std::endl;
}