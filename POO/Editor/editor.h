#ifndef EDITOR_H
#define EDITOR_H


#include <QObject>
#include <QWidget>
#include <QLabel>
#include<QPushButton>
#include<QTextEdit>
#include<QGridLayout>

class Editor:public QWidget
{
    Q_OBJECT
private:
    QLabel *lCantidad;
    QTextEdit *teTexto;
    QPushButton *pbBuscar;
    QGridLayout *layout;

public:

    Editor();
    ~Editor();

private slots:

    void slot_buscar();


};

#endif // EDITOR_H
