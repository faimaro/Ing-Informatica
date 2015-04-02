#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
class Login: public QWidget
{
    Q_OBJECT
public:
    Login();
    ~Login();
private:
    QLabel *lUsuario,*lClave;
    QLineEdit *leUsuario,*leClave;
    QGridLayout *layout;
    QPushButton *pbIngresar;
private slots:
    void slot_validar();
};

#endif // LOGIN_H
