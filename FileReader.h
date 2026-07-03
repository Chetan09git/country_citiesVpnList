#ifndef FILEREADER_H
#define FILEREADER_H

#include <QtCore/qobject.h>

class CountryManager;

class FileReader {
public:
  virtual ~FileReader() {};

  virtual bool writeJson(const QString &fileName, CountryManager *manager) = 0;
  virtual bool readJson(const QString &fileName, CountryManager *manager) = 0;
};

#endif // FILEREADER_H
