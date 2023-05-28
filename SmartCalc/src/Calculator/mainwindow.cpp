#include "mainwindow.h"

#include "ui_mainwindow.h"

extern "C" Node *polish_notation(Node *line, double x_value);
extern "C" double calculation(Node *line);
extern "C" double calculate(double val1, double val2, type_t operation);
extern "C" Node *parsing(const char *str);

extern "C" int operator_1(type_t type);  // E
extern "C" int func(type_t type);
extern "C" Node *inverse_stack(Node *line);

extern "C" void print(Node *list);
extern "C" void push(Node **plist, int prioritet, double number, type_t type_d);
extern "C" void pop(Node **plist);
extern "C" int is_empty(Node *list);

extern "C" int check_input(const char *s);
extern "C" void check_input_start(const char *s, int *err);
extern "C" void check_input_arithmetic(const char *s, int *err, int i);
extern "C" void check_input_brackets(const char *s, int *err, int i);
extern "C" void sum_brackets(int *err, int open, int close);
extern "C" void check_correct(const char *s, int *err, int *open, int *close,
                              int *i);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::concat(QString str) {
  QString text = ui->label->text();

  if (static_cast<int>(text.length()) == 1 &&
      *text.toLocal8Bit().constData() == '0' &&
      *str.toLocal8Bit().constData() != '.')
    ui->label->clear();

  ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_null_2_clicked() { MainWindow::concat("0"); }

void MainWindow::on_one_clicked() { MainWindow::concat("1"); }

void MainWindow::on_two_clicked() { MainWindow::concat("2"); }

void MainWindow::on_three_clicked() { MainWindow::concat("3"); }

void MainWindow::on_four_clicked() { MainWindow::concat("4"); }

void MainWindow::on_five_clicked() { MainWindow::concat("5"); }

void MainWindow::on_six_clicked() { MainWindow::concat("6"); }

void MainWindow::on_seven_clicked() { MainWindow::concat("7"); }

void MainWindow::on_eigth_clicked() { MainWindow::concat("8"); }

void MainWindow::on_nine_clicked() { MainWindow::concat("9"); }

void MainWindow::on_pushButton_15_clicked() { MainWindow::concat("."); }

void MainWindow::on_plus_clicked() { MainWindow::concat("+"); }

void MainWindow::on_minus_clicked() { MainWindow::concat("-"); }

void MainWindow::on_mult_clicked() { MainWindow::concat("*"); }

void MainWindow::on_div_clicked() { MainWindow::concat("/"); }

void MainWindow::on_mod_clicked() { MainWindow::concat("%"); }

void MainWindow::on_X_clicked() { MainWindow::concat("x"); }

void MainWindow::on_Lbracket_clicked() { MainWindow::concat("("); }

void MainWindow::on_Rbracket_clicked() { MainWindow::concat(")"); }

void MainWindow::on_pow_clicked() { MainWindow::concat("^"); }

void MainWindow::on_sqrt_clicked() { MainWindow::concat("sqrt"); }

void MainWindow::on_ln_clicked() { MainWindow::concat("ln"); }

void MainWindow::on_log_clicked() { MainWindow::concat("log"); }

void MainWindow::on_cos_clicked() { MainWindow::concat("cos"); }

void MainWindow::on_sin_clicked() { MainWindow::concat("sin"); }

void MainWindow::on_tan_clicked() { MainWindow::concat("tan"); }

void MainWindow::on_acos_clicked() { MainWindow::concat("acos"); }

void MainWindow::on_asin_clicked() { MainWindow::concat("asin"); }

void MainWindow::on_atan_clicked() { MainWindow::concat("atan"); }

void MainWindow::on_delete_2_clicked() {
  QString s = ui->label->text();

  if (s.length() > 0) {
    QString newtext = s.remove(s.length() - 1, 1);
    ui->label->setText(newtext);
  }
}

void MainWindow::on_plus_minus_clicked() {
  double res = 0.;
  QString tmp;
  if (ui->plus_minus->text() == "+/-") {
    res = (ui->label->text()).toDouble();
    res *= -1;
    tmp = QString::number(res, 'g', 15);
  }
  ui->label->setText(tmp);
}

void MainWindow::on_equal_clicked() {
  QString str = ui->label->text();
  const char *ptr = str.toStdString().c_str();
  int error = 0;
  error = check_input(ptr);
  QString str_x = ui->label_value->text();
  double x = str_x.toDouble();
  Node *polish = NULL;
  if (error == 0) {
    QString str_x = ui->label_value->text();
    double x = str_x.toDouble();
    Node *polish = NULL;
    polish = parsing(ptr);
    polish = polish_notation(polish, x);
    double result = calculation(polish);
    char arr[1000] = {0};
    sprintf(arr, "%0.7lf", result);
    ui->label->setText(arr);
  } else
    ui->label->setText("ERROR!");
}

void MainWindow::on_print_graph_clicked() {
  ui->widget_graph->clearGraphs();
  x.clear();
  y.clear();

  QString str_xBegin = ui->x_begin->text();
  QString str_xEnd = ui->x_end->text();
  QString str_step = ui->step->text();

  double xStart = str_xBegin.toDouble();
  double xEnd = str_xEnd.toDouble();
  double step = str_step.toDouble();

  QString str_xMax = ui->x_max->text();
  QString str_xMin = ui->x_min->text();

  double xMax = str_xMax.toDouble();
  double xMin = str_xMin.toDouble();

  QString str_yMax = ui->y_max->text();
  QString str_yMin = ui->x_max->text();

  double yMax = str_yMax.toDouble();
  double yMin = str_yMin.toDouble();

  ui->widget_graph->xAxis->setRange(xMin, xMax);
  ui->widget_graph->yAxis->setRange(yMin, yMax);

  std::string str = ui->label->text().toStdString();
  char *ptr = &str[0];

  for (double tmp = xStart; tmp <= xEnd; tmp += step) {
    Node *polish = parsing(ptr);
    x.push_back(tmp);
    polish = polish_notation(polish, tmp);
    y.push_back(calculation(polish));
  }

  ui->widget_graph->addGraph();
  ui->widget_graph->graph(0)->addData(x, y);
  ui->widget_graph->replot();
}
