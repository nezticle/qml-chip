#ifndef CHIPITEM_H
#define CHIPITEM_H

#include <QtQuick/QQuickItem>
#include "chipsmodel.h"

class ChipItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(bool isSelected READ selected WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY(qreal lod READ lod WRITE setLod NOTIFY lodChanged)
    Q_PROPERTY(int modelX READ modelX WRITE setModelX NOTIFY modelXChanged)
    Q_PROPERTY(int modelY READ modelY WRITE setModelY NOTIFY modelYChanged)
    Q_PROPERTY(ChipsModel* model READ model WRITE setModel NOTIFY modelChanged)

public:
    ChipItem(QQuickItem *parent = nullptr);

    //QRectF boundingRect() const;

    //void paint(QPainter *painter);

    QColor color() const;
    bool selected() const;
    qreal lod() const;
    int modelX() const;
    int modelY() const;
    ChipsModel *model() const;

public slots:
    void setColor(QColor color);
    void setSelected(bool selected);
    void setLod(qreal lod);
    void setModelX(int modelX);
    void setModelY(int modelY);

    void setModel(ChipsModel* model);

signals:
    void colorChanged(QColor color);
    void selectedChanged(bool selected);
    void lodChanged(qreal lod);
    void modelXChanged(int modelX);
    void modelYChanged(int modelY);

    void modelChanged(ChipsModel* model);

private:
    QSGNode* createChipNodes();

    QColor m_color;
    bool m_selected;
    qreal m_lod;
    int m_modelX;
    int m_modelY;

    ChipsModel* m_model;

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *) override;
};

#endif // CHIPITEM_H
