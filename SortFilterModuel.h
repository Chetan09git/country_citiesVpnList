#ifndef SORTFILTERMODUEL_H
#define SORTFILTERMODUEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class SortFilterModuel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit SortFilterModuel(QSortFilterProxyModel *parent = nullptr);

    Q_INVOKABLE void setFilterString(const QString &filter);
    Q_INVOKABLE void setSortType(int index);
};

#endif // SORTFILTERMODUEL_H
