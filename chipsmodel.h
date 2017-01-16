#ifndef CHIPSMODEL_H
#define CHIPSMODEL_H

#include <QAbstractListModel>

#include <QColor>

class ChipsModel : public QAbstractListModel
{
    Q_OBJECT
    struct ChipData {
        int idX;
        int idY;
        qreal xPos;
        qreal yPos;
        QColor color;
        bool selected;
    };

public:
    enum ChipRoles {
        IdXRole = Qt::UserRole + 1,
        IdYRole,
        XPosRole,
        YPosRole,
        ColorRole,
        SelectedRole
    };

    ChipsModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QHash<int, QByteArray> roleNames() const;

private:
    void generateData();
    QVector<ChipData> m_data;
};

#endif // CHIPSMODEL_H
