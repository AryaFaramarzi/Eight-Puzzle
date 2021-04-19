#include "../header/Node.h"
#include "../header/Search.h"
#include <ctime>

using namespace std;
int main()
{
    std::clock_t start;
    double duration;

    start = std::clock();
    // doable board
    std::cout << " Welcome to afara027 and ezhu010 8 puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << std::endl;
    int choice;
    std::cin >> choice;
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '0'));
    if (choice == 1)
    {
        // DOABLE !!
        board = {{'1', '2', '3'},
                 {'4', '5', '6'},
                 {'8', '7', '0'}};
    }

    else
    {
        std::vector<char> row(3, '0');
        std::cout << "Enter your puzzle, use a zero to represent the blank ..." << std::endl;

        std::cout << "Enter the first row, use space or tabs between numbers\t";
        cin >> row[0] >> row[1] >> row[2];
        board[0] = row;

        std::cout << "\nEnter the second row, use space or tabs between numbers\t";
        cin >> row[0] >> row[1] >> row[2];
        board[1] = row;

        std::cout << "\nEnter the third row, use space or tabs between numbers\t";
        cin >> row[0] >> row[1] >> row[2];
        board[2] = row;
    }

    Node *root = new Node(board, nullptr, 0);
    Search *search = new Search(root);

    std::cout << "Enter your choice of algorithm" << std::endl;
    std::cout << "Uniform Cost Search (1)" << std::endl;
    std::cout << "A* with the misplaced Tile heuristic (2)" << std::endl;
    std::cout << "A* with the Eucledian distance heuristic (3)" << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        search->UniformCostSearch();
        std::cout << "Total number of nodes generated is: " << search->getNodes() << std::endl;
        break;
    case 2:
        search->MisplacedTilesSearch();
        std::cout << "Total number of nodes generated is: " << search->getNodes() << std::endl;
        break;
    case 3:
        search->EucledianDistanceSearch();
        std::cout << "Total number of nodes generated is: " << search->getNodes() << std::endl;
        break;
    }

    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    std::cout << "Duration: " << duration << '\n';
}
