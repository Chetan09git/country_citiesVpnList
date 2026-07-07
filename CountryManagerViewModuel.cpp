#include "CountryManagerViewModuel.h"

CountryManagerViewModuel::CountryManagerViewModuel(QAbstractItemModel *parent):QAbstractListModel(parent)
{
    m_countryManager = CountryManager::init();
}

int CountryManagerViewModuel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_countryManager->getCountryList().size();
}
QVariant CountryManagerViewModuel::data(const QModelIndex &index, int role) const
{
    int row  = index.row();
    Country *country = m_countryManager->getCountry(row);
    switch(role)
    {
    case COUNTRY_NAME:
        return country->getCountry();break;
    case COUNTRY_IP:
        return country->getCountryIp();break;
    case IMAGE_PNG:
        return country->getPngPath();break;
    case RANDOM_ROLE:
        return country->getPingNumber();break;
    case CITIES_ROLE: {
        QVariantList cityList;
        for (const City *city : country->getCityList()) {
            QVariantMap map;
            map["name"] = city->getCityName();
            map["randomNumber"] = city->getPingNumber();
            cityList.append(map);
        }
        return cityList;
    }
    }
    return QVariant();
}

QHash<int, QByteArray> CountryManagerViewModuel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[COUNTRY_NAME] = "CountryName";
    roles[COUNTRY_IP] = "CountryIp";
    roles[IMAGE_PNG] = "CountryImage";
    roles[CITIES_ROLE] = "cities";
    roles[RANDOM_ROLE] = "RandomNumber";
    return roles;
}

QVariantList CountryManagerViewModuel::getSearchResults(const QString &filter) const
{
    QVariantList results;
    if (filter.isEmpty()) {
        return results;
    }

    for (Country *country : m_countryManager->getCountryList()) {
        if (country->getCountry().contains(filter, Qt::CaseInsensitive))
        {
            QVariantMap item;
            item["name"] = country->getCountry();
            item["image"] = country->getPngPath();
            item["randomNumber"] = country->getPingNumber();
            results.append(item);
        }
        for (City *city : country->getCityList()) {
            if (city->getCityName().contains(filter, Qt::CaseInsensitive)) {
                QVariantMap item;
                item["name"] = city->getCityName();
                item["image"] = country->getPngPath();
                item["randomNumber"] = city->getPingNumber();
                results.append(item);
            }
        }
    }
    return results;
}
