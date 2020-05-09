#include <iostream>
#include <vector>
using namespace std;

struct node
{
    vector<int> index;
    int document_number;
    string word;
    node *left;
    node *right;
};

class BST
{

private:
    node *root;

    void addleafprivate(int document_number, string word, node *ptr)
    {
        if (root == NULL)
        {

            root = createleaf(document_number, word);
        }
        else if (word < ptr->word)
        {
            if (ptr->left != NULL)
            {
                addleafprivate(document_number, word, ptr->left);
            }
            else
            {
                ptr->left = createleaf(document_number, word);
            }
        }
        else if (word > ptr->word)
        {
            if (ptr->right != NULL)
            {
                addleafprivate(document_number, word, ptr->right);
            }
            else
            {
                ptr->right = createleaf(document_number, word);
            }
        }
        else if (word == ptr->word)
        {
            if (document_number != ptr->index.back())
            {
                ptr->index.push_back(document_number);
                cout << word;
                cout << ptr->index.back() << endl;
            }
        }
    }

public:
    BST() { root = NULL; }
    node *createleaf(int document_number, string word)
    {
        node *n = new node;
        n->index.push_back(document_number);
        n->word = word;
        n->left = n->right = NULL;
        cout << n->word;

        for (int i = 0; i < n->index.size(); i++)
        {
            cout << n->index[i];
        }
        cout << endl;
        return n;
    }
    void addleaf(int document_number, string word)
    {
        addleafprivate(document_number, word, root);
    }

    bool search(string word, vector<int> &document)
    {
        node *current;
        current = root;
        while (current != NULL)
        {
            if (current->word == word)
            {
                document = current->index;
                return true;
            }
            else if (word < current->word)
            {
                current = current->left;
            }
            else if (word > current->word)
            {
                current = current->right;
            }
        }
        return false;
    }
};
int main()
{
    BST tree;
    vector<int> index;
    tree.addleaf(2, "yara");
    tree.addleaf(5, "aya");
    tree.addleaf(3, "yara");
    tree.addleaf(4, "aya");
    tree.addleaf(3, "hi");

    if (tree.search("yara", index))
    {

        for (int i = 0; i < index.size(); i++)
        {
            cout << index[i] << " ";
        }
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }
    return 0;
}