#include "mainwindowlogerro.h"

mainwindowLogErro::mainwindowLogErro(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant mainwindowLogErro::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex mainwindowLogErro::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex mainwindowLogErro::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int mainwindowLogErro::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int mainwindowLogErro::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant mainwindowLogErro::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
