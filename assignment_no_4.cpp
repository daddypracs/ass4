#include "assignment_no_4.h"
#include "ui_assignment_no_4.h"
QImage j(600,600,QImage::Format_RGB888);
Assignment_No_4::Assignment_No_4(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Assignment_No_4)
{
  ui->setupUi(this);
}

Assignment_No_4::~Assignment_No_4()
{
  delete ui;
}

void Assignment_No_4::DDA_Line(float x1,float y1,float x2,float y2)
{

  float step, dx, dy, i, x, y;
  dx = x2-x1;
  dy = y2-y1;
  if(abs(dx)>=abs(dy))
    {
      step = abs(dx);
    }
  else
    {
      step = abs(dy);
    }
  x = x1;
  y = y1;
  i = 0;
  dx = (dx/step);
  dy = (dy/step);
  while (i<=step)
    {
      j.setPixel((x),(y),qRgb(255,255,0));
      x = x + dx;
      y = y + dy;
      i++;
    }
}
void Assignment_No_4::on_pushButton_clicked()
{
    Scan_Line_Fill_Concave();
    ui->label->setPixmap(QPixmap::fromImage(j));
}
void Assignment_No_4::on_pushButton_2_clicked()
{
    Scan_Line_Fill_Convex();
    ui->label->setPixmap(QPixmap::fromImage(j));
}

void Assignment_No_4::Scan_Line_Fill_Concave()
{

  int x1[] = {100,200,250,250,200,150,100};
  int y1[] = {100,150,100,200,250,200,100};
  int i = 0;
  int n = 7;
  int ymin = 600;
  int ymax = 0;
  int c,j,y;
  float m[50],a[50],dx,dy,t;
  x1[i] = x1[0];
  y1[i] = y1[0];
  for(i=0;i<n-1;i++)
  {
      DDA_Line(x1[i],y1[i],x1[i+1],y1[i+1]);
  }
  for(i=0;i<n;i++)
  {
        if(y1[i]>=ymax)
        {
            ymax = y1[i];
        }
        if(y1[i]<=ymin)
        {
            ymin = y1[i];
        }
        dx = x1[i+1]-x1[i];
        dy = y1[i+1]-y1[i];
        if(dx==0)
        {
            m[i] = 0;
        }
        if(dy==0)
        {
            m[i] = 1;
        }
        if(dx!=0 and dy!=0)
        {
            m[i] = dx/dy;
        }

  }
  for(y = ymax;y>=ymin;y--)
  {
      c = 0;
      for(i=0;i<n;i++)
      {
          if((y1[i]>y and y1[i+1]<=y) or (y1[i]<=y && y1[i+1]>y))
          {
              a[c]=x1[i]+(m[i]*(y-y1[i]));
              c++;
          }
      }

    for(i=0;i<c-1;i++)      //Bubble sort
    {
      for(j=0;j<c-1;j++)
      {
          if(a[j]>a[j+1])
          {
              t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
          }
      }
    }
      for(i=0;i<c-1;i=i+2)
      {
          DDA_Line(a[i],y,a[i+1],y);
      }
  }
}

void Assignment_No_4::Scan_Line_Fill_Convex()
{
  int x1[] = {100,200,200,100,100};
  int y1[] = {100,100,200,200,100};
  int i = 0;
  int n = 5;
  int ymin = 600;
  int ymax = 0;
  int c,j,y;
  float m[50],a[50],dx,dy,t;
  x1[i] = x1[0];
  y1[i] = y1[0];
  for(i=0;i<n-1;i++)
  {
      DDA_Line(x1[i],y1[i],x1[i+1],y1[i+1]);
  }
  for(i=0;i<n;i++)
  {
        if(y1[i]>=ymax)
        {
            ymax = y1[i];
        }
        if(y1[i]<=ymin)
        {
            ymin = y1[i];
        }
        dx = x1[i+1]-x1[i];
        dy = y1[i+1]-y1[i];
        if(dx==0)
        {
            m[i] = 0;
        }
        if(dy==0)
        {
            m[i] = 1;
        }
        if(dx!=0 and dy!=0)
        {
            m[i] = dx/dy;
        }

  }
  for(y = ymax;y>=ymin;y--)
  {
      c = 0;
      for(i=0;i<n;i++)
      {
          if((y1[i]>y and y1[i+1]<=y) or (y1[i]<=y && y1[i+1]>y))
          {
              a[c]=x1[i]+(m[i]*(y-y1[i]));
              c++;
          }
      }

    for(i=0;i<c-1;i++)      //Bubble sort
    {
      for(j=0;j<c-j-1;j++)
      {
          if(a[j]>a[j+1])
          {
              t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
          }
      }
    }
      for(i=0;i<c-1;i+=2)
      {
          DDA_Line(a[i],y,a[i+1],y);
      }
  }
}

