#pragma once

#include <QApplication>
#include <QtWidgets>
#include <QObject>
#include <QMessageBox>
#include <QListWidget>
#include "MyStack.h"
#include "Person.h"
#include "PersonKeeper.h"

class MyGUI : public QWidget
{
	Q_OBJECT // ������, ��������� ��� ����� ��� QObject

public:
	MyGUI();

private slots: // ���� � �������, ������� ����� ���� ������� � �������� ���������� ���������
    int open();
    int output();

private:
    QTextEdit* inputPath;
    QPushButton* inputButton;
    QTextEdit* outputPath;
    QPushButton* outputButton;
    QListWidget* listWidget;
    MyStack<Person>* personStack;
};
