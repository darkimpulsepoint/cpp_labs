#include "gtest/gtest.h"
#include "FileReverser.h"
#include "FileWriter.h"
#include "FileReader.h"
#include <filesystem>
#include <chrono>
#include <spdlog/spdlog.h>

class FileReverserTest : public ::testing::Test {
protected:
    void SetUp() override {
        input_filename = "input_test.txt";
        output_filename = "output_test.txt";
        FileWriter::write(input_filename, "Hello\nWorld\nTest");
    }

    std::string input_filename;
    std::string output_filename;
};

TEST_F(FileReverserTest, ReverseLinesAndZip) {
    spdlog::info("Running ReverseLinesAndZip test...");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_NO_THROW(FileReverser::reverseLinesAndZip(input_filename, output_filename));
    auto end = std::chrono::high_resolution_clock::now();

    std::string output_content = FileReader::read(output_filename);
    EXPECT_EQ(output_content, "olleH\ndlroW\ntseT\n");

    spdlog::info("ReverseLinesAndZip executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReverseLinesAndZip exceeded timeout of 100 ms";
    }
}

TEST_F(FileReverserTest, ReverseEmptyFile) {
    spdlog::info("Running ReverseEmptyFile test...");

    std::string empty_input_filename = "empty_input_test.txt";
    std::string empty_output_filename = "empty_output_test.txt";
    FileWriter::write(empty_input_filename, "");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_THROW(FileReverser::reverseLinesAndZip(empty_input_filename, empty_output_filename), empty_file);
    auto end = std::chrono::high_resolution_clock::now();

    spdlog::info("ReverseEmptyFile executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReverseEmptyFile exceeded timeout of 100 ms";
    }

    std::filesystem::remove(empty_input_filename);
}

TEST_F(FileReverserTest, ReverseSingleLineFile) {
    spdlog::info("Running ReverseSingleLineFile test...");

    std::string single_line_input_filename = "single_line_test.txt";
    std::string single_line_output_filename = "single_line_output_test.txt";
    FileWriter::write(single_line_input_filename, "SingleLine");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_NO_THROW(FileReverser::reverseLinesAndZip(single_line_input_filename, single_line_output_filename));
    auto end = std::chrono::high_resolution_clock::now();

    std::string output_content = FileReader::read(single_line_output_filename);
    EXPECT_EQ(output_content, "eniLelgniS\n");

    spdlog::info("ReverseSingleLineFile executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    std::filesystem::remove(single_line_input_filename);
    std::filesystem::remove(single_line_output_filename);

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReverseSingleLineFile exceeded timeout of 100 ms";
    }
}

TEST_F(FileReverserTest, ReverseSpecialCharacters) {
    spdlog::info("Running ReverseSpecialCharacters test...");

    std::string special_input_filename = "special_input_test.txt";
    std::string special_output_filename = "special_output_test.txt";
    FileWriter::write(special_input_filename, "Line1!@#$\nLine2%^&*\n");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_NO_THROW(FileReverser::reverseLinesAndZip(special_input_filename, special_output_filename));
    auto end = std::chrono::high_resolution_clock::now();

    std::string output_content = FileReader::read(special_output_filename);
    EXPECT_EQ(output_content, "$#@!1eniL\n*&^%2eniL\n");

    spdlog::info("ReverseSpecialCharacters executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    std::filesystem::remove(special_input_filename);
    std::filesystem::remove(special_output_filename);

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReverseSpecialCharacters exceeded timeout of 100 ms";
    }
}

TEST_F(FileReverserTest, ReverseWithBlankLines) {
    spdlog::info("Running ReverseWithBlankLines test...");

    std::string blank_lines_input_filename = "blank_lines_input_test.txt";
    std::string blank_lines_output_filename = "blank_lines_output_test.txt";
    FileWriter::write(blank_lines_input_filename, "First Line\n\nSecond Line\n\n\n");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_NO_THROW(FileReverser::reverseLinesAndZip(blank_lines_input_filename, blank_lines_output_filename));
    auto end = std::chrono::high_resolution_clock::now();

    std::string output_content = FileReader::read(blank_lines_output_filename);
    EXPECT_EQ(output_content, "eniL tsriF\n\neniL dnoceS\n\n\n");

    spdlog::info("ReverseWithBlankLines executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    std::filesystem::remove(blank_lines_input_filename);
    std::filesystem::remove(blank_lines_output_filename);

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReverseWithBlankLines exceeded timeout of 100 ms";
    }
}