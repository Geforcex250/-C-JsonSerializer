//
// Created by diacon_c on 23/01/16.
//

#include <iostream>
#include "JSONDocument.h"

JSONDocument::JSONDocument() {
    this->buffer = NULL;
}

JSONDocument::~JSONDocument() {
    if (this->buffer != NULL)
        delete this->buffer;
}

void JSONDocument::addObject(const std::string &key, JSONDocument *object) {
    this->object_values[key] = object;
}

JSONDocument *JSONDocument::getObject(const std::string &key) const {
    return (this->object_values.at(key));
}

void JSONDocument::deleteObject(const std::string &key) {
    this->object_values.erase(key);
}

void JSONDocument::addValue(const std::string &key, const std::string &value) {
    this->simple_values[key] = value;
}

std::string JSONDocument::getValue(const std::string &key) const {
    return (this->simple_values.at(key));
}

void JSONDocument::deleteValue(std::string key) {
    this->object_values.erase(key);
}

void JSONDocument::addArray(const std::string &key, JSONDocument *document) {
    this->array_values[key].push_back(document);
}


/* JSON Generator - Sys FXs */


void JSONDocument::bufferGenerator_Values() {
    unsigned long int i = 0;

    // Lets save simple values !
    typedef std::map<std::string, std::string>::iterator simple_IT;
    for(simple_IT iterator = this->simple_values.begin(); iterator != this->simple_values.end(); iterator++) {

        // Compose element in JSON !
        this->buffer->append("\"" + iterator->first + "\":\"" + iterator->second + "\"");
        // Add semi-colomuns when needed
        if (i++ != (this->simple_values.size() - 1) || this->object_values.size() != 0)
            buffer->append(",");

    }
}

void JSONDocument::bufferGenerator_Objects() {
    unsigned long int i =  0;

    // Lets save object values !
    typedef std::map<std::string, JSONDocument *>::iterator object_IT;
    for(object_IT iterator = this->object_values.begin(); iterator != this->object_values.end(); iterator++) {

        // Compose element in JSON !
        this->buffer->append("\"" + iterator->first + "\":" + (iterator->second->serialize()));
        // Add semi-colomuns when needed
        if (i++ != (this->object_values.size() - 1) || this->array_values.size() != 0)
            buffer->append(",");
    }
}


void JSONDocument::bufferGenerator_Arrays() {
    unsigned long int i =  0;
    unsigned long int i2 = 0;

    // Lets save arrays values !
    typedef std::map<std::string, std::vector<JSONDocument *>>::iterator array_IT;
    for(array_IT iterator = this->array_values.begin(); iterator != this->array_values.end(); iterator++) {

        this->buffer->append("\"" + iterator->first + "\":[");
        while (i2 != iterator->second.size())
        {
            this->buffer->append(iterator->second.at(i2)->serialize());

            // Add semi-colomuns when needed
            if (i2++ != (iterator->second.size() - 1))
                buffer->append(",");
        }
        this->buffer->append("]");

        // Add semi-colomuns when needed
        if (i++ != (this->object_values.size() - 1))
            buffer->append(",");
    }
}


/* JSON Main call */
std::string &JSONDocument::serialize() {
    if (buffer == NULL)
        buffer = new std::string;

    buffer->append("{");
    this->bufferGenerator_Values();
    this->bufferGenerator_Objects();
    this->bufferGenerator_Arrays();
    buffer->append("}");

    return (*buffer);
}

JSONDocument &JSONDocument::operator=(JSONDocument &document) {
    (void)document;
    return (*this);
}

JSONDocument::JSONDocument(JSONDocument &document) {
    (void)document;
}
