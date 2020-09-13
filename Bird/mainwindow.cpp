#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEstado()));

    //iniciamos juego
      iniciarJuego();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: iniciarJuego(){


    this->time.setHMS(0,0,10);
    QRgb value[3]= {qRgb(0,0,0),qRgb(0,255,0),qRgb(255,0,0)};
    this->colores[0] = value[0];
    this->colores[1] = value[1];
    this->colores[2] = value[2];

    this->turnoAvanzar = 0;

    this->moneda = 0;
    this->juego = new Juego();


}

bool MainWindow :: tocaAvanzar() {

    if(this->turnoAvanzar<3) { turnoAvanzar++; return false;}
    else{turnoAvanzar=0; return true;}

}

void MainWindow :: actualizarEstado(){

  actualizarJuego();

  actualizarMarcador();

  actualizarRonda();

}

void MainWindow :: actualizarJuego(){


    this->juego->moverTxoria();
   if(tocaAvanzar()) this->juego->avanceTablero();
    this->juego->sincronizar();

    mostrarImagen();

    if(juego->getPerdido()) perder();

}

void MainWindow :: actualizarMarcador(){

    ui->roundWindow->display(juego->getRound());

    time = time.addMSecs(-20);
    ui->countDownWindow->display(time.toString("ss"));

}

void MainWindow :: actualizarRonda() {

    if (time.toString()=="00:00:00") {
        juego->increaseRound();
        this->time.setHMS(0,0,10);}

}

void MainWindow :: mostrarImagen(){
    //INICIAMOS LA IMAGE
    QSize size= ui->pantalla->size();
    QImage image(size.width(),size.height(), QImage::Format_RGB32);


    int lengthX = ui->pantalla->size().width();
    int lengthY = ui->pantalla->size().height();

    int pX= lengthX/juego->lengthX;
    int pY = lengthY/juego->lengthY ;

    int color;

           for(int i=0; i<juego->lengthX;i++){
               for(int j=0; j<(juego->lengthY);j++){

                 color = juego->getColor(i,j);
                 if(color==1){
                   ui->pajaro->setGeometry(i*pX,j*pY,50,50);
                 }

                 else{
                   for (int x=0;x<pX;x++) {
                       for (int y=0;y<pY;y++) {

                           image.setPixel(i*pX+x, j*pY+y, colores[color]);


                       }
                   }
                 }


               }

           }

           ui->pantalla->setPixmap(QPixmap::fromImage(image));

           if(moneda<6) {
             ui->pajaro->setStyleSheet(" background-image: url(:/bird_down.png)");
             moneda++;
           }
            else {
             ui->pajaro->setStyleSheet(" background-image: url(:/bird_up.png)");
             moneda++;
             if(moneda==10) moneda=0;
           }
}

void MainWindow :: perder() {
    this->timer->stop();
    msgBox.setWindowTitle("Juego terminado");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setEscapeButton(QMessageBox::No);
    msgBox.setText("Perdiste :( \n ¿Volver a jugar?");
    if (QMessageBox::Yes == msgBox.exec()){
         iniciarJuego();
         ui->startLabel->setVisible(true);
         mostrarImagen();
    }
    else{
        QCoreApplication::quit();
    }
}

void MainWindow :: keyPressEvent(QKeyEvent *e){

 int tecla = e->key();

  if (tecla==32) this->juego->cargarBateria();
  if (tecla==90) {  this->timer->start(10); ui->startLabel->setVisible(false); }

}
