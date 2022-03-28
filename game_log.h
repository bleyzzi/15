#ifndef GAME_LOG_H
#define GAME_LOG_H
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Game{
public:
    Game();
    void start();
    bool isSolve();
    int getItem(int i);
    void restart();
    bool isFinished();
    void move(int row, int column);
    int moves;
private:
    std::vector <int> v;
    std::vector <int> v_res;
    int table[4][4];
    int table_true[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
};
#endif // GAME_LOG_H
