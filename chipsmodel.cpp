#include "chipsmodel.h"

#include <QImage>

ChipsModel::ChipsModel(QObject *parent)
    : QAbstractListModel(parent)
{
    generateData();
}

int ChipsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

QVariant ChipsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > m_data.count())
        return QVariant();

    switch (role) {
    case IdXRole:
        return QVariant::fromValue(m_data[index.row()].idX);
    case IdYRole:
        return QVariant::fromValue(m_data[index.row()].idY);
    case XPosRole:
        return QVariant::fromValue(m_data[index.row()].xPos);
    case YPosRole:
        return QVariant::fromValue(m_data[index.row()].yPos);
    case ColorRole:
        return QVariant::fromValue(m_data[index.row()].color);
    case SelectedRole:
        return QVariant::fromValue(m_data[index.row()].selected);
    default:
        break;
    }
    return QVariant();
}

bool ChipsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() > m_data.count())
        return false;


    switch (role) {
    case IdXRole:
        return false;
    case IdYRole:
        return false;
    case XPosRole:
        m_data[index.row()].xPos = value.toReal();
        return true;
    case YPosRole:
        m_data[index.row()].xPos = value.toReal();
        return true;
    case ColorRole:
        m_data[index.row()].color = value.value<QColor>();
        return true;
    case SelectedRole:
        m_data[index.row()].selected = value.toBool();
        return true;
    default:
        break;
    }
    return false;
}

QHash<int, QByteArray> ChipsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdXRole] = "idX";
    roles[IdYRole] = "idY";
    roles[XPosRole] = "xPos";
    roles[YPosRole] = "yPos";
    roles[ColorRole] = "color";
    roles[SelectedRole] = "selected";
    return roles;
}

void ChipsModel::generateData()
{
    QImage image(":/qt4logo.png");

    // Populate scene
    int xx = 0;
    int nitems = 0;
    for (int i = -11000; i < 11000; i += 110) {
        ++xx;
        int yy = 0;
        for (int j = -7000; j < 7000; j += 70) {
            ++yy;
            qreal x = (i + 11000) / 22000.0;
            qreal y = (j + 7000) / 14000.0;

            QColor color(image.pixel(int(image.width() * x), int(image.height() * y)));

            ChipData chip;
            chip.color = color;
            chip.idX = xx;
            chip.idY = yy;
            chip.xPos = i;
            chip.yPos = j;
            chip.selected = false;

            m_data.append(chip);

            ++nitems;
        }
    }
}
