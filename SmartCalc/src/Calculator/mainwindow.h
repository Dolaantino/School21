#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "qcustomplot.h"

extern "C" {
#include "calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  QVector<double> x, y;

 private slots:

  void on_null_2_clicked();

  void concat(QString str);

  void on_one_clicked();

  void on_two_clicked();

  void on_three_clicked();

  void on_four_clicked();

  void on_five_clicked();

  void on_six_clicked();

  void on_seven_clicked();

  void on_eigth_clicked();

  void on_nine_clicked();

  void on_pushButton_15_clicked();

  void on_plus_clicked();

  void on_minus_clicked();

  void on_mult_clicked();

  void on_div_clicked();

  void on_mod_clicked();

  void on_X_clicked();

  void on_Lbracket_clicked();

  void on_print_graph_clicked();

  void on_Rbracket_clicked();

  void on_pow_clicked();

  void on_sqrt_clicked();

  void on_ln_clicked();

  void on_log_clicked();

  void on_cos_clicked();

  void on_sin_clicked();

  void on_tan_clicked();

  void on_acos_clicked();

  void on_asin_clicked();

  void on_atan_clicked();

  void on_delete_2_clicked();

  void on_plus_minus_clicked();

  void on_equal_clicked();
};
#endif  // MAINWINDOW_H
