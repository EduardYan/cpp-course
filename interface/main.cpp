#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>
#include <QLabel>

class TaskManager : public QWidget
{
  Q_OBJECT

public:
  TaskManager(QWidget *parent = nullptr) : QWidget(parent)
  {
    setupUI();

    loadTasks();
  }

private slots:
  void addTask()
  {
    QString taskText = taskLineEdit->text();
    if (!taskText.isEmpty())
    {
      taskListWidget->addItem(taskText);
      taskLineEdit->clear();
      saveTasks();
      updateNoTasksLabelVisibility();
    }
  }

  void removeTask()
  {
    int selectedRow = taskListWidget->currentRow();
    if (selectedRow != -1)
    {
      delete taskListWidget->takeItem(selectedRow);
      saveTasks();
      updateNoTasksLabelVisibility();
    }
  }

  void updateTask()
  {
    int selectedRow = taskListWidget->currentRow();
    if (selectedRow != -1)
    {
      QString updatedTaskText = taskLineEdit->text();
      if (!updatedTaskText.isEmpty())
      {
        taskListWidget->item(selectedRow)->setText(updatedTaskText);
        taskLineEdit->clear();
        saveTasks();
        updateNoTasksLabelVisibility();
      }
    }
  }

private:
  void setupUI()
  {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    taskListWidget = new QListWidget(this);
    mainLayout->addWidget(taskListWidget);

    // Crear un QLabel para el mensaje cuando no hay tareas
    noTasksLabel = new QLabel("Ninguna tarea por el momento", this);
    noTasksLabel->setAlignment(Qt::AlignCenter);
    noTasksLabel->setStyleSheet("color: #888888; font-size: 16px;");
    mainLayout->addWidget(noTasksLabel);

    QHBoxLayout *inputLayout = new QHBoxLayout;

    taskLineEdit = new QLineEdit(this);
    inputLayout->addWidget(taskLineEdit);

    addButton = new QPushButton("Agregar", this);
    connect(addButton, &QPushButton::clicked, this, &TaskManager::addTask);
    inputLayout->addWidget(addButton);

    removeButton = new QPushButton("Eliminar", this);
    connect(removeButton, &QPushButton::clicked, this, &TaskManager::removeTask);
    inputLayout->addWidget(removeButton);

    updateButton = new QPushButton("Actualizar", this);
    connect(updateButton, &QPushButton::clicked, this, &TaskManager::updateTask);
    inputLayout->addWidget(updateButton);

    mainLayout->addLayout(inputLayout);

    // Cargar estilos desde el archivo style.qss
    QFile styleFile("style.qss");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      QString style = styleFile.readAll();
      setStyleSheet(style);
    }
  }

  void loadTasks()
  {
    QFile file("tasks.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      QByteArray data = file.readAll();
      file.close();

      QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
      if (jsonDoc.isArray())
      {
        QJsonArray taskArray = jsonDoc.array();
        for (const auto &task : taskArray)
        {
          taskListWidget->addItem(task.toString());
        }
      }
    }

    updateNoTasksLabelVisibility();
  }

  void saveTasks()
  {
    QFile file("tasks.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
      QJsonArray taskArray;

      for (int i = 0; i < taskListWidget->count(); ++i)
      {
        taskArray.append(taskListWidget->item(i)->text());
      }

      QJsonDocument jsonDoc(taskArray);
      file.write(jsonDoc.toJson());
      file.close();
    }

    updateNoTasksLabelVisibility();
  }

  void updateNoTasksLabelVisibility()
  {
    // Mostrar el QLabel si no hay tareas
    noTasksLabel->setVisible(taskListWidget->count() == 0);
  }

  QListWidget *taskListWidget;
  QLineEdit *taskLineEdit;
  QPushButton *addButton;
  QPushButton *removeButton;
  QPushButton *updateButton;
  QLabel *noTasksLabel;
};

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QFontDatabase::addApplicationFont("./HackNerdFontMono-Regular.ttf");
  QFont customFont("HackNerdFontMono", 12);
  app.setFont(customFont);

  TaskManager taskManager;
  taskManager.show();

  return app.exec();
}

#include "main.moc"
