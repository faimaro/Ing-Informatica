#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>


class Formulario: public QWidget
{
    Q_OBJECT;
private:
    QLabel *lLegajo,*lNombre,*lApellido;
    QLineEdit *leLegajo,*leNombre,*leApellido;
    QPushButton *pbAlta;
    QPushButton *pbVolver;
    QGridLayout *layout;
public:
    Formulario();
    ~Formulario();
};

#endif // FORMULARIO_H
