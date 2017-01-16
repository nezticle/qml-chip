#ifndef CHIPNODE_H
#define CHIPNODE_H

#include <QtQuick/QSGNode>
#include <QtQuick/QSGTexture>

class ChipNode : public QSGNode
{
public:
    ChipNode(const QPointF &pos, const QPoint &index, const QColor &color, QSGTexture *texture);
};

#endif // CHIPNODE_H
