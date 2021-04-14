#include "../header/Node.h"
#include "../header/Search.h"
using namespace std;
int main()
{
    vector<vector<char>> board = {
        // normal:
        {'8', '7', '1'}, // up:
        {'6', '0', '2'}, // left:
        {'5', '4', '3'}, // right:

    };
    Node *root = new Node(board, nullptr, 0);
    Search *search = new Search(root);
    search->UniformCostSearch();
}
