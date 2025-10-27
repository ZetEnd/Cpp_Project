// ALGOSSS_LetsGooo_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct tnode {
    int field;
    struct tnode* left;

    struct tnode *right;
};

struct tnode* addnode(int x, tnode* tree) {

    if (tree == NULL) {

        tree = new tnode;
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else {
        if (x < tree->field) {

            tree->left = addnode(x, tree->left);
        }
        else {
            tree->right = addnode(x, tree->right);
        }
    }

    return tree;
};

void freemem(tnode* tree) {


    if (tree != NULL) {
        freemem(tree->left);
        freemem(tree->right);

        delete tree;
    }
}
void treeprint(tnode* tree) {

    if (tree != NULL) {

        std::cout << tree->field;

        treeprint(tree->left);
        treeprint(tree->right);
    }
};

void treeprint1(tnode* tree) {

    if (tree != NULL) {
        treeprint1(tree->left);
        std::cout << tree->field;
        treeprint1(tree->right);

    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
