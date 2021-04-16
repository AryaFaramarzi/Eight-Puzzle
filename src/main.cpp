#include "../header/Node.h"
#include "../header/Search.h"
using namespace std;
int main()
{
    // doable board
    vector<vector<char>> board1 = {
        // normal:
        {'0', '1', '2'}, // up:
        {'4', '5', '3'}, // left:
        {'7', '8', '6'}, // right:
    };

    // OH BOY
    vector<vector<char>> board2 = {
        // normal:
        {'8', '7', '1'}, // up:
        {'6', '0', '2'}, // left:
        {'5', '4', '3'}, // right:
    };

    Node *root = new Node(board1, nullptr, 0);
    Search *search = new Search(root);
    search->UniformCostSearch();
    std::cout << "Total number of nodes generated is: " << search->getNodes() << std::endl;
}
