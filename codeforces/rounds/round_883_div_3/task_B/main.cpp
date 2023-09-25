#include <iostream>
#include <string>
#include <array>
#include <algorithm>


std::string solve(std::array<std::string, 3> const &);


int main(void) {
    int t;
    std::cin >> t;

    std::array<std::string, 3> grid;
    std::getline(std::cin, grid[0]);
    for (int i = 0; i < t; ++i) {
        for (int i = 0; i < 3; ++i)
            std::getline(std::cin, grid[i]);
            std::cout << solve(grid) << "\n";
    }

    return 0;
}


std::array<std::string, 3> rows = { { "XXX", "OOO", "+++" } };

std::string solve(std::array<std::string, 3> const & grid) {
    for (int i = 0; i < 3; ++i) {
        if (std::find(rows.begin(), rows.end(), grid[i]) != rows.end())
            return std::string(1, grid[i][0]);
        
        std::string col = std::string(1, grid[0][i]) + \
            std::string(1, grid[1][i]) + std::string(1, grid[2][i]);
        if (std::find(rows.begin(), rows.end(), col) != rows.end())
            return std::string(1, col[0]);
    }

    std::string diag = std::string(1, grid[0][0]) + \
        std::string(1, grid[1][1]) + std::string(1, grid[2][2]);
    if (std::find(rows.begin(), rows.end(), diag) != rows.end())
        return std::string(1, diag[0]);
    diag[0] = grid[0][2]; diag[2] = grid[2][0];
    if (std::find(rows.begin(), rows.end(), diag) != rows.end())
        return std::string(1, diag[0]);

    return "DRAW";
}
