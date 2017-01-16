#include "mainwindow.h"
#include "view.h"
#include "chipitem.h"

#include <QHBoxLayout>
#include <QSplitter>

#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_h1Spliter = new QSplitter;
    m_h2Spliter = new QSplitter;

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(m_h1Spliter);
    vSplitter->addWidget(m_h2Spliter);

    m_qmlEngine = new QQmlEngine(this);
    m_chipsModel = new ChipsModel(this);

    m_qmlEngine->rootContext()->setContextProperty("chipModel", m_chipsModel);
    qmlRegisterType<ChipItem>("io.qad.chip" , 1, 0, "ChipItem");

    auto view = new View("Top left view", m_qmlEngine);
    m_h1Spliter->addWidget(view);

    view = new View("Top right view", m_qmlEngine);
    m_h1Spliter->addWidget(view);

    view = new View("Bottom left view", m_qmlEngine);
    m_h2Spliter->addWidget(view);

    view = new View("Bottom right view", m_qmlEngine);
    m_h2Spliter->addWidget(view);

    setCentralWidget(vSplitter);

    setWindowTitle("QML Chip Example");
}
