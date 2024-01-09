#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QFontDatabase>
#include "ipinfoapp.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QFile styleFile("./style.qss");
  styleFile.open(QFile::ReadOnly | QFile::Text);
  QTextStream stream(&styleFile);
  qApp->setStyleSheet(stream.readAll());
  styleFile.close();

  int fontId = QFontDatabase::addApplicationFont("./HackNerdFontMono-Regular.ttf");
  QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
  QFont customFont(fontName);
  app.setFont(customFont);

  IpInfoApp ipInfoApp;

  ipInfoApp.show();

  return app.exec();
}
