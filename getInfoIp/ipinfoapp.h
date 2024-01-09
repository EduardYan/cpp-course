#ifndef IPINFOAPP_H
#define IPINFOAPP_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class IpInfoApp : public QWidget
{
  Q_OBJECT

public:
  IpInfoApp(QWidget *parent = nullptr);

private slots:
  void obtenerInformacion();

private:
  QLabel *labelTitulo;
  QLabel *labelResultado;
  QLineEdit *lineEditIP;
  QPushButton *btnObtenerInfo;
  QPushButton *btnCerrar;
};

#endif // IPINFOAPP_H
