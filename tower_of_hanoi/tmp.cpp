#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;

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



}

void MainWindow::setScene(QGraphicsScene *scene, QGraphicsView *view){

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::difference(int a, int b)
{
    //if ()
}

void MainWindow::on_push2_clicked()
{
    switch(current){
    case 1:{ //1 -> 2

        v2.push(v1.pop());
        int k = v2.top();
        scene1->removeItem(mas[k]);
        scene2->addItem(mas[k]);
        count1=v1.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count2-1),50+10*k,20);
        current = 0;
        break;
    }
    case 3: //3 -> 2
        v2.push(v3.pop());
        int k = v2.top();
        scene3->removeItem(mas[k]);
        scene2->addItem(mas[k]);
        count3= v3.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count2-1),50+10*k,20);
        current = 0;
        break;
    }
}

void MainWindow::on_push3_clicked()
{
    switch(current){
    case 1:{ //1 -> 3
        v3.push(v1.pop());
        //v1.top - 1
        //v2.top - 0
        int k = v3.top();
        scene1->removeItem(mas[k]);
        scene3->addItem(mas[k]);
        count1=v1.count();
        count3 = v3.count();
        mas[k]->setRect(55-k*5,140-20*(count3-1),50+10*k,20);
        current = 0;
        break;
    }
    case 2: //2 -> 3
        v3.push(v2.pop());
        int k = v3.top();
        scene2->removeItem(mas[k]);
        scene3->addItem(mas[k]);
        count3=v3.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count3-1),50+10*k,20);
        current = 0;
        break;
    }
}

void MainWindow::on_push1_clicked()
{
    switch(current){
    case 2:{ //2 -> 1
        v1.push(v2.pop());
        //v1.top - 1
        //v2.top - 0
        int k = v1.top();
        scene2->removeItem(mas[k]);
        scene1->addItem(mas[k]);
        count1=v1.count();
        count2 = v2.count();
        mas[k]->setRect(55-k*5,140-20*(count1-1),50+10*k,20);
        current = 0;
        break;
    }
    case 3: //3 -> 1
        v1.push(v3.pop());
        int k = v1.top();
        scene3->removeItem(mas[k]);
        scene1->addItem(mas[k]);
        count1=v1.count();
        count3 = v3.count();
        mas[k]->setRect(55-k*5,140-20*(count1-1),50+10*k,20);
        current = 0;
        break;
    }
}

void MainWindow::on_sel1_clicked()
{
    current = 1;

}


void MainWindow::setColotSelect(bool clicked, int cur, int current_scene){

}


void MainWindow::on_sel2_clicked()
{
    current = 2;
}

void MainWindow::on_sel3_clicked()
{
    current = 3;
}


