TEST_CASE("Bin Packing Algorithms", "[bin_packing]") {
    BinPacking bp;
    std::vector<int> items = {4, 3, 4, 1, 2};
    int binCapacity = 5;

    SECTION("First-Fit") {
        REQUIRE(bp.firstFit(items, binCapacity) == 3);
    }

    SECTION("Best-Fit") {
        REQUIRE(bp.bestFit(items, binCapacity) == 3);
    }

    SECTION("First-Fit Decreasing") {
        REQUIRE(bp.firstFitDecreasing(items, binCapacity) == 3);
    }

    SECTION("Best-Fit Decreasing") {
        REQUIRE(bp.bestFitDecreasing(items, binCapacity) == 3);
    }

    SECTION("Edge Case: Large Item") {
        std::vector<int> itemsWithLarge = {5, 1, 2, 3};
        REQUIRE(bp.firstFit(itemsWithLarge, binCapacity) == 3);
        REQUIRE(bp.bestFit(itemsWithLarge, binCapacity) == 3);
        REQUIRE(bp.firstFitDecreasing(itemsWithLarge, binCapacity) == 3);
        REQUIRE(bp.bestFitDecreasing(itemsWithLarge, binCapacity) == 3);
    }

    SECTION("Edge Case: All items fit perfectly") {
        std::vector<int> perfectFitItems = {5, 5, 5};
        REQUIRE(bp.firstFit(perfectFitItems, binCapacity) == 3);
        REQUIRE(bp.bestFit(perfectFitItems, binCapacity) == 3);
        REQUIRE(bp.firstFitDecreasing(perfectFitItems, binCapacity) == 3);
        REQUIRE(bp.bestFitDecreasing(perfectFitItems, binCapacity) == 3);
    }

    SECTION("Edge Case: Single Item") {
        std::vector<int> singleItem = {5};
        REQUIRE(bp.firstFit(singleItem, binCapacity) == 1);
        REQUIRE(bp.bestFit(singleItem, binCapacity) == 1);
        REQUIRE(bp.firstFitDecreasing(singleItem, binCapacity) == 1);
        REQUIRE(bp.bestFitDecreasing(singleItem, binCapacity) == 1);
    }

    SECTION("Edge Case: No Items") {
        std::vector<int> noItems;
        REQUIRE(bp.firstFit(noItems, binCapacity) == 0);
        REQUIRE(bp.bestFit(noItems, binCapacity) == 0);
        REQUIRE(bp.firstFitDecreasing(noItems, binCapacity) == 0);
        REQUIRE(bp.bestFitDecreasing(noItems, binCapacity) == 0);
    }
}