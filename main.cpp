#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"
using namespace std;

int main(int argc, char *argv[]) {
    string treeType;
    string treeFile;
    ifstream treeF;
    BinaryTree<int> *treeInt;
    BinaryTree<float> *treeFloat;
    BinaryTree<string> *treeString;

    int numInt;
    float numFloat;
    string numString;

    //Checks to see if input is correct
    if (argc == 2) {
        treeFile = argv[1];
        treeF.open(treeFile, ios::in);
    } else {
        cerr << "Usage: main [treeFile]" << endl;
        exit(1);
    }

    // Checks if list file exists with list data
    if (!treeF) {
        cerr << "Error: cannot parse tree information from file" << endl;
        treeF.close();
        exit(1);
    }

    cout << "Enter list type(i - int, f - float, s - std::string): ";
    cin >> treeType;

    //Inserts items withing list depending on list type
    if (treeType.compare("i") == 0) {
        treeInt = new BinaryTree<int>();
        while (treeF >> numInt) {
            treeInt->insert(numInt);
        }
    }

    if (treeType.compare("f") == 0) {
        treeFloat= new BinaryTree<float>();
        while (treeF >> numFloat) {
            treeFloat->insert(numFloat);
        }
    }

    if (treeType.compare("s") == 0) {
        treeString = new BinaryTree<string>();
        while (treeF >> numString) {
            treeString->insert(numString);
        }
    }

    treeF.close();

    cout << "Commands:" << endl;
    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s),getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)" << endl;

    //while loop for commands
    bool quitL = false;
    char command;
    while(!quitL) {
        cout << "Enter a command: ";
        cin >> command;
        switch(command) {
        case 'i': {
            cout << "Item to insert: ";
            if (treeType.compare("i") == 0) {
                cin >> numInt;
                treeInt->insert(numInt);
                cout << "In-order: ";
                treeInt->inOrder();
                cout << "" << endl;
            }
            if (treeType.compare("f") == 0) {
                cin >> numFloat;
                treeFloat->insert(numFloat);
                cout << "In-order: ";
                treeFloat->inOrder();
                cout << "" << endl;
            }
            if (treeType.compare("s") == 0) {
                cin >> numString;
                treeString->insert(numString);
                cout << "In-order: ";
                treeString->inOrder();
                cout << "" << endl;
            }
        }
            break;
        case 'd': {
            cout << "Item to delete: ";
            if (treeType.compare("i") == 0) {
                cin >> numInt;
                treeInt->deleteItem(numInt);
                cout << "In-order: ";
                treeInt->inOrder();
                cout << "" << endl;
            }
            if (treeType.compare("f") == 0) {
                cin >> numFloat;
                treeFloat->deleteItem(numFloat);
                cout << "In-order: ";
                treeFloat->inOrder();
                cout << "" << endl;
            }
            if (treeType.compare("s") == 0) {
                cin >> numString;
                treeString->deleteItem(numString);
                cout << "In-order: ";
                treeString->inOrder();
                cout << "" << endl;
            }
        }
            break;
        case 'r': {
            cout << "Item to be retrieved: ";
            bool found;
            if (treeType.compare("i") == 0) {
                cin >> numInt;
                treeInt->retrieve(numInt, found);
            }
            if (treeType.compare("f") == 0) {
                cin >> numFloat;
                treeFloat->retrieve(numFloat, found);
            }
            if (treeType.compare("s") == 0) {
                cin >> numString;
                treeString->retrieve(numString, found);
            }
        }
            break;
        case 'l': {
            cout << "Tree Length: ";
            if (treeType.compare("i") == 0) {
                cout << treeInt->getLength() << endl;
            }
            if (treeType.compare("f") == 0) {
                cout << treeFloat->getLength() << endl;
            }
            if (treeType.compare("s") == 0) {
                cout << treeString->getLength() << endl;
            }
        }
            break;
        case 'n': {
            if (treeType.compare("i") == 0) {
                cout << "In-order: ";
                treeInt->inOrder();
                cout << "" << endl;
            }
            if (treeType.compare("f") == 0) {
                cout << "In-order: ";
                treeFloat->inOrder();
                cout << "" << endl;
            }
            if (treeType.compare("s") == 0) {
                cout << "In-order: ";
                treeString->inOrder();
                cout << "" << endl;
            }
        }
            break;
        case 'p': {
            if (treeType.compare("i") == 0) {
                cout << "Pre-order: ";
                treeInt->preOrder();
                cout << "" << endl;
            }
            if (treeType.compare("f") == 0) {
                cout << "Pre-order: ";
                treeFloat->preOrder();
                cout << "" << endl;
            }
            if (treeType.compare("s") == 0) {
                cout << "Pre-order: ";
                treeString->preOrder();
                cout << "" << endl;
            }
        }
            break;
        case 'o': {
            if (treeType.compare("i") == 0) {
                cout << "Post-order: ";
                treeInt->postOrder();
                cout << "" << endl;
            }
            if (treeType.compare("f") == 0) {
                cout << "Post-order: ";
                treeFloat->postOrder();
                cout << "" << endl;
            }
            if (treeType.compare("s") == 0) {
                cout << "Post-order: ";
                treeString->postOrder();
                cout << "" << endl;
            }
        }
            break;
        case 's': {
            cout << "Number of Single Parents: ";
            if (treeType.compare("i") == 0) {
                cout << treeInt->getNumSingleParent() << endl;
            }
            if (treeType.compare("f") == 0) {
                cout << treeFloat->getNumSingleParent() << endl;
            }
            if (treeType.compare("s") == 0) {
                cout << treeString->getNumSingleParent() << endl;
            }
        }
            break;

            case 'f': {
            cout << "Number of leaf nodes: ";
            if (treeType.compare("i") == 0) {
                cout << treeInt->getNumLeafNodes() << endl;
            }
            if (treeType.compare("f") == 0) {
                cout << treeFloat->getNumLeafNodes() << endl;
            }
            if (treeType.compare("s") == 0) {
                cout << treeString->getNumLeafNodes() << endl;
            }
        }
            break;
            case 't': {
                cout << "Item to get sum of subtrees: ";
                if (treeType.compare("i") == 0) {
                    cin >> numInt;
                    int numInt2 = treeInt->getSumOfSubTrees(numInt);
                    if (treeInt->sumT == true) {
                        cout << "Sum of Subtrees: " << numInt2  << endl;
                    } else {
                        cout << "Item not in tree." << endl;
                    }
                }
                if (treeType.compare("f") == 0) {
                    cin >> numFloat;
                    float numFloat2 = treeFloat->getSumOfSubTrees(numFloat);
                    if (treeFloat->sumT == true) {
                        cout << "Sum of Subtrees: " << numFloat2  << endl;
                    } else {
                        cout << "Item not in tree." << endl;
                    }
                }
                if (treeType.compare("s") == 0) {
                    cin >> numString;
                    string numString2 = treeString->getSumOfSubTrees(numString);
                    if (treeString->sumT == true) {
                        cout << "Sum of Subtrees: " << numString2  << endl;
                    } else {
                        cout << "Item not in tree." << endl;
                    }
                }
            }
                break;
        case 'q': {
            cout << "Quitting program..." << endl;
            quitL = true;
        }
            break;
        default: {
            cout << "Command not recognized. Try again" << endl;
        }

        }
    }




    return 0;
}
