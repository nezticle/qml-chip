#include "view.h"
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStyle>

View::View(const QString &name, QQmlEngine *engine, QWidget *parent)
    : QFrame(parent)
{
    setFrameStyle(Sunken | StyledPanel);
    m_quickWidget = new QQuickWidget(engine, this);

    int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
    QSize iconSize(size, size);

    QToolButton *zoomInIcon = new QToolButton;
    zoomInIcon->setAutoRepeat(true);
    zoomInIcon->setAutoRepeatInterval(33);
    zoomInIcon->setAutoRepeatDelay(0);
    zoomInIcon->setIcon(QPixmap(":/zoomin.png"));
    zoomInIcon->setIconSize(iconSize);
    QToolButton *zoomOutIcon = new QToolButton;
    zoomOutIcon->setAutoRepeat(true);
    zoomOutIcon->setAutoRepeatInterval(33);
    zoomOutIcon->setAutoRepeatDelay(0);
    zoomOutIcon->setIcon(QPixmap(":/zoomout.png"));
    zoomOutIcon->setIconSize(iconSize);
    m_zoomSlider = new QSlider;
    m_zoomSlider->setMinimum(0);
    m_zoomSlider->setMaximum(500);
    m_zoomSlider->setValue(250);
    m_zoomSlider->setTickPosition(QSlider::TicksRight);

    // Zoom slider layout
    QVBoxLayout *zoomSliderLayout = new QVBoxLayout;
    zoomSliderLayout->addWidget(zoomInIcon);
    zoomSliderLayout->addWidget(m_zoomSlider);
    zoomSliderLayout->addWidget(zoomOutIcon);

    QToolButton *rotateLeftIcon = new QToolButton;
    rotateLeftIcon->setIcon(QPixmap(":/rotateleft.png"));
    rotateLeftIcon->setIconSize(iconSize);
    QToolButton *rotateRightIcon = new QToolButton;
    rotateRightIcon->setIcon(QPixmap(":/rotateright.png"));
    rotateRightIcon->setIconSize(iconSize);
    m_rotateSlider = new QSlider;
    m_rotateSlider->setOrientation(Qt::Horizontal);
    m_rotateSlider->setMinimum(-360);
    m_rotateSlider->setMaximum(360);
    m_rotateSlider->setValue(0);
    m_rotateSlider->setTickPosition(QSlider::TicksBelow);

    // Rotate slider layout
    QHBoxLayout *rotateSliderLayout = new QHBoxLayout;
    rotateSliderLayout->addWidget(rotateLeftIcon);
    rotateSliderLayout->addWidget(m_rotateSlider);
    rotateSliderLayout->addWidget(rotateRightIcon);

    m_resetButton = new QToolButton;
    m_resetButton->setText(tr("0"));
    m_resetButton->setEnabled(false);

    // Label layout
    QHBoxLayout *labelLayout = new QHBoxLayout;
    m_label1 = new QLabel(name);
    m_label2 = new QLabel(tr("Pointer Mode"));
    m_selectModeButton = new QToolButton;
    m_selectModeButton->setText(tr("Select"));
    m_selectModeButton->setCheckable(true);
    m_selectModeButton->setChecked(true);
    m_dragModeButton = new QToolButton;
    m_dragModeButton->setText(tr("Drag"));
    m_dragModeButton->setCheckable(true);
    m_dragModeButton->setChecked(false);

    QButtonGroup *pointerModeGroup = new QButtonGroup(this);
    pointerModeGroup->setExclusive(true);
    pointerModeGroup->addButton(m_selectModeButton);
    pointerModeGroup->addButton(m_dragModeButton);

    labelLayout->addWidget(m_label1);
    labelLayout->addStretch();
    labelLayout->addWidget(m_label2);
    labelLayout->addWidget(m_selectModeButton);
    labelLayout->addWidget(m_dragModeButton);
    labelLayout->addStretch();

    QGridLayout *topLayout = new QGridLayout;
    topLayout->addLayout(labelLayout, 0, 0);
    topLayout->addWidget(m_quickWidget, 1, 0);
    topLayout->addLayout(zoomSliderLayout, 1, 1);
    topLayout->addLayout(rotateSliderLayout, 2, 0);
    topLayout->addWidget(m_resetButton, 2, 1);
    setLayout(topLayout);

    connect(m_resetButton, SIGNAL(clicked()), this, SLOT(resetView()));
    connect(m_zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
    connect(m_rotateSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
//    connect(graphicsView->verticalScrollBar(), SIGNAL(valueChanged(int)),
//            this, SLOT(setResetButtonEnabled()));
//    connect(graphicsView->horizontalScrollBar(), SIGNAL(valueChanged(int)),
//            this, SLOT(setResetButtonEnabled()));
    connect(m_selectModeButton, SIGNAL(toggled(bool)), this, SLOT(togglePointerMode()));
    connect(m_dragModeButton, SIGNAL(toggled(bool)), this, SLOT(togglePointerMode()));
    connect(rotateLeftIcon, SIGNAL(clicked()), this, SLOT(rotateLeft()));
    connect(rotateRightIcon, SIGNAL(clicked()), this, SLOT(rotateRight()));
    connect(zoomInIcon, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(zoomOutIcon, SIGNAL(clicked()), this, SLOT(zoomOut()));

    setupMatrix();

    m_quickWidget->setSource(QUrl("qrc:/scene.qml"));
}

void View::zoomIn(int level)
{

}

void View::zoomOut(int level)
{

}

void View::resetView()
{

}

void View::setResetButtonEnabled()
{

}

void View::setupMatrix()
{

}

void View::togglePointerMode()
{

}

void View::rotateLeft()
{

}

void View::rotateRight()
{

}
