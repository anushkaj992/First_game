#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void drawMaze(const std::vector<std::string>& maze) {
    std::system("cls");
    for (int row = 0; row < maze.size(); row++) {
        std::cout << maze[row] << '\n';
    }
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

    drawMaze(maze);
    std::cout << "Collect all dots (*) using n e s w. Press Q to quit.\n";
    std::cout << "Score: " << score << " / " << totalDots << "\n";

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
            drawMaze(maze);
            std::cout << "Cannot move outside the maze! Use n e s w.\n";
            std::cout << "Score: " << score << " / " << totalDots << "\n";
            continue;
        }

        if (maze[nextRow][nextCol] == '|') {
            drawMaze(maze);
            std::cout << "Hit a wall! Use n e s w.\n";
            std::cout << "Score: " << score << " / " << totalDots << "\n";
            continue;
        }

        if (maze[nextRow][nextCol] == '*') {
            score++;
        }

        maze[playerRow][playerCol] = ' ';
        playerRow = nextRow;
        playerCol = nextCol;
        maze[playerRow][playerCol] = 'P';

        drawMaze(maze);
        std::cout << "Collect all dots (*) using n e s w. Press Q to quit.\n";
        std::cout << "Score: " << score << " / " << totalDots << "\n";

        if (score == totalDots) {
            std::cout << "You win! All dots collected.\n";
            break;
        }
    }

    return 0;
}
