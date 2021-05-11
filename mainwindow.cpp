#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::agregar(int valor)
{
    if (empty == true)
    {
        valores.push_back(0);
        empty = false;
    }
    if(cantidadOp == cantidadVal){
        valores.push_back(valor);
        cantidadVal++;
    }
    else {
        valores[cantidadVal-1] = (valores[cantidadVal-1] * 10) + valor;
    }
    ui->pantalla->display(valores[cantidadVal-1]);
}


void MainWindow::on_botonIgual_clicked()
{
    for (int i = 0; i < cantidadOp; i ++) {
        switch (operaciones[i]) {
            case '+': valores[0] = valores[0] + valores[i+1];
            break;
            case '-': valores[0] = valores[0] - valores[i+1];
            break;
            case '*': valores[0] = valores[0] * valores[i+1];
            break;
        case '/': valores[0] = valores[0]/valores [i+1];
        }
    }
    resultado = valores[0];
    while (valores.size()!=1) {
        valores.pop_back();
    }
    cantidadVal = 1;
    while (operaciones.size() != 0) {
        operaciones.pop_back();
    }
    cantidadOp = 0;
    ui->pantalla->display(resultado);
}


void MainWindow::on_boton0_clicked(){agregar(0);}
void MainWindow::on_boton1_clicked(){agregar(1);}
void MainWindow::on_boton2_clicked(){agregar(2);}
void MainWindow::on_boton3_clicked(){agregar(3);}
void MainWindow::on_boton4_clicked(){agregar(4);}
void MainWindow::on_boton5_clicked(){agregar(5);}
void MainWindow::on_boton6_clicked(){agregar(6);}
void MainWindow::on_boton7_clicked(){agregar(7);}
void MainWindow::on_boton8_clicked(){agregar(8);}
void MainWindow::on_boton9_clicked(){agregar(9);}

void MainWindow::on_clear_clicked()
{

    while(valores.size() != 1)
    {
        valores.pop_back();
    }
    valores[0] = 0;
    cantidadVal = 1;
    while (operaciones.size() != 0) {
        operaciones.pop_back();
    }
    cantidadOp = 0;
    ui->pantalla->display(valores[0]);
}

void MainWindow::on_signo_clicked(){
    valores[cantidadVal -1] = (-1)*(valores[cantidadVal -1] );
    ui->pantalla->display(valores[cantidadVal-1]);
}

void MainWindow::on_division_clicked(){ operaciones.push_back('/'); cantidadOp++;}
void MainWindow::on_suma_clicked(){ operaciones.push_back('+');cantidadOp++;}
void MainWindow::on_resta_clicked(){ operaciones.push_back('-');cantidadOp++;}
void MainWindow::on_producto_clicked(){ operaciones.push_back('*');cantidadOp++;}
