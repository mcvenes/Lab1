#include "mygui.h"
#include <QObject>
#include <QListWidgetItem>
#include "MyStack.h"
#include "Person.h"
#include "PersonKeeper.h"


MyGUI::MyGUI()
{
    // Инициализируем GUI-элементы
    inputPath = new QTextEdit;
    outputPath = new QTextEdit;
    listWidget = new QListWidget;
    inputButton = new QPushButton(tr("Input"));
    outputButton = new QPushButton(tr("Output"));

    // Присваеиваем полям для ввода пути файлов изначальные имена, чтобы не перепутать
    inputPath->setText(tr("inputPath"));
    outputPath->setText(tr("outputPath"));

    // Связываем функции и кнопки
    connect(inputButton, SIGNAL(clicked()), this, SLOT(open()));
    connect(outputButton, SIGNAL(clicked()), this, SLOT(output()));

    // Добавляем элементы в приложение
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(inputPath);
    layout->addWidget(inputButton);
    layout->addWidget(outputPath);
    layout->addWidget(outputButton);
    layout->addWidget(listWidget);
    setLayout(layout);

    // Устанавливаем название окна
    setWindowTitle(tr("MyGUI"));
}

static int showMsgBox(QString text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    return msgBox.exec();
}

int MyGUI::open()
{
    // Получаем путь к файлу из GUI-элементов
    std::string inputFilePath = inputPath->toPlainText().toStdString();

    // Пытаемся прочитать входной файл
    personStack = PersonKeeper::instance().readPersons(inputFilePath, 100);
    if (personStack == NULL) return showMsgBox("Incorrect input path");

    // Удаляем из GUI-списка предыдущие элементы
    listWidget->clear();

    // Вывод прочитанного в GUI-элемент
    while (!personStack->isEmpty())
    {
        Person p = personStack->pop();
        std::string fullName = p.getLastName();
        fullName += " " + p.getFirstName();
        fullName += " " + p.getMiddleName();
        new QListWidgetItem(QString::fromStdString(fullName), listWidget);
    }

    // Еще раз считываем файл, так как стек опустошился
    personStack = PersonKeeper::instance().readPersons(inputFilePath, 100);

    return 0;
}

int MyGUI::output()
{
    // Получаем путь к файлу из GUI-элементов
    std::string outputFilePath = outputPath->toPlainText().toStdString();

    // Пытаемся вывести людей в файл
    std::fstream outStream;
    outStream.open(outputFilePath, std::ios_base::out);
    if (!outStream.is_open()) return showMsgBox("Incorrect output path");

    std::cout << "Trying to write persons to file\n";
    PersonKeeper::instance().writePersons(*personStack, outStream);

    return showMsgBox("Written succesfully");;
}
