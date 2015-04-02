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
#include<iostream>
#include "login.h"
#include "formulario.h"
using namespace  std;
int main(int argc,char ** argv)
{

    QApplication a(argc,argv);
    //Formulario *formulario=new Formulario;
    Login *login=new Login;
    char cad[2][3]={
        {
            's','i','\000'
        },
        {
            'n','o','\000'
        }
    };


   cout<<cad;

    login->show();














    return a.exec();
}

