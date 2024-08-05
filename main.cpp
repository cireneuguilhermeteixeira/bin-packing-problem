#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <algorithm>

class BinPacking {
public:
    int firstFit(std::vector<int> &items, int binCapacity) {
        std::vector<int> bins;
        for (int item : items) {
            bool placed = false;
            for (int &bin : bins) {
                if (bin + item <= binCapacity) {
                    bin += item;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                bins.push_back(item);
            }
        }
        return bins.size();
    }

    int bestFit(std::vector<int> &items, int binCapacity) {
        std::vector<int> bins;
        for (int item : items) {
            int bestIndex = -1;
            int minSpaceLeft = binCapacity + 1;
            for (int i = 0; i < bins.size(); i++) {
                int spaceLeft = binCapacity - bins[i];
                if (spaceLeft >= item && spaceLeft < minSpaceLeft) {
                    bestIndex = i;
                    minSpaceLeft = spaceLeft;
                }
            }
            if (bestIndex == -1) {
                bins.push_back(item);
            } else {
                bins[bestIndex] += item;
            }
        }
        return bins.size();
    }

    int firstFitDecreasing(std::vector<int> items, int binCapacity) {
        std::sort(items.begin(), items.end(), std::greater<int>());
        return firstFit(items, binCapacity);
    }

    int bestFitDecreasing(std::vector<int> items, int binCapacity) {
        std::sort(items.begin(), items.end(), std::greater<int>());
        return bestFit(items, binCapacity);
    }
};

