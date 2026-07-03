#include "JsonFileManager.h"
#include "CountryManager.h"
#include "Country.h"
#include "City.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDir>

bool JsonFileManager::writeJson(const QString &fileName,
                                CountryManager *manager)
{
    QJsonArray countryArray;

    QMap<int, Country*> countryMap =
        manager->getCountryList();

    for(auto it = countryMap.begin();
         it != countryMap.end();
         ++it)
    {
        Country *country = it.value();

        QJsonObject countryObject;

        countryObject["countryName"] =
            country->getCountry();

        countryObject["countryCode"] =
            country->getCountryIp();
        countryObject["pngPath"] = country->getPngPath();

        QJsonArray cityArray;

        for(City *city : country->getCityList())
        {
            QJsonObject cityObject;

            cityObject["cityName"] =
                city->getCityName();

            cityObject["cityCode"] =
                city->getPinCode();

            cityArray.append(cityObject);
        }

        countryObject["cities"] = cityArray;

        countryArray.append(countryObject);
    }

    QJsonObject root;
    root["countries"] = countryArray;

    QFile file(fileName);


    if(!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    qDebug() << "Current Path:"
             << QDir::currentPath();
    file.write(
        QJsonDocument(root).toJson()
        );

    file.close();

    return true;
}


bool JsonFileManager::readJson(const QString &fileName,
                               CountryManager *manager)
{
    QFile file(fileName);


    if (!file.open(QIODevice::ReadOnly))
        return false;

    QJsonArray countries =
        QJsonDocument::fromJson(file.readAll())
            .object()["countries"]
            .toArray();

    for (const auto &countryVal :  countries)
    {
        auto countryObj = countryVal.toObject();

        manager->addCountry(
            countryObj["countryName"].toString(),
            countryObj["countryCode"].toInt(),
            countryObj["pngPath"].toString());

        Country *country =
            manager->getCountryList()
                .value(countryObj["countryCode"].toInt());

        for (const auto &cityVal :
             countryObj["cities"].toArray())
        {
            auto cityObj = cityVal.toObject();

            country->addCity(
                cityObj["cityName"].toString(),
                cityObj["cityCode"].toInt());
        }
    }

    return true;
}