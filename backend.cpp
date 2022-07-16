#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <set>

using namespace std;


void insertValue(map<string, set<string> >& myMap)
{
   // Check whether there is already a set given the key.
   // If so, insert to the existing set.
   // Otherwise, create a set and add it to the map.
    string tagName,filePath,key,value;
    cin >> tagName;                 //Take tag name from user
    cin >> filePath;//Take file path from user
    key=tagName;
    value=filePath;
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

void getFiles(map<string, set<string> > myMap)
{
    string tag;

    cin >> tag;
   if ( myMap[tag].size()>0 )
   {
      //cout << "Print the present sets";
      //for(auto& it : myMap[tag])
        //cout<<it<<" ";
   }
   else
   {
      //cout << "no such tag available";
   }// Check if tag is present in map, if not give error, else fetch the files and return them

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
    int n=0;



    map <string,set <string> > myMap;

    while(n!=4)
    {cin>>n;
    switch(n)
    {
        case 1:
           insertValue(myMap);
        break;
        case 2:
            getFiles(myMap);
            break;
        case 3:
            removeTagFromFile();
            break;
        default:
            cout<<"Ended"<<endl;
    }
    }
}
