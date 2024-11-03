#include "gtest/gtest.h"
#include "StringService.h"
#include "FileWriter.h"
#include "FileReader.h"
#include <filesystem>
#include <spdlog/spdlog.h>
#include <chrono>
#include <stdexcept>

class StringServiceTest : public ::testing::Test {
protected:
    std::string test_filename;
    std::string output_filename;
};

TEST_F(StringServiceTest, MaxConsecutiveDigits) {
    test_filename = "test_digits.txt";
    output_filename = "max_digits.txt";
    FileWriter::write(test_filename, "abc123de456fgh");

    spdlog::info("Running MaxConsecutiveDigits test...");

    auto start = std::chrono::high_resolution_clock::now();
    double timeout_ms = 100;

    int max_count = StringService::maxConsecutiveDigitsInFile_WriteToFileAndZip(test_filename, output_filename.c_str());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    if (duration.count() > timeout_ms) {
        GTEST_FAIL() << "MaxConsecutiveDigits test exceeded timeout of " << timeout_ms << " ms";
    }

    EXPECT_EQ(max_count, 3);

    std::string output_content = FileReader::read(output_filename);
    EXPECT_EQ(output_content, "3");
}

TEST_F(StringServiceTest, EmptyFile) {
    test_filename = "empty.txt";
    output_filename = "output_empty.txt";
    FileWriter::write(test_filename, "");

    spdlog::info("Running EmptyFile test...");

    auto start = std::chrono::high_resolution_clock::now();
    double timeout_ms = 100;

    EXPECT_THROW(StringService::maxConsecutiveDigitsInFile_WriteToFileAndZip(test_filename, output_filename.c_str()),
                 empty_file);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    if (duration.count() > timeout_ms) {
        GTEST_FAIL() << "EmptyFile test exceeded timeout of " << timeout_ms << " ms";
    }

    std::filesystem::remove(test_filename);
}

TEST_F(StringServiceTest, NoDigits) {
    test_filename = "no_digits.txt";
    output_filename = "output_no_digits.txt";
    FileWriter::write(test_filename, "abcdefg");

    spdlog::info("Running NoDigits test...");

    auto start = std::chrono::high_resolution_clock::now();
    double timeout_ms = 100;

    int max_count = StringService::maxConsecutiveDigitsInFile_WriteToFileAndZip(test_filename, output_filename.c_str());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    if (duration.count() > timeout_ms) {
        GTEST_FAIL() << "NoDigits test exceeded timeout of " << timeout_ms << " ms";
    }

    EXPECT_EQ(max_count, 0);

    std::string output_content = FileReader::read(output_filename);
    EXPECT_EQ(output_content, "0");
}

TEST_F(StringServiceTest, LargeInputFile) {
    test_filename = "large_input.txt";
    output_filename = "output_large.txt";
    std::string large_content;
    for (int i = 0; i < 100000; ++i) {
        large_content += "1234567890\n";
    }
    FileWriter::write(test_filename, large_content);

    spdlog::info("Running LargeInputFile test...");

    auto start = std::chrono::high_resolution_clock::now();
    double timeout_ms = 100;

    int max_count = StringService::maxConsecutiveDigitsInFile_WriteToFileAndZip(test_filename, output_filename.c_str());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    if (duration.count() > timeout_ms) {
        GTEST_FAIL() << "LargeInputFile test exceeded timeout of " << timeout_ms << " ms";
    }

    EXPECT_EQ(max_count, 10);

    std::filesystem::remove(test_filename);
}