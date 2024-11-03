#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <chrono>
#include <string>
#include "BracketsService.h" // Убедитесь, что у вас есть этот заголовочный файл

TEST(StackTest, PushAndTopTest) {
    Stack<int> stack;

    auto start = std::chrono::high_resolution_clock::now();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("PushAndTopTest duration: {} ms", duration.count());

    EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, PopTest) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

    auto start = std::chrono::high_resolution_clock::now();
    stack.pop();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("PopTest duration: {} ms", duration.count());

    EXPECT_EQ(stack.top(), 1);
}

TEST(StackTest, IsEmptyTest) {
    Stack<int> stack;

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_TRUE(stack.isEmpty());
    stack.push(1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("IsEmptyTest duration: {} ms", duration.count());

    EXPECT_FALSE(stack.isEmpty());
}

TEST(StackTest, TopOnEmptyStackTest) {
    Stack<int> stack;

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_THROW(stack.top(), std::underflow_error);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("TopOnEmptyStackTest duration: {} ms", duration.count());
}

TEST(StackTest, PopOnEmptyStackTest) {
    Stack<int> stack;

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_THROW(stack.pop(), std::underflow_error);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("PopOnEmptyStackTest duration: {} ms", duration.count());
}

TEST(BracketsServiceTest, ValidBracketsTest) {
    std::string str = "({[]})";

    auto start = std::chrono::high_resolution_clock::now();
    bool result = BracketsService::areBracketsValid(str);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("ValidBracketsTest duration: {} ms", duration.count());

    EXPECT_EQ(result, true);
}

TEST(BracketsServiceTest, InvalidBracketsTest) {
    std::string str = "({[})";

    auto start = std::chrono::high_resolution_clock::now();
    bool result = BracketsService::areBracketsValid(str);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("InvalidBracketsTest duration: {} ms", duration.count());

    EXPECT_EQ(result, false);
}

TEST(BracketsServiceTest, EmptyStringTest) {
    std::string str = "";

    auto start = std::chrono::high_resolution_clock::now();
    bool result = BracketsService::areBracketsValid(str);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("EmptyStringTest duration: {} ms", duration.count());

    EXPECT_EQ(result, true);
}

TEST(BracketsServiceTest, MultipleTypesOfBracketsTest) {
    std::string str = "([{}])";

    auto start = std::chrono::high_resolution_clock::now();
    bool result = BracketsService::areBracketsValid(str);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("MultipleTypesOfBracketsTest duration: {} ms", duration.count());

    EXPECT_EQ(result, true);
}

TEST(BracketsServiceTest, UnmatchedBracketsTest) {
    std::string str = "([)]";

    auto start = std::chrono::high_resolution_clock::now();
    bool result = BracketsService::areBracketsValid(str);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("UnmatchedBracketsTest duration: {} ms", duration.count());

    EXPECT_EQ(result, false);
}
