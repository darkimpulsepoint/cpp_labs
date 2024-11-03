#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <chrono>
#include <sstream>
#include <unordered_set>
#include <fstream>
#include "ObjectInfo.h"
#include "ListService.h"

TEST(LinkedListTest, PushBackTest) {
    LinkedList<int> list;
    auto start = std::chrono::high_resolution_clock::now();

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("PushBackTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head()->data, 1);
}

TEST(LinkedListTest, PushBackMultipleTest) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto start = std::chrono::high_resolution_clock::now();

    EXPECT_EQ(list.get_head()->next->data, 2);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("PushBackMultipleTest duration: {} ms", duration.count());
}

TEST(LinkedListTest, GetHeadTest) {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    auto start = std::chrono::high_resolution_clock::now();

    EXPECT_EQ(list.get_head()->data, 10);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("GetHeadTest duration: {} ms", duration.count());
}

TEST(LinkedListTest, SortTest) {
    LinkedList<ObjectInfo> list;
    list.push_back(ObjectInfo("B", 2));
    list.push_back(ObjectInfo("A", 1));
    list.push_back(ObjectInfo("C", 3));

    auto start = std::chrono::high_resolution_clock::now();

    list.sort();
    EXPECT_EQ(list.get_head()->data.getName(), "A");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("SortTest duration: {} ms", duration.count());
}

TEST(ListServiceTest, CreateListFromFileTest) {
    std::string filename = "test.txt";
    {
        std::ofstream ofs(filename);
        ofs << "Object1 1\n";
        ofs << "Object2 2\n";
    }

    auto start = std::chrono::high_resolution_clock::now();

    LinkedList<ObjectInfo> list = ListService::createListFromFile(filename);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CreateListFromFileTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head()->data.getName(), "Object1");
}

TEST(ListServiceTest, CreateListFromEmptyFileTest) {
    std::string filename = "empty_test.txt";
    {
        std::ofstream ofs(filename);
        // Пустой файл
    }

    auto start = std::chrono::high_resolution_clock::now();

    LinkedList<ObjectInfo> list = ListService::createListFromFile(filename);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CreateListFromEmptyFileTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head(), nullptr);
}

TEST(ListServiceTest, CreateListFromMalformedFileTest) {
    std::string filename = "malformed_test.txt";
    {
        std::ofstream ofs(filename);
        ofs << "Object1\n";
    }

    auto start = std::chrono::high_resolution_clock::now();

    LinkedList<ObjectInfo> list = ListService::createListFromFile(filename);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CreateListFromMalformedFileTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head(), nullptr);
}

TEST(ListServiceTest, CreateListFromFileMultipleObjectsTest) {
    std::string filename = "multiple_objects.txt";
    {
        std::ofstream ofs(filename);
        ofs << "Object1 1\n";
        ofs << "Object2 2\n";
        ofs << "Object3 3\n";
    }

    auto start = std::chrono::high_resolution_clock::now();

    LinkedList<ObjectInfo> list = ListService::createListFromFile(filename);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CreateListFromFileMultipleObjectsTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head()->data.getName(), "Object1");
}


TEST(ListServiceTest, CompressWithDuplicateNamesTest) {
    LinkedList<ObjectInfo> list;
    list.push_back(ObjectInfo("Object1", 1));
    list.push_back(ObjectInfo("Object2", 2));
    list.push_back(ObjectInfo("Object1", 3));
    list.push_back(ObjectInfo("Object3", 4));
    list.push_back(ObjectInfo("Object2", 5));

    auto start = std::chrono::high_resolution_clock::now();

    ListService::compress(list);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CompressWithDuplicateNamesTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head()->data.getName(), "Object1");
    EXPECT_EQ(list.get_head()->next->data.getName(), "Object2");
    EXPECT_EQ(list.get_head()->next->next->data.getName(), "Object3");
}

TEST(ListServiceTest, CompressWithNoDuplicatesTest) {
    LinkedList<ObjectInfo> list;
    list.push_back(ObjectInfo("Object1", 1));
    list.push_back(ObjectInfo("Object2", 2));
    list.push_back(ObjectInfo("Object3", 3));

    auto start = std::chrono::high_resolution_clock::now();

    ListService::compress(list);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CompressWithNoDuplicatesTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head()->data.getName(), "Object1");
    EXPECT_EQ(list.get_head()->next->data.getName(), "Object2");
    EXPECT_EQ(list.get_head()->next->next->data.getName(), "Object3");
}

TEST(ListServiceTest, CompressWithAllDuplicatesTest) {
    LinkedList<ObjectInfo> list;
    list.push_back(ObjectInfo("Object1", 1));
    list.push_back(ObjectInfo("Object1", 2));
    list.push_back(ObjectInfo("Object1", 3));

    auto start = std::chrono::high_resolution_clock::now();

    ListService::compress(list);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CompressWithAllDuplicatesTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head()->data.getName(), "Object1");
    EXPECT_EQ(list.get_head()->next, nullptr);
}

TEST(ListServiceTest, CompressEmptyListTest) {
    LinkedList<ObjectInfo> list;

    auto start = std::chrono::high_resolution_clock::now();

    ListService::compress(list);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CompressEmptyListTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head(), nullptr);
}

TEST(ListServiceTest, CompressWithSingleElementTest) {
    LinkedList<ObjectInfo> list;
    list.push_back(ObjectInfo("Object1", 1));

    auto start = std::chrono::high_resolution_clock::now();

    ListService::compress(list);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    spdlog::info("CompressWithSingleElementTest duration: {} ms", duration.count());

    EXPECT_EQ(list.get_head()->data.getName(), "Object1");
    EXPECT_EQ(list.get_head()->next, nullptr);
}

int main(int argc, char **argv) {
    spdlog::set_level(spdlog::level::info);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}