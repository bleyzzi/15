#include "game_log.h"
#include "gamewindow.h"
Game::Game(){
    start();
}

void Game::start(){
    v.clear();
    v_res.clear();
    moves = 0;
    for(int i = 1; i < 16; i++){
       v.push_back(i);
    }
    int k = 0;
    std::random_device rd;
    std::mt19937 g(time(NULL));
    std::shuffle(v.begin(), v.end(), g);
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(i*j != 9){
            table[i][j] = v[k];
            v_res.push_back(v[k]);
            k++;
            }
            else table[i][j] = 16;
        }
    }
    v.push_back(16);
    v_res.push_back(16);
}

void Game::restart(){
    v.clear();
    int k = 0;
    moves = 0;
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(i*j != 9){
            v.push_back(v_res[k]);
            table[i][j] = v_res[k];
            k++;
            }
            else {table[i][j] = 16; v.push_back(16);}
        }
    }
}

bool Game::isSolve(){
    int inv=0;
    for(int i = 0; i < 15; i++){
        if(v[i] ){
            for (int j = 0; j < i; j++){
                if(v[j] > v[i]) inv++;
            }
        }
    }
    for (int i = 0; i< 15; i++){
        if(v[i] == 0){
            inv += 1 + i/4;
        }
    }
    if (inv & 1){
        v.clear();
        return false;
    }

    else {return true;}
}

int Game::getItem(int i){
    return v[i];
}

void Game::move(int row, int column){
    int dx = 0;
    int dy = 0;
    if(row != 3 && table[row + 1][column] == 16){dx = 1; dy = 0;}
    else if(column != 3 && table[row][column + 1] == 16){dx = 0; dy = 1;}
    else if(column != 0 && table[row][column - 1] == 16){dx = 0; dy = -1;}
    else if(row != 0 && table[row - 1][column] == 16){dx = -1; dy = 0;}

    int temp = table[row][column];
    table[row][column] = 16;
    table[row + dx][column + dy] = temp;
    int k = 0;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            v[k] = table[i][j];
            k++;
        }
    }
    if(dx > 0 || dy > 0){
        moves++;
    }
}

bool Game::isFinished(){
    int k = 0;
    for(int i  = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (v[k] != table_true[i][j]){
                return false;
            }
        k++;
        }
    }
    v.clear();
    return true;
}

