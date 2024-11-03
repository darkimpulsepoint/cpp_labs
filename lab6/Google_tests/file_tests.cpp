#include "gtest/gtest.h"
#include "FileReader.h"
#include "FileWriter.h"
#include <chrono>
#include <filesystem>
#include <spdlog/spdlog.h>

class FileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        test_file_path = "test_file.txt";
        std::string content = "This is a test file with some content.";
        FileWriter::write(test_file_path, content);
    }

    void TearDown() override {
        std::filesystem::remove(test_file_path);
    }

    std::string test_file_path;
};

TEST_F(FileReaderTest, ReadValidFile) {
    spdlog::info("Running ReadValidFile test...");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_NO_THROW(FileReader::read(test_file_path));
    auto end = std::chrono::high_resolution_clock::now();

    std::string content = FileReader::read(test_file_path);
    EXPECT_EQ(content, "This is a test file with some content.");

    spdlog::info("ReadValidFile executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReadValidFile exceeded timeout of 100 ms";
    }
}

TEST_F(FileReaderTest, ReadFileContent) {
    spdlog::info("Running ReadFileContent test...");

    auto start = std::chrono::high_resolution_clock::now();
    std::string content = FileReader::read(test_file_path);
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_EQ(content, "This is a test file with some content.");

    spdlog::info("ReadFileContent executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReadFileContent exceeded timeout of 100 ms";
    }
}

TEST_F(FileReaderTest, ReadNonExistentFile) {
    spdlog::info("Running ReadNonExistentFile test...");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_THROW(FileReader::read("non_existent_file.txt"), std::runtime_error);
    auto end = std::chrono::high_resolution_clock::now();

    spdlog::info("ReadNonExistentFile executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReadNonExistentFile exceeded timeout of 100 ms";
    }
}

TEST_F(FileReaderTest, ReadEmptyFile) {
    spdlog::info("Running ReadEmptyFile test...");

    std::string empty_file_path = "empty_file.txt";
    FileWriter::write(empty_file_path, "");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_THROW(FileReader::read(empty_file_path), empty_file);
    auto end = std::chrono::high_resolution_clock::now();

    std::filesystem::remove(empty_file_path);

    spdlog::info("ReadEmptyFile executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "ReadEmptyFile exceeded timeout of 100 ms";
    }
}

TEST_F(FileReaderTest, ReadFilePerformance) {
    spdlog::info("Running ReadFilePerformance test...");

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        FileReader::read(test_file_path);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    spdlog::info("Time taken to read file 1000 times: {:.2f} ms", duration.count());
    EXPECT_LE(duration.count(), 1000);

    if (duration.count() > 1000) {
        GTEST_FAIL() << "ReadFilePerformance exceeded timeout of 1000 ms";
    }
}

class FileWriterTest : public ::testing::Test {
protected:
    void TearDown() override {
        std::filesystem::remove(test_file_path);
    }

    std::string test_file_path = "test_write_file.txt";
};

TEST_F(FileWriterTest, WriteValidFile) {
    spdlog::info("Running WriteValidFile test...");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_NO_THROW(FileWriter::write(test_file_path, "Hello, World!"));
    auto end = std::chrono::high_resolution_clock::now();

    std::string content = FileReader::read(test_file_path);
    EXPECT_EQ(content, "Hello, World!");

    spdlog::info("WriteValidFile executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "WriteValidFile exceeded timeout of 100 ms";
    }
}

TEST_F(FileWriterTest, WriteEmptyContent) {
    spdlog::info("Running WriteEmptyContent test...");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_NO_THROW(FileWriter::write(test_file_path, ""));
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_THROW(FileReader::read(test_file_path), empty_file);

    spdlog::info("WriteEmptyContent executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "WriteEmptyContent exceeded timeout of 100 ms";
    }
}

TEST_F(FileWriterTest, WriteToExistingFile) {
    spdlog::info("Running WriteToExistingFile test...");

    auto start = std::chrono::high_resolution_clock::now();
    FileWriter::write(test_file_path, "Initial content.");
    EXPECT_NO_THROW(FileWriter::write(test_file_path, "Overwritten content."));
    auto end = std::chrono::high_resolution_clock::now();

    std::string content = FileReader::read(test_file_path);
    EXPECT_EQ(content, "Overwritten content.");

    spdlog::info("WriteToExistingFile executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "WriteToExistingFile exceeded timeout of 100 ms";
    }
}

TEST_F(FileWriterTest, WriteToInvalidPath) {
    spdlog::info("Running WriteToInvalidPath test...");

    auto start = std::chrono::high_resolution_clock::now();
    EXPECT_THROW(FileWriter::write("/invalid/path/file.txt", "Content"), std::runtime_error);
    auto end = std::chrono::high_resolution_clock::now();

    spdlog::info("WriteToInvalidPath executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "WriteToInvalidPath exceeded timeout of 100 ms";
    }
}

TEST_F(FileWriterTest, WriteLongContent) {
    spdlog::info("Running WriteLongContent test...");

    std::string long_content(10000, 'A');
    auto start = std::chrono::high_resolution_clock::now();

    EXPECT_NO_THROW(FileWriter::write(test_file_path, long_content));

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    spdlog::info("Time taken to write long content: {:.2f} ms", duration.count());

    std::string content = FileReader::read(test_file_path);
    EXPECT_EQ(content, long_content);

    if (duration.count() > 1000) {
        GTEST_FAIL() << "WriteLongContent exceeded timeout of 1000 ms";
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    spdlog::set_level(spdlog::level::info);
    return RUN_ALL_TESTS();
}