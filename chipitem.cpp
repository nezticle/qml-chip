#include "chipitem.h"
#include "chipnode.h"

#include <QtGui/QPainter>
#include <QtGui/QImage>
#include <QtQuick/QQuickWindow>

#include <QtQuick/QSGSimpleRectNode>
#include <QtQuick/QSGTexture>

ChipItem::ChipItem(QQuickItem *parent)
    : QQuickItem (parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
}

QColor ChipItem::color() const
{
    return m_color;
}

bool ChipItem::selected() const
{
    return m_selected;
}

qreal ChipItem::lod() const
{
    return m_lod;
}

int ChipItem::modelX() const
{
    return m_modelX;
}

int ChipItem::modelY() const
{
    return m_modelY;
}

ChipsModel *ChipItem::model() const
{
    return m_model;
}

void ChipItem::setColor(QColor color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged(color);
    update();
}

void ChipItem::setSelected(bool selected)
{
    if (m_selected == selected)
        return;

    m_selected = selected;
    emit selectedChanged(selected);
    update();
}

void ChipItem::setLod(qreal lod)
{
    if (m_lod == lod)
        return;

    m_lod = lod;
    emit lodChanged(lod);
    update();
}

void ChipItem::setModelX(int modelX)
{
    if (m_modelX == modelX)
        return;

    m_modelX = modelX;
    emit modelXChanged(modelX);
    update();
}

void ChipItem::setModelY(int modelY)
{
    if (m_modelY == modelY)
        return;

    m_modelY = modelY;
    emit modelYChanged(modelY);
    update();
}

void ChipItem::setModel(ChipsModel *model)
{
    if (m_model == model)
        return;

    m_model = model;
    emit modelChanged(model);
}

QSGNode *ChipItem::createChipNodes()
{
    QSGNode *node = new QSGNode();
    QImage image(110, 70, QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::transparent);
    QPainter painter(&image);

    QPen pen = painter.pen();
    pen.setWidth(0);
    QBrush b = painter.brush();
    painter.setPen(QPen(Qt::gray, 1));
    painter.drawLine(15, 54, 94, 54);
    painter.drawLine(94, 53, 94, 15);
    painter.setPen(QPen(Qt::black, 0));

    // Draw text
    QFont font("Times", 10);
    font.setStyleStrategy(QFont::ForceOutline);
    painter.setFont(font);
    painter.save();
    painter.scale(0.1, 0.1);
    painter.drawText(170, 180, QString("Model: VSC-2000 (Very Small Chip)"));
    painter.drawText(170, 200, QString("Serial number: DLWR-WEER-123L-ZZ33-SDSJ"));
    painter.drawText(170, 220, QString("Manufacturer: Chip Manufacturer"));
    painter.restore();

    // Draw lines
    QVarLengthArray<QLineF, 36> lines;
    for (int i = 0; i <= 10; i += (m_lod > 0.5 ? 1 : 2)) {
        lines.append(QLineF(18 + 7 * i, 13, 18 + 7 * i, 5));
        lines.append(QLineF(18 + 7 * i, 54, 18 + 7 * i, 62));
    }
    for (int i = 0; i <= 6; i += (m_lod > 0.5 ? 1 : 2)) {
        lines.append(QLineF(5, 18 + i * 5, 13, 18 + i * 5));
        lines.append(QLineF(94, 18 + i * 5, 102, 18 + i * 5));
    }

    const QLineF lineData[] = {
        QLineF(25, 35, 35, 35),
        QLineF(35, 30, 35, 40),
        QLineF(35, 30, 45, 35),
        QLineF(35, 40, 45, 35),
        QLineF(45, 30, 45, 40),
        QLineF(45, 35, 55, 35)
    };
    lines.append(lineData, 6);
    painter.drawLines(lines.data(), lines.size());

    QSGTexture *texture = window()->createTextureFromImage(image);

    for(int row = 0; row < m_model->rowCount(QModelIndex()); ++row) {
        QPoint index(m_model->data(m_model->index(row), ChipsModel::IdXRole).toInt(),
                     m_model->data(m_model->index(row), ChipsModel::IdYRole).toInt());
        QPointF pos(m_model->data(m_model->index(row), ChipsModel::XPosRole).toReal(),
                    m_model->data(m_model->index(row), ChipsModel::YPosRole).toReal());
        QColor color(m_model->data(m_model->index(row), ChipsModel::ColorRole).value<QColor>());
        node->appendChildNode(new ChipNode(pos, index, color, texture));
    }
    return node;
}


QSGNode *ChipItem::updatePaintNode(QSGNode *node, UpdatePaintNodeData *)
{
    if (!node && m_model) {
        node = createChipNodes();
    }

    return node;
}
