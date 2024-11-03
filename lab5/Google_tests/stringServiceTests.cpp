#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include "StringService.h"
#include "FileReader.h"
#include <chrono>
#include <algorithm>
#include <fstream>

std::string createTempFile(const std::string& content) {
    std::string filename = "temp_test_file.txt";
    std::ofstream out(filename);
    out << content;
    out.close();
    return filename;
}

class StringServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
        std::remove("temp_test_file.txt");
    }
};

TEST_F(StringServiceTest, InsertAfterSubstring) {
    std::string filename = createTempFile("Hello world, this is a test");
    auto start = std::chrono::high_resolution_clock::now();

    std::string result = StringService::getInsertAfterSubstring(filename, "is", "INSERTED");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result, "Hello world, thisINSERTED isINSERTED a test");
    spdlog::info("Elapsed time for InsertAfterSubstring: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, FindUniqueWordsOfLengthInAllQuestions) {
    std::string filename = createTempFile("What is your name? My name is John? How are you?");
    auto start = std::chrono::high_resolution_clock::now();

    auto result = StringService::findUniqueWordsOfLengthInQuestion(filename, 4);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(( std::find(result.begin(), result.end(), "what") != result.end()), true);
    EXPECT_EQ(( std::find(result.begin(), result.end(), "your") != result.end()), true);
    EXPECT_EQ(( std::find(result.begin(), result.end(), "name") != result.end()), true);
    EXPECT_EQ(( std::find(result.begin(), result.end(), "john") != result.end()), true);
    spdlog::info("Elapsed time for FindUniqueWordsOfLengthInQuestion: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, Decompress) {
    std::string filename = createTempFile("a5b3c2");
    auto start = std::chrono::high_resolution_clock::now();

    std::string result = StringService::decompress(filename);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result, "aaaaabbbcc");
    spdlog::info("Elapsed time for Decompress: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, InsertAfterSubstringEdgeCase) {
    std::string filename = createTempFile("Test string");
    auto start = std::chrono::high_resolution_clock::now();

    std::string result = StringService::getInsertAfterSubstring(filename, "notfound", "INSERTED");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result, "Test string");
    spdlog::info("Elapsed time for InsertAfterSubstring edge case: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, InsertAfterEmptySubstr) {
    std::string filename = createTempFile("Test string");
    auto start = std::chrono::high_resolution_clock::now();

    std::string result = StringService::getInsertAfterSubstring(filename, "", "INSERTED");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result, "Test string");
    spdlog::info("Elapsed time for InsertAfterSubstring edge case: {} seconds", elapsed.count());
    spdlog::info("Elapsed time for InsertAfterSubstring edge case: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, FindUniqueWordsOfLengthInQuestionNoQuestions) {
    std::string filename = createTempFile("This is a statement.");
    auto start = std::chrono::high_resolution_clock::now();

    auto result = StringService::findUniqueWordsOfLengthInQuestion(filename, 4);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result.size(), 0);
    spdlog::info("Elapsed time for FindUniqueWordsOfLengthInQuestion with no questions: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, DecompressEdgeCase) {
    std::string filename = createTempFile("a0");
    auto start = std::chrono::high_resolution_clock::now();

    std::string result = StringService::decompress(filename);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result, "");
    spdlog::info("Elapsed time for Decompress edge case: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, InsertAfterSubstringMultipleOccurrences) {
    std::string filename = createTempFile("This is a test. This is another test.");
    auto start = std::chrono::high_resolution_clock::now();

    std::string result = StringService::getInsertAfterSubstring(filename, "is", "INSERTED");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result, "ThisINSERTED isINSERTED a test. ThisINSERTED isINSERTED another test.");
    spdlog::info("Elapsed time for InsertAfterSubstring with multiple occurrences: {} seconds", elapsed.count());
}

TEST_F(StringServiceTest, FindUniqueWordsOfLengthInQuestionMultipleQuestions) {
    std::string filename = createTempFile("What is your name? Where do you live.");
    auto start = std::chrono::high_resolution_clock::now();

    auto result = StringService::findUniqueWordsOfLengthInQuestion(filename, 4);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(( std::find(result.begin(), result.end(), "what") != result.end()), true);
    EXPECT_EQ(( std::find(result.begin(), result.end(), "your") != result.end()), true);
    EXPECT_EQ(( std::find(result.begin(), result.end(), "name") != result.end()), true);
    spdlog::info("Elapsed time for FindUniqueWordsOfLengthInQuestion with multiple questions: {} seconds", elapsed.count());
}

class FileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::ofstream out("test_file.txt");
        out << "Hello, World!";
        out.close();

        std::ofstream emptyFile("empty_file.txt");
        emptyFile.close();

        nonexistentFile = "nonexistent_file.txt";
    }

    void TearDown() override {
        std::remove("test_file.txt");
        std::remove("empty_file.txt");
    }

    std::string nonexistentFile;
};

TEST_F(FileReaderTest, ReadValidFile) {
    auto start = std::chrono::high_resolution_clock::now();

    std::string content = FileReader::read("test_file.txt");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(content, "Hello, World!");
    spdlog::info("Elapsed time for ReadValidFile: {} seconds", elapsed.count());
}

TEST_F(FileReaderTest, ReadNonExistentFile) {
    auto start = std::chrono::high_resolution_clock::now();

    EXPECT_THROW(FileReader::read(nonexistentFile), std::runtime_error);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    spdlog::info("Elapsed time for ReadNonExistentFile: {} seconds", elapsed.count());
}

TEST_F(FileReaderTest, ReadEmptyFile) {
    auto start = std::chrono::high_resolution_clock::now();

    EXPECT_THROW(FileReader::read("empty_file.txt"), empty_file);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    spdlog::info("Elapsed time for ReadEmptyFile: {} seconds", elapsed.count());
}

TEST_F(FileReaderTest, ReadFileWithWhitespace) {
    std::ofstream whitespaceFile("whitespace_file.txt");
    whitespaceFile << "   \n   ";
    whitespaceFile.close();

    auto start = std::chrono::high_resolution_clock::now();

    EXPECT_THROW(FileReader::read("whitespace_file.txt"), empty_file);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    spdlog::info("Elapsed time for ReadFileWithWhitespace: {} seconds", elapsed.count());

    std::remove("whitespace_file.txt");
}

TEST_F(FileReaderTest, ReadJustCreatedFile) {
    std::ofstream justCreatedFile("just_created_file.txt");
    justCreatedFile << "Some content";
    justCreatedFile.close();

    auto start = std::chrono::high_resolution_clock::now();

    std::string content = FileReader::read("just_created_file.txt");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_EQ(content, "Some content");
    spdlog::info("Elapsed time for ReadJustCreatedFile: {} seconds", elapsed.count());

    std::remove("just_created_file.txt");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    spdlog::info("Starting tests...");

    int result = RUN_ALL_TESTS();

    spdlog::info("Tests finished with result: {}", result);
    return result;
}