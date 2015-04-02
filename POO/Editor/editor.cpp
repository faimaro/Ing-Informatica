#include "editor.h"
#include <QDebug>
Editor::Editor()
{

    teTexto=new QTextEdit;
    pbBuscar=new QPushButton("Buscar -a-");
    lCantidad=new QLabel("");
    layout=new QGridLayout;

    layout->addWidget(teTexto,0,0,1,1);
    layout->addWidget(pbBuscar,9,0,1,1);
    layout->addWidget(lCantidad,0,1,1,1);
    this->setLayout(layout);
    connect(pbBuscar,SIGNAL(clicked()),this,SLOT(slot_buscar()));
    connect(teTexto,SIGNAL(returnPressed()),this,SLOT(slot_buscar()));
}

Editor::~Editor()
{

}
void Editor::slot_buscar()
{
    int cant=0;
    QString *cad=new QString;
    cad->append(teTexto->toPlainText());

    for(int i=0;i<cad->size();i++)
    {
        if(cad->at(i)=='a')cant++;
    }
    cad->clear();
    cad->append("Hay ");
    cad->append(QString::number(cant));
    cad->append("letras \n");
    cad->append("-a- en el texto que ingresaste");
    //qDebug()<<cant;
    lCantidad->setText(*cad);
}

