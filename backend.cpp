#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <set>

using namespace std;


void insertValue(map<string, set<string> >& myMap, string const& key,
                    string const& value)
{
   // Check whether there is already a set given the key.
   // If so, insert to the existing set.
   // Otherwise, create a set and add it to the map.

   map<string, set<string> >::iterator found = myMap.find(key);
   if ( found != myMap.end() )
   {
      //cout << "Adding '" << value << "' to an existing set of " << key << "s.\n";
      found->second.insert(value);
   }
   else
   {
      //cout << "Adding '" << value << "' to a new set of " << key << "s.\n";
      set<string> temp;
      temp.insert(value);
      myMap.insert(make_pair(key, temp));
   }
}

void getFiles()
{
    string tag;

    cin >> tag;

    // Check if tag is present in map, if not give error, else fetch the files and return them

}

void removeTagFromFile()
{

    /* This is incomplete
     */

    // if (map.contains(tagName))
    //     if (map.get(tagName))
}

int main()
{
    string tagName;
    string filePath;

    map <string,set <string> > myMap;

    cin >> tagName;                 //Take tag name from user
    cin >> filePath;                //Take file path from user
    insertValue(myMap,tagName, filePath);
}