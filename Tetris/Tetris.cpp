#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <ctime>
using namespace std;



struct Shape {
    vector<vector<int>> blocks;
    int x, y; // позиція на полі

    Shape() : x(3), y(0) {}

    //генерація фігур
    void generateRandom() {
        static vector<vector<vector<int>>> shapes = {
            {{1,1,1,1}},               // I
            {{0,1},{0,1},{0,1},{0,1}}, // I^
            {{1,1},{1,1}},             // O
            {{0,1,0},{0,1,1}, {0,1,0}},// T>
            {{0,1,0},{1,1,0}, {0,1,0}},// T<
            {{1,1,1},{0,1,0}},         // T (down)
            {{0,1,0},{1,1,1}},         // T^
            {{1,0,0},{1,1,1}},         // J
            {{0,0,1},{1,1,1}},         // L
            {{0,1,1},{1,1,0}},         // S
            {{1,1,0},{0,1,1}}          // Z
        };
        int index = rand() % shapes.size();
        blocks = shapes[index];
        x = 3;
        y = 0;
    }
};


class Matrix {
private:
    int width, height;
    int score;
    int gameSpeed; // мілісекунд між кроками падіння
    vector<vector<int>> field;
    Shape cShape;
    bool gameOver;
public:
    Matrix(int w= 10, int h=20, int gs = 300, bool go = false): width(w), height(h), gameSpeed(gs), score(0), gameOver(go)
    {
        srand((unsigned)time(nullptr)); 
        field.assign(height, vector<int>(width, 0));
        cShape.generateRandom();
    }
    //показ кадру
    void fill() {
        system("cls"); 
        
        

        for (int j = 0; j < height; ++j) {
            cout << "|";
            for (int i = 0; i < width; ++i) {
                bool isShapeBlock = false;
                for (int k = 0; k < 4; ++k) {
                    if (cShape.blocks[k][0] == i && cShape.blocks[k][1] == j) {
                        isShapeBlock = true;
                        break;
                    }
                }
                if (isShapeBlock) {
                    cout << "[]";
                    }
                }
                if (partOfShape)
                    cout << "*";
                else
                   cout << (field[y][x] ? "*": " ");
            }
            cout << "\n";
        }
        cout << "score: " << score << std::endl;
    }
    //перевірка вдару
    bool checkCollision(int dx, int dy) {
        for (int y = 0; y < (int)cShape.blocks.size(); ++y) {
            for (int x = 0; x < (int)cShape.blocks[y].size(); ++x) {
                if (cShape.blocks[y][x]) {
                    int newX = cShape.x + x + dx;
                    int newY = cShape.y + y + dy;
                    if (newX < 0 || newX >= width || newY >= height)
                        return true;
                    if (newY >= 0 && field[newY][newX])
                        return true;
                }
            }
        }
        return false;
    }
    //стоп фігури
    void mergeShape() {
        for (int y = 0; y < (int)cShape.blocks.size(); ++y) {
            for (int x = 0; x < (int)cShape.blocks[y].size(); ++x) {
                if (cShape.blocks[y][x]) {
                    int fx = cShape.x + x;
                    int fy = cShape.y + y;
                    if (fy >= 0 && fy < height && fx >= 0 && fx < width)
                        field[fy][fx] = 1;
                }
            }
        }
    }
    //перевірка повної лініхї
    void checkFullLines() {
        for (int y = height - 1; y >= 0; --y) {
            bool full = true;
            for (int x = 0; x < width; ++x)
                if (field[y][x] == 0) { full = false; break; }

            if (full) {
                field.erase(field.begin() + y);
                field.insert(field.begin(), std::vector<int>(width, 0));
                score += 100;
                y++;
            }
        }
    }
    //перевірка переповнення
    void checkOverflow() {
        for (int i = 0; i < width; ++i) {
            if (field[0][i] != 0) {
                gameOver = true;
                break;
            }
        }
    }
    //падіння
    bool fall() {
        if (!checkCollision(0, 1)) {
            cShape.y++;
            return true;
        }
        else {
            mergeShape();
            checkFullLines();
            cShape.generateRandom();
            return false;
        }
    }
    //ріх фігур
    void move(char dir) {
        if (dir == 'L' && !checkCollision(-1, 0)) cShape.x--;
        else if (dir == 'R' && !checkCollision(1, 0)) cShape.x++;
        else if (dir == 'D' && !checkCollision(0, 1)) cShape.y++;
    }
    //цикл
    void run() {
        while (!gameOver) {
            int key;
            if (_kbhit())
            {
                key = _getch();
                if (key == 224)
                {
                    key = _getch();
                    if (key == 75) move('L'); // ←
                    else if (key == 77) move('R'); // →
                    else if (key == 80) move('D'); // ↓
                }
            }
            fall();
            fill();
            Sleep(gameSpeed);
            
        }
    }
};


int main()
{
    Matrix game(10, 20, 700);
    game.run();
}

