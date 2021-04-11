#include "../header/Node.h"
#include "../header/Search.h"
using namespace std;
int main()
{
    vector<vector<char>> board = {
        {'0', '1', '3'},
        {'4', '2', '5'},
        {'7', '8', '6'},
    };
    Node *root = new Node(board, nullptr, 0);
    Search *search = new Search(root);
    search->UniformCostSearch();
}
