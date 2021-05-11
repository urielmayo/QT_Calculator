#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void agregar(int valor);

private slots:
    void on_boton0_clicked();
    void on_botonIgual_clicked();
    void on_boton1_clicked();
    void on_boton2_clicked();
    void on_boton3_clicked();
    void on_boton4_clicked();
    void on_boton5_clicked();
    void on_boton6_clicked();
    void on_boton7_clicked();
    void on_boton8_clicked();
    void on_boton9_clicked();
    void on_clear_clicked();
    void on_signo_clicked();
    void on_division_clicked();
    void on_suma_clicked();
    void on_resta_clicked();
    void on_producto_clicked();

private:
    Ui::MainWindow *ui;
private:
    bool empty = true;
    std::vector <float> valores;
    std::vector <char> operaciones;
    int cantidadVal = 1, cantidadOp = 0;
    float resultado;
};
#endif // MAINWINDOW_H
