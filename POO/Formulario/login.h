#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include "formulario.h"
class Login: public QWidget
{
    Q_OBJECT
public:
    Login();
    ~Login();
private:
    Formulario *form;
    QLabel *lUsuario,*lClave;
    QLineEdit *leUsuario,*leClave;
    QGridLayout *layout;
    QPushButton *pbIngresar;
private slots:
    void slot_validar();
};

#endif // LOGIN_H
