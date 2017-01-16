#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "chipsmodel.h"

class QQmlEngine;
class QSplitter;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QQmlEngine *m_qmlEngine;
    QSplitter *m_h1Spliter;
    QSplitter *m_h2Spliter;

    ChipsModel *m_chipsModel;
};

#endif // MAINWINDOW_H
