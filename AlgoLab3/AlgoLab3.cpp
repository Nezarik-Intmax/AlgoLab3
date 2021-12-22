#include <iostream>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#define N 23
const int t = N * 1.5;
using namespace std;
void goXY(int x, int y){
    COORD position;										// Объявление необходимой структуры
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
    position.X = x;									    // Установка координаты X
    position.Y = y;									    // Установка координаты Y
    SetConsoleCursorPosition(hConsole, position);
}
void randInput(int* arr){
    //srand(time(NULL));
    for(int i = 0; i < N; i++){
        bool stop = false;
        while(!stop){
            stop = true;
            arr[i] = rand() % 9000 + 1000;
            for(int j = 0; j < i; j++){
                if(arr[i] == arr[j]){
                    stop = false;
                    break;
                }
            }
        }
    }
}
void show(int* arr, int size = N){
    for(int i = 0; i < size; i++){
        cout << arr[i] << "   ";
    }
    cout << endl << endl;
}
class NodeTree{
private:
    NodeTree* left;
    NodeTree* right;
    int value;
public:
    NodeTree(){
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    NodeTree(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
    void addChild(int value){
        if(value > this->value)
            if(right==nullptr)
                right = new NodeTree(value);
            else
                right->addChild(value);
        else if(value < this->value)
            if(left==nullptr)
                left = new NodeTree(value);
            else
                left->addChild(value);
    }
    void showTree(NodeTree* t, const int level = 0, const int x = 0){
        if(t->left != nullptr)
            showTree(t->left, level + 1, x - 10);
        /*for(int i = 0; i < level; i++)
            std::cout << "      ";*/
        goXY(160/(pow(2, level)+1), level+5);
        std::cout << t->value;
        if(t->right != nullptr)
            showTree(t->right, level + 1, x + 10);
    }
};

int main(){
    int a[N];
    randInput(a);
    //int a[7] = {5, 7, 9, 4, 2, 3, 9};
    show(a);
    NodeTree* tree = new NodeTree(a[0]);
    for(int i = 1; i < N; i++){
        tree->addChild(a[i]);
    }
    tree->showTree(tree, 0, 40);
    goXY(0, 30);
}