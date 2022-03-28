#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void NotSolve();
    void Timer();
    void STimer();
private slots:
    void on_TableGame_cellClicked(int row, int column);

    void on_NewGame_clicked();

    void on_Restart_clicked();

    void UpTimer();
private:
    QTimer *timer;
    int seconds;
    int minutes;
    Ui::GameWindow *ui;
    void TableShow();
};
#endif // GAMEWINDOW_H
