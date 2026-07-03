#include "SortFilterModuel.h"

SortFilterModuel::SortFilterModuel(QSortFilterProxyModel *parent) :QSortFilterProxyModel(parent)
{
    setFilterRole(5);
    setSortRole(1);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    // sort(0, Qt::AscendingOrder);
}

void SortFilterModuel::setFilterString(const QString &filter)
{
    setFilterFixedString(filter);
}

void SortFilterModuel::setSortOrder(Qt::SortOrder order)
{
    sort(0, order ? Qt::AscendingOrder
                      : Qt::DescendingOrder);
}

void SortFilterModuel::setSortType(int index)
{
    if (index == 0) {
        setSortRole(6); // RANDOM_ROLE (Ping number - Fastest first)
        sort(0, Qt::AscendingOrder);
    } else if (index == 1) {
        setSortRole(1); // COUNTRY_NAME
        sort(0, Qt::AscendingOrder);
    } else if (index == 2) {
        setSortRole(1); // COUNTRY_NAME
        sort(0, Qt::DescendingOrder);
    }
}
