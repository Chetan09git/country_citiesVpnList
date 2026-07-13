#include "CountryManager.h"
#include "JsonFileManager.h"
#include <QDebug>
#include <QTimer>

CountryManager *CountryManager::m_countryManager = nullptr;

CountryManager::CountryManager(QObject *parent) : QObject{parent} {
  // countryInitializer();
  if(!m_fileReder)
      m_fileReder = new JsonFileManager;

  // m_fileReder->writeDta("CountryData.json", this);
  m_fileReder->readData("CountryData.json",this);
}

QMap<int, Country *> CountryManager::getCountryList() const {
  return m_countryList;
}

void CountryManager::addCountry(QString newCountryName, int newcountryIp,
                                QString newImgPage) {
  m_Country = new Country(newCountryName, newcountryIp, newImgPage);
  m_countryList.insert(newcountryIp, m_Country);
  emit countryAdded(newCountryName);
}

CountryManager *CountryManager::init() {
  if (m_countryManager == nullptr) {
    m_countryManager = new CountryManager;
    return m_countryManager;
  } else {
    return m_countryManager;
  }
}

Country *CountryManager::getCountry(int index) {
  return m_countryList.values().at(index);
}

void CountryManager::countryInitializer()
{
    addCountry("India", 91, "qrc:/Png/india.png");
    addCountry("United States", 1, "qrc:/Png/united-states.png");
    addCountry("United Kingdom", 44, "qrc:/Png/united-kingdom.png");
    addCountry("Canada", 11, "qrc:/Png/canada.png");
    addCountry("Australia", 61, "qrc:/Png/australia.png");
    addCountry("Germany", 49, "qrc:/Png/germany.png");
    addCountry("France", 33, "qrc:/Png/france.png");
    addCountry("Japan", 81, "qrc:/Png/japan.png");
    addCountry("China", 86, "qrc:/Png/china.png");
    addCountry("Brazil", 55, "qrc:/Png/brazil.png");
    addCountry("Russia", 7, "qrc:/Png/russia.png");
    addCountry("Italy", 39, "qrc:/Png/italy.png");
    addCountry("Spain", 34, "qrc:/Png/spain.png");
    addCountry("South Korea", 82, "qrc:/Png/south-korea.png");
    addCountry("Mexico", 52, "qrc:/Png/mexico.png");
    addCountry("Singapore", 65, "qrc:/Png/singapore.png");
    addCountry("Netherlands", 31, "qrc:/Png/netherlands.png");
    addCountry("Sweden", 46, "qrc:/Png/sweden.png");
    addCountry("Norway", 47, "qrc:/Png/norway.png");
    addCountry("South Africa", 27, "qrc:/Png/south-africa.png");

    Country *country;

    country = m_countryList.value(44);
    country->addCity("London", 441);
    country->addCity("Birmingham", 442);
    country->addCity("Manchester", 443);
    country->addCity("Liverpool", 444);
    country->addCity("Leeds", 445);
    country->addCity("Glasgow", 446);
    country->addCity("Edinburgh", 447);
    country->addCity("Bristol", 448);
    country->addCity("Cardiff", 449);
    country->addCity("Belfast", 450);

    country = m_countryList.value(11);
    country->addCity("Toronto", 111);
    country->addCity("Vancouver", 112);
    country->addCity("Montreal", 113);


    country = m_countryList.value(49);
    country->addCity("Berlin", 491);
    country->addCity("Munich", 492);
    country->addCity("Hamburg", 493);

    country = m_countryList.value(33);
    country->addCity("Paris", 331);
    country->addCity("Lyon", 332);
    country->addCity("Marseille", 333);

    country = m_countryList.value(81);
    country->addCity("Tokyo", 811);
    country->addCity("Osaka", 812);
    country->addCity("Kyoto", 813);

    country = m_countryList.value(86);
    country->addCity("Beijing", 861);
    country->addCity("Shanghai", 862);
    country->addCity("Shenzhen", 863);

    country = m_countryList.value(55);
    country->addCity("Sao Paulo", 551);
    country->addCity("Rio de Janeiro", 552);
    country->addCity("Brasilia", 553);

    country = m_countryList.value(7);
    country->addCity("Moscow", 71);
    country->addCity("Saint Petersburg", 72);
    country->addCity("Kazan", 73);

    country = m_countryList.value(39);
    country->addCity("Rome", 391);
    country->addCity("Milan", 392);
    country->addCity("Venice", 393);

    country = m_countryList.value(34);
    country->addCity("Madrid", 341);
    country->addCity("Barcelona", 342);
    country->addCity("Valencia", 343);

    country = m_countryList.value(82);
    country->addCity("Seoul", 821);
    country->addCity("Busan", 822);
    country->addCity("Incheon", 823);

    country = m_countryList.value(52);
    country->addCity("Mexico City", 521);
    country->addCity("Guadalajara", 522);
    country->addCity("Monterrey", 523);

    country = m_countryList.value(65);
    country->addCity("Central", 651);
    country->addCity("Jurong", 652);
    country->addCity("Woodlands", 653);

    country = m_countryList.value(31);
    country->addCity("Amsterdam", 311);
    country->addCity("Rotterdam", 312);
    country->addCity("The Hague", 313);

    country = m_countryList.value(46);
    country->addCity("Stockholm", 461);
    country->addCity("Gothenburg", 462);
    country->addCity("Malmo", 463);

    country = m_countryList.value(47);
    country->addCity("Oslo", 471);
    country->addCity("Bergen", 472);
    country->addCity("Trondheim", 473);

    country = m_countryList.value(27);
    country->addCity("Johannesburg", 271);
    country->addCity("Cape Town", 272);
    country->addCity("Durban", 273);

    country = m_countryList.value(1);
    country->addCity("New York", 101);
    country->addCity("Los Angeles", 102);
    country->addCity("Chicago", 103);
    country->addCity("Houston", 104);
    country->addCity("Phoenix", 105);
    country->addCity("Philadelphia", 106);
    country->addCity("San Antonio", 107);
    country->addCity("San Diego", 108);
    country->addCity("Dallas", 109);
    country->addCity("San Jose", 110);

      int seqNum = 100;
      for (Country *c : m_countryList.values()) {
        c->setPingNumber(seqNum);
        QList<City *> cities = c->getCityList();
        for (int i = 0; i < cities.size(); ++i) {
          if (i == 0) {
            cities[i]->setPingNumber(seqNum);
          } else {
            cities[i]->setPingNumber(++seqNum);
          }
        }
        seqNum++;
      }
}

CountryManager::~CountryManager() {
  for (auto countryList : m_countryList)
    {
    delete countryList;
  }
  m_countryList.clear();
  delete m_Country;
}
