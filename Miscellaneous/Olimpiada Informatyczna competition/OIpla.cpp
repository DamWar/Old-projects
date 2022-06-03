#include <iostream>
#include <vector>

//task I completed for internship recruitment

int main()
{
    std::ios::sync_with_stdio(false);
    int n, di, wi, notRedundant, wiVecSize = 0;
    bool redundant;
    std::vector<int> wiVec;
    std::cin >> n;
    notRedundant = n;
    for (int i = 0; i < n ; ++i) {
        std::cin >> di;
        std::cin >> wi;
        
        if (wiVecSize > 0) {
            while ((wiVecSize > 0) && (wi < wiVec.back())) {
                wiVec.pop_back();
                --wiVecSize;
            }
            if (wi > wiVec.back()) {
                wiVec.push_back(wi);
                ++wiVecSize;
                continue;
            }
            if (wi == wiVec.back()) {
                --notRedundant;
            }
        }
        else {
            wiVec.push_back(wi);
            ++wiVecSize;
        }
    }
    std::cout << notRedundant;

    return 0;
}