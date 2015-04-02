#include "formulario.h"

Formulario::Formulario()
{

    lLegajo = new QLabel("Legajo:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    leLegajo=new QLineEdit;
    leNombre=new QLineEdit;
    leApellido=new QLineEdit;
    pbAlta=new QPushButton ("Alta");
    pbVolver=new QPushButton ("Volver");
    layout=new QGridLayout;
    layout->addWidget(lLegajo,0,0,1,1);
    layout->addWidget(lNombre,1,0);
    layout->addWidget(lApellido,2,0);
    layout->addWidget(leLegajo,0,1,1,1);
    layout->addWidget(leNombre,1,1,1,3);
    layout->addWidget(leApellido,2,1,1,3);
    layout->addWidget(pbAlta,4,0);
    layout->addWidget(pbVolver,4,3);
    this->setLayout(layout);

}

Formulario::~Formulario()
{

}

