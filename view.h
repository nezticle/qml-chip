#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QFrame>


class QLabel;
class QSlider;
class QToolButton;
class QQuickWidget;
class QQmlEngine;

class View : public QFrame
{
    Q_OBJECT
public:
    View(const QString &name, QQmlEngine *engine, QWidget *parent = nullptr);

public slots:
    void zoomIn(int level = 1);
    void zoomOut(int level = 1);

private slots:
    void resetView();
    void setResetButtonEnabled();
    void setupMatrix();
    void togglePointerMode();
    void rotateLeft();
    void rotateRight();

private:
    QQuickWidget *m_quickWidget;
    QLabel *m_label1;
    QLabel *m_label2;
    QToolButton *m_selectModeButton;
    QToolButton *m_dragModeButton;
    QToolButton *m_resetButton;
    QSlider *m_zoomSlider;
    QSlider *m_rotateSlider;
};

#endif // VIEW_H
