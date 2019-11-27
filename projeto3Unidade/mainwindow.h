#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_horizontalSliderMatriz_valueChanged();
    void on_pushButtonMatriz_clicked();
    void on_pushButtonCor_clicked();
    void on_pushButtonPutBox_clicked();
    void on_pushButtonCutBox_clicked();
    void on_pushButtonPutSphere_clicked();
    void on_pushButtonCutSphere_clicked();
    void on_pushButtonPutEllipsoid_clicked();
    void on_pushButtonCutEllipsoid_clicked();
    void on_radioButtonSphere_clicked();
    void on_radioButtonBox_clicked();
    void on_radioButtonPut_clicked();
    void on_radioButtonEllip_clicked();
    void on_pushButtonSalvar_clicked();
private slots:

private:
    int matrizX, matrizY, matrizZ;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H



