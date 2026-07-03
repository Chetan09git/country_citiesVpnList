#ifndef JSONFILEMANAGER_H
#define JSONFILEMANAGER_H

#include "FileReader.h"
#include <QObject>

// class CountryManager;

class JsonFileManager : public FileReader {
public:
  bool writeJson(const QString &fileName, CountryManager *manager);
  bool readJson(const QString &fileName, CountryManager *manager);
};

#endif