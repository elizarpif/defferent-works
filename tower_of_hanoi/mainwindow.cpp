#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QHBoxLayout>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->help_action, SIGNAL(triggered()), this, SLOT(on_help_clicked()));
    connect(ui->action, SIGNAL(triggered()), this, SLOT(on_rebuld_clicked()));

    Constructor();


}

void MainWindow::Constructor()
{

    //weight 156
    //height 161

    scene1 = new QGraphicsScene();
    scene1->setSceneRect(0,0,this->width()-460,this->height()-250);
    ui->view1->setScene(scene1);

    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,this->width()-460,this->height()-250);
    ui->view2->setScene(scene2);

    scene3 = new QGraphicsScene();
    scene3->setSceneRect(0,0,this->width()-460,this->height()-250);
    ui->view3->setScene(scene3);

    br.setColor(Qt::white);
    br.setStyle(Qt::SolidPattern);

    p.setColor(Qt::white);

    scene1->addRect(0,0,156,161, p, br);
    p.setColor(Qt::black);
    p.setWidth(2);
    for (int i=0; i<8; i++){
        mas[i] = new QGraphicsRectItem;
        mas[i]->setRect(55-i*5,0+i*20,50+10*i,20);
        mas[i]->setPen(p);
        br.setColor(mascol[i]);
        mas[i]->setBrush(br);
        v1.push(7-i);
        scene1->addItem(mas[i]);
    }
    count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::CheckWrong(int top, int bottom)
{
    if (top>bottom)
        return false;
    return true;
}


void MainWindow::on_push2_clicked()
{
    switch(current){
    case 1:{ //1 -> 2
        if (v2.count() != 0 && v1.count()!=0){

            bool isRight = CheckWrong(v1.top(), v2.top());
            if (!isRight) break;
        }
        v2.push(v1.pop());
        int k = v2.top();
        scene1->removeItem(mas[k]);
        scene2->addItem(mas[k]);
        count1=v1.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count2-1),50+10*k,20);
        current = 0;
        cl[0] = !cl[0];
        setColotSelect(cl[0], v2.top(), current);
        ui->count->setText(temp.number(++count));
        break;
    }
    case 3: //3 -> 2
        if (v2.count() != 0 && v3.count()!=0){

            bool isRight = CheckWrong(v3.top(), v2.top());
            if (!isRight) break;
        }
        v2.push(v3.pop());
        int k = v2.top();
        scene3->removeItem(mas[k]);
        scene2->addItem(mas[k]);
        count3= v3.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count2-1),50+10*k,20);
        current = 0;
        cl[2] = !cl[2];
        setColotSelect(cl[2], v2.top(), current);
        ui->count->setText(temp.number(++count));
        break;
    }
}

void MainWindow::on_push3_clicked()
{
    switch(current){
    case 1:{ //1 -> 3
        if (v1.count() != 0 && v3.count()!=0){

            bool isRight = CheckWrong(v1.top(), v3.top());
            if (!isRight) break;
        }

        v3.push(v1.pop());

        int k = v3.top();
        scene1->removeItem(mas[k]);
        scene3->addItem(mas[k]);
        count1=v1.count();
        count3 = v3.count();
        mas[k]->setRect(55-k*5,140-20*(count3-1),50+10*k,20);
        current = 0;
        cl[0] = !cl[0];
        setColotSelect(cl[0], v3.top(), current);
        ui->count->setText(temp.number(++count));
        break;
    }
    case 2: //2 -> 3

        if (v2.count() != 0 && v3.count()!=0){

            bool isRight = CheckWrong(v2.top(), v3.top());
            if (!isRight) break;
        }
        v3.push(v2.pop());
        int k = v3.top();
        scene2->removeItem(mas[k]);
        scene3->addItem(mas[k]);
        count3=v3.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count3-1),50+10*k,20);
        current = 0;
        cl[1] = !cl[1];
        setColotSelect(cl[1], v3.top(), current);
        ui->count->setText(temp.number(++count));
        break;
    }
}

void MainWindow::on_push1_clicked()
{
    switch(current){
    case 2:{ //2 -> 1

        if (v2.count() != 0 && v1.count()!=0){

            bool isRight = CheckWrong(v2.top(), v1.top());
            if (!isRight) break;
        }
        v1.push(v2.pop());

        int k = v1.top();
        scene2->removeItem(mas[k]);
        scene1->addItem(mas[k]);
        count1=v1.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count1-1),50+10*k,20);
        current = 0;
        cl[1] = !cl[1];
        setColotSelect(cl[1], v1.top(), current);

        ui->count->setText(temp.number(++count));
        break;
    }
    case 3: //3 -> 1

        if (v3.count() != 0 && v1.count()!=0){

            bool isRight = CheckWrong(v3.top(), v1.top());
            if (!isRight) break;
        }
        v1.push(v3.pop());
        int k = v1.top();
        scene3->removeItem(mas[k]);
        scene1->addItem(mas[k]);
        count1=v1.count();
        count3 = v3.count();
        mas[k]->setRect(55-k*5,140-20*(count1-1),50+10*k,20);
        current = 0;
        cl[2] = !cl[2];
        setColotSelect(cl[2], v1.top(), current);

        ui->count->setText(temp.number(++count));
        break;
    }
}

void MainWindow::on_sel1_clicked()
{

    if (v1.count()!=0){  //cur1 - текущая вершина на 1 сцене
        cl[0] = !cl[0];
        current = 1;
        setColotSelect(cl[0], v1.top(), current);
    }

}


void MainWindow::setColotSelect(bool clicked, int cur, int current_scene){
    if (clicked){
        p.setColor(Qt::red);
        mas[cur]->setPen(p);
        current = current_scene;
    }
    else{
        p.setColor(Qt::black);
        mas[cur]->setPen(p);
        current = 0;
    }
}


void MainWindow::on_sel2_clicked()
{
    if (v2.count()!=0){
        cl[1] = !cl[1];
        current = 2;
        setColotSelect(cl[1], v2.top(), current);
    }
}

void MainWindow::on_sel3_clicked()
{
    if (v3.count()!=0){  //cur1 - текущая вершина на 1 сцене
        cl[2] = !cl[2];
        current = 3;
        setColotSelect(cl[2], v3.top(), current);
    }
}


void MainWindow::on_help_clicked()
{
    qDebug()<<"yes";
    QDialog *f2 = new QDialog(this );

    QFont f;
    f.setItalic(true);
    f.setWeight(12);
    f.setFamily("Comic Sans MS");

    QTextEdit *t = new QTextEdit(f2);
    t->setText("Правила игры в Ханойскую башню.");
    t->append("Есть три контейнера. Изначально в 1 контейнере лежат 8 дисков, от большего к меньшему."
              "Задача - перенести пирамиду из дисков в том же порядке в другой контейнер, перенося"
              "за раз только один диск, и не помещая больший диск на меньший. ");
    t->setFont(f);


    t->setReadOnly(true);


    QVBoxLayout *lay = new QVBoxLayout(f2);

    lay->addWidget(t);

    f2->setLayout(lay);

    f2->show();
}
void MainWindow::on_rebuld_clicked()
{
    v1.clear();
    v2.clear();
    v3.clear();
    Constructor();
    count = 0;
    cl[0] = false;
    cl[1] = false;
    cl[2] = false;
}

