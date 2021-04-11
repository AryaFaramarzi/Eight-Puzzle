#include "../header/Node.h"
#include "../header/Search.h"
using namespace std;
int main()
{
    vector<vector<char>> board = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '*', '8'},
    };
    Node *root = new Node(board, nullptr);
    Search *search = new Search(root);
    search->UniformCostSearch();
    
}
