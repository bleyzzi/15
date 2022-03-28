#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "game_log.h"

Game g;
bool check = true;
GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    NotSolve();
    Timer();
    TableShow();
    if(!check) {
        exit(0);
    }
    }

void GameWindow::TableShow(){
    int k = 0;
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(g.getItem(k)!=16){
            ui->TableGame->setItem(i, j, new QTableWidgetItem(QString::number(g.getItem(k))));
            }
            else ui->TableGame->setItem(i, j, new QTableWidgetItem());
            k++;
        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_TableGame_cellClicked(int row, int column)
{
    g.move(row, column);
    ui -> Moves -> setText(QString::number(g.moves));
    if(g.isFinished()){
        if (QMessageBox::question(this, "Игра закончена!", "Победа! Желаете сыграть снова?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
                    QApplication::quit();
        else{
            STimer();
            g.start();
            TableShow();
            NotSolve();
            Timer();
        }
    }
    TableShow();
}

void GameWindow::NotSolve(){
    while(!g.isSolve()){
        QMessageBox msgBox;
        msgBox.setText("Игра не может быть собрана");
        QPushButton *exitButton = msgBox.addButton(tr("Выйти"), QMessageBox::ActionRole);
        QPushButton *restartButton = msgBox.addButton(tr("Новая игра"), QMessageBox::ActionRole);
        msgBox.exec();
        if(msgBox.clickedButton() == exitButton){
            QApplication::quit();
            check = false;
            break;
        }
        else if(msgBox.clickedButton() == restartButton){
            g.start();
            TableShow();
        }
    }
}

void GameWindow::on_NewGame_clicked()
{
    STimer();
    g.start();
    ui -> Moves -> setText(QString::number(g.moves));
    NotSolve();
    Timer();
    TableShow();
}

void GameWindow::on_Restart_clicked()
{
    STimer();
    g.restart();
    ui -> Moves -> setText(QString::number(g.moves));
    NotSolve();
    Timer();
    TableShow();
}

void GameWindow::Timer(){
    ui->Timer->setText("00");
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(UpTimer()));
    timer->start(1000);
    seconds = 0;
}

void GameWindow::UpTimer(){
    seconds++;
    ui -> Timer -> setText(QString::number(seconds));
}

void GameWindow::STimer(){
    timer->stop();
    seconds = 0;
}


