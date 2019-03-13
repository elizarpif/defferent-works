#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QStack>
#include <stack>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setScene(QGraphicsScene *scene, QGraphicsView *view);

    void setColotSelect(bool clicked, int cur, int current_scene);

    void Constructor();

    bool CheckWrong(int a, int b);

private slots:

    void on_sel1_clicked();

    void on_sel1_clicked(bool checked);

    void on_push2_clicked();

    void on_push3_clicked();

    void on_sel2_clicked();

    void on_sel3_clicked();

    void on_push1_clicked();

    void on_help_clicked();



private:

    Ui::MainWindow *ui;
    int count;
    QGraphicsScene *scene1, *scene2, *scene3;
    QBrush br;
    QPen p;
    QGraphicsRectItem *mas[8];
    QColor mascol[8] = {Qt::darkRed, Qt::blue, Qt::darkBlue, Qt::darkCyan,
                        Qt::darkMagenta, Qt::darkGreen,
                       Qt::darkYellow,  Qt::gray};
    int current;
    int count1, count2, count3;
    bool cl[3] = {false, false, false};
    QStack<int> v1, v2, v3;
    QString temp;
};

#endif // MAINWINDOW_H
