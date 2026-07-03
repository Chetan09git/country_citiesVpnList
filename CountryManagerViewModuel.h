#ifndef COUNTRYMANAGERVIEWMODUEL_H
#define COUNTRYMANAGERVIEWMODUEL_H
#include <QAbstractListModel>
#include "CountryManager.h"

class CountryManagerViewModuel : public QAbstractListModel
{
public:
    enum CountryRole {
        COUNTRY_NAME = 1,
        COUNTRY_IP,
        IMAGE_PNG,
        CITIES_ROLE,
        SEARCH_ROLE,
        RANDOM_ROLE
    };
    explicit CountryManagerViewModuel(QAbstractItemModel *parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE QVariantList getSearchResults(const QString &filter) const;

private:
    Q_OBJECT
    CountryManager *m_countryManager;
};

#endif // COUNTRYMANAGERVIEWMODUEL_H
