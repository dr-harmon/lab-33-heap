#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "heap.h"

using namespace std;

TEST_CASE("Insert/remove/get (Example 8.4)")
{
    PriorityQueue<int> p(5);
    REQUIRE_THROWS(p.getMinimum());
    p.insert(5);
    REQUIRE(p.getMinimum() == 5);
    p.insert(9);
    REQUIRE(p.getMinimum() == 5);
    p.insert(2);
    REQUIRE(p.getMinimum() == 2);
    p.insert(7);
    REQUIRE(p.getMinimum() == 2);
    p.removeMinimum();
    REQUIRE(p.getSize() == 3);
    REQUIRE(p.getMinimum() == 5);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 7);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 9);
    p.removeMinimum();
    REQUIRE(p.isEmpty());
    REQUIRE_THROWS(p.removeMinimum());
}

TEST_CASE("Heap sort (Figure 8.1)")
{
    PriorityQueue<int> p(10);
    p.insert(7);
    p.insert(4);
    p.insert(8);
    p.insert(2);
    p.insert(5);
    p.insert(3);
    p.insert(9);
    REQUIRE(p.getMinimum() == 2);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 3);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 4);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 5);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 7);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 8);
    p.removeMinimum();
    REQUIRE(p.getMinimum() == 9);
    p.removeMinimum();
}

TEST_CASE("Heap capacity")
{
    PriorityQueue<int> p(3);
    p.insert(3);
    p.insert(2);
    p.insert(1);
    REQUIRE(p.getSize() == 3);
    REQUIRE_THROWS(p.insert(0));
    p.removeMinimum();
    p.removeMinimum();
    p.removeMinimum();
    REQUIRE(p.getSize() == 0);
}
