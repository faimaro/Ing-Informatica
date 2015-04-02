#include "login.h"

Login::Login()
{
    form=new Formulario;
    lUsuario=new QLabel("Usuario: ");
    lClave=new QLabel("Clave: ");
    leUsuario=new QLineEdit;
    leClave=new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);
    pbIngresar=new QPushButton("Ingresar");
    layout=new QGridLayout;
    layout->addWidget(lUsuario,0,0,1,1);
    layout->addWidget(lClave,1,0);
    layout->addWidget(leUsuario,0,1,1,3);
    layout->addWidget(leClave,1,1,1,3);
    layout->addWidget(pbIngresar,2,1);
    this->setLayout(layout);
    connect(pbIngresar,SIGNAL(clicked()),this,SLOT(slot_validar()));
    connect(leClave,SIGNAL(returnPressed()),this,SLOT(slot_validar()));

}

Login::~Login()
{

}
void Login::slot_validar()
{
    if(leUsuario->text()=="admin" && leClave->text()=="1122")
    {
        this->hide();

        form->show();

    }
    else
    {
        leUsuario->setText("");
        leClave->setText("");

    }


}

