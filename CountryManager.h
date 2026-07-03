#ifndef COUNTRYMANAGER_H
#define COUNTRYMANAGER_H

#include "Country.h"
#include <QObject>
#include <QMap>
#include "FileReader.h"

class CountryManager : public QObject
{
    Q_OBJECT
    explicit CountryManager(QObject *parent = nullptr);
public:

    ~CountryManager()override;

    QMap<int, Country *> getCountryList() const;
    // const QMap<QString, QString> &getCountryCityListMap() const;
    void addToSearchList();
    void displayList();

    static CountryManager *init();
    Country *getCountry(int index);

    void addCountry(QString newCountryName, int newcountryIp, QString newImgPage);
    QString getCountryCityList(int index) const;

signals:
    void countryAdded(const QString &newCountryName);

private:

    static CountryManager *m_countryManager;

    void countryInitializer();
    Country *m_Country;
    FileReader *m_fileReder;
    QMap<int,Country*> m_countryList;
    // QMap<QString,QString> M_countryCityList;
};

#endif // COUNTRYMANAGER_H
