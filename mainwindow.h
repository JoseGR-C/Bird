#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTimer>
#include<QTime>
#include <QMainWindow>
#include<QImage>
#include<QRgb>
#include<juego.h>
#include<QKeyEvent>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mostrarImagen();
    void actualizarJuego();
    void actualizarMarcador();
    void actualizarRonda();
    bool tocaAvanzar();
    void perder();


private slots :
    void actualizarEstado();


private:
    Ui::MainWindow *ui;
    Juego *juego;
    QTimer *timer = new QTimer;
    QTime time;
    QRgb colores[3];
    int turnoAvanzar;
    int  moneda;
    QMessageBox msgBox;
    void iniciarJuego();

protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // MAINWINDOW_H
