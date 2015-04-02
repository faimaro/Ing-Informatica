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
#include "login.h"

int main(int argc,char ** argv)
{

    QApplication a(argc,argv);
    Login *login=new Login;

    login->show();







    return a.exec();
}
