//
// Created by Christian Diaconu on 23/01/16.
// christian.diaconu@epitech.eu
//

#include "../JSONDocument.h"
#include <iostream>

int main() {
  JSONDocument my_profile;
  JSONDocument hobbie1;
  JSONDocument hobbie2;

  my_profile.addValue("FirstName", "Christian");
  my_profile.addValue("LastName", "Diaconu");
  my_profile.addArray("Hobbies", &hobbie1);
  my_profile.addArray("Hobbies", &hobbie2);

  // Adding first hobbie
  hobbie1.addValue("Type", "Sport");
  hobbie1.addValue("Name", "Climbing");

  // Adding second hobbie
  hobbie2.addValue("Type", "Self developement");
  hobbie2.addValue("Name", "Coding");

  /*
  * That's simply it folks !
  * You can easly imagine inherit all of your custom classes from JSONDocument
  * making them automaticaly serializable recursively, two lines of codes ;)
  */

  std::cout << my_profile.serialize() << std::endl;

  return (0);
}
