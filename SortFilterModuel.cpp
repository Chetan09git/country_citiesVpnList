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

void SortFilterModuel::setSortType(int index)
{
    switch(index)
    {
    case 0:
        setSortRole(5);sort(0, Qt::AscendingOrder);break;
    case 1:
        setSortRole(1);sort(0, Qt::AscendingOrder);break;
    case 2:
        setSortRole(1);sort(0, Qt::DescendingOrder);break;
    default:
        setSortRole(1);sort(0, Qt::AscendingOrder);break;
    }
}
