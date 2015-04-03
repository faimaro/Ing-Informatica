
#include<QApplication>
#include<QLabel>
#include<QMenu>
#include<QPushButton>
#include<QSlider>
#include<QHBoxLayout>
#include<QSpinBox>
#include<QDebug>
#include<QLineEdit>
#include<QGridLayout>
#include "editor.h"
//solo es un comentario de pruebaaa para GITHUBB
int main(int argc,char ** argv)
{

    QApplication a(argc,argv);
    Editor *editor=new Editor;

    editor->show();







    return a.exec();
}
