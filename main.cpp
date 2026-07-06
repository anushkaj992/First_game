#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>

void drawMaze(const std::vector<std::string>& maze, int score, int totalDots) {
    std::cout << "\n=== Tiny Pac-Man ===\n";
    for (int row = 0; row < maze.size(); row++) {
        std::cout << maze[row] << '\n';
    }
    std::cout << "Use n e s w. Press q to quit.\n";
    std::cout << "Score: " << score << " / " << totalDots << "\n";
    std::cout.flush();
}

int main() {
    std::vector<std::string> maze = {
     "****|**|*|***",
     "**|***|*|**|*",
     "|***|*|P*|***",
     "**|*****|***|"
    };

    int playerRow = 2 ;
    int playerCol = 7;
    int score = 0;
    int totalDots = 0;

    for (const auto& row : maze) {
        for (char ch : row) {
            if (ch == '*') totalDots++;
        }
    }

    drawMaze(maze, score, totalDots);

    while (true) {
        char move;
        std::cin >> move;
        move = std::tolower(move);
        if (move == 'q') {
            std::cout << "Goodbye!\n";
            break;
        }

        int nextRow = playerRow;
        int nextCol = playerCol;
        if (move == 'n') nextRow--;
        else if (move == 's') nextRow++;
        else if (move == 'w') nextCol--;
        else if (move == 'e') nextCol++;
        else continue;

        if (nextRow < 0 || nextRow >= maze.size() || nextCol < 0 || nextCol >= maze[nextRow].size()) {
            drawMaze(maze, score, totalDots);
            std::cout << "Cannot move outside the maze! Use n e s w.\n";
            continue;
        }

        if (maze[nextRow][nextCol] == '|') {
            drawMaze(maze, score, totalDots);
            std::cout << "Hit a wall! Use n e s w.\n";
            continue;
        }

        if (maze[nextRow][nextCol] == '*') {
            score++;
        }

        maze[playerRow][playerCol] = ' ';
        playerRow = nextRow;
        playerCol = nextCol;
        maze[playerRow][playerCol] = 'P';

        drawMaze(maze, score, totalDots);

        if (score == totalDots) {
            std::cout << "You win! All dots collected.\n";
            break;
        }
    }

    return 0;
}
