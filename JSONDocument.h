//
// Created by Christian Diaconu on 23/01/16.
// christian.diaconu@epitech.eu
//

#ifndef C_JSONSERIALIZER_JSONDOCUMENT_H
#define C_JSONSERIALIZER_JSONDOCUMENT_H

#include <string>
#include <vector>
#include <map>

class JSONDocument {
private:
    std::map<std::string, std::string> simple_values;
    std::map<std::string, std::vector<JSONDocument *> > array_values;
    std::map<std::string, JSONDocument *> object_values;
    std::string *buffer;

private:
    void bufferGenerator_Objects();
    void bufferGenerator_Values();
    void bufferGenerator_Arrays();
    JSONDocument &operator=(JSONDocument&);
    JSONDocument(JSONDocument&);

public:
    JSONDocument();
    ~JSONDocument();

public:
    void addObject(const std::string &key, JSONDocument *object);
    JSONDocument *getObject(const std::string &key) const;
    void deleteObject(const std::string &key);

    void addArray(const std::string &key, JSONDocument *document);

    void addValue(const std::string &key, const std::string &value);
    std::string getValue(const std::string &key) const;
    void deleteValue(std::string key);

    std::string &serialize();
};


#endif //C_JSONSERIALIZER_JSONDOCUMENT_H
