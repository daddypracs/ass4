#ifndef ASSIGNMENT_NO_4_H
#define ASSIGNMENT_NO_4_H

#include <QMainWindow>
#include<QWidget>
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Assignment_No_4; }
QT_END_NAMESPACE

class Assignment_No_4 : public QMainWindow
{
  Q_OBJECT

public:
  Assignment_No_4(QWidget *parent = nullptr);
  ~Assignment_No_4();
  void DDA_Line(float,float,float,float);
  void Scan_Line_Fill_Concave();
  void Scan_Line_Fill_Convex();
private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();

private:
  Ui::Assignment_No_4 *ui;

};
#endif // ASSIGNMENT_NO_4_H
