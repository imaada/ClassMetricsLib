#include <iostream>
#include "Classification/classification.hpp"
#include "vector"

int main() {

    std::vector<std::vector<int> > GT { { 1, 0 },
                                         { 0, 0 } };

    std::vector<std::vector<int> > PR { { 1, 1 },
                                         { 1, 1 } };

    InputVectors i(GT, PR);

    std::vector<std::vector<int> > vec = i.getConfustionMatrix();

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j];
        }
        std::cout << std::endl;
    }

    return 0;

}
