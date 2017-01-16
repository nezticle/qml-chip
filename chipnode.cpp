#include "chipnode.h"
#include <QSGTransformNode>
#include <QtQuick/QSGSimpleRectNode>
#include <QtQuick/QSGSimpleTextureNode>

ChipNode::ChipNode(const QPointF &pos, const QPoint &index, const QColor &color, QSGTexture *texture)
{
    // Create Transform node
    auto transformNode = new QSGTransformNode();
    QMatrix4x4 matrix;
    matrix.translate(pos.x(), pos.y());
    transformNode->setMatrix(matrix);
    this->appendChildNode(transformNode);

    // Create Content
    auto rectangleNode = new QSGSimpleRectNode();
    rectangleNode->setRect(QRectF(14, 14, 79, 39));
    rectangleNode->setColor(color);
    transformNode->appendChildNode(rectangleNode);

    auto textureNode = new QSGSimpleTextureNode();
    textureNode->setTexture(texture);
    textureNode->setOwnsTexture(false);
    textureNode->setRect(QRectF(0, 0, 110, 70));
    transformNode->appendChildNode(textureNode);

}
