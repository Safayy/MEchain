#include "../src/block.h"
#include <gtest/gtest.h>

TEST(BlockTest, BasicTest) {
    Block block(1, "0", "Demo Test Information");
    EXPECT_EQ(block.getBlockNumber(), 1);
    EXPECT_EQ(block.getPreviousBlockHash(), "0");
    EXPECT_EQ(block.getInformation(), "Demo Test Information");
    block.setCurrentTime();
    time_t timestamp = block.getTimestamp();
    EXPECT_TRUE(timestamp > 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}