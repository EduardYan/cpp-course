#include <QApplication>
#include "ipinfoapp.h"
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QClipboard>
#include <QCursor>

IpInfoApp::IpInfoApp(QWidget *parent) : QWidget(parent)
{
    labelTitulo = new QLabel("Obtener información de IP", this);
    labelResultado = new QLabel("", this);
    labelResultado->setObjectName("labelResultado");
    lineEditIP = new QLineEdit(this);
    btnObtenerInfo = new QPushButton("Obtener información", this);
    btnCerrar = new QPushButton("Cerrar", this);
    btnCerrar->setObjectName("btnCerrar");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(labelTitulo);
    layout->addWidget(lineEditIP);
    layout->addWidget(btnObtenerInfo);
    layout->addWidget(labelResultado);
    layout->addWidget(btnCerrar);

    setLayout(layout);

    connect(btnObtenerInfo, &QPushButton::clicked, this, &IpInfoApp::obtenerInformacion);

    // Configuración del cursor al pasar sobre el botón
    btnObtenerInfo->setCursor(Qt::PointingHandCursor);
    btnCerrar->setCursor(Qt::PointingHandCursor);

    // Conectar la señal clicked del botón de cerrar con la función close()
    connect(btnCerrar, &QPushButton::clicked, this, &IpInfoApp::close);
}

void IpInfoApp::obtenerInformacion()
{
    QString ip = lineEditIP->text();

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://ip-api.com/json/" + ip));

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]()
            {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();

            // Formatear el JSON con 2 espacios de indentación
            QJsonParseError error;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &error);

            if (error.error == QJsonParseError::NoError) {
                QString formattedJson = jsonDoc.toJson(QJsonDocument::Indented);

                // Mostrar el resultado formateado y permitir la copia al portapapeles
                labelResultado->setTextInteractionFlags(Qt::TextSelectableByMouse);
                labelResultado->setText(formattedJson);

                // Habilitar la acción de copiar al portapapeles
                QClipboard *clipboard = QApplication::clipboard();
                connect(labelResultado, &QLabel::linkActivated, [=]() {
                    clipboard->setText(labelResultado->selectedText());
                });

                // Mensaje informativo
                // QMessageBox::information(this, "Información", "Información de IP obtenida exitosamente.");
            } else {
                labelResultado->setText("Error al analizar la respuesta JSON");
            }
        } else {
            labelResultado->setText("Error al obtener información");
        }

        reply->deleteLater(); });
}
