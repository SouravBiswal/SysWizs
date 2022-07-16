#include <iostream>
#include <stdlib.h>

using namespace std;

int buildTag()
{
    string tagName;

    cin >> tagName;

    /*fetch map from database and check if tag already exists
    if yes, throw error, else create new tag
    */

    string fileName, filePath;

    cin >> fileName;
    cin >> filePath;

    // Add filename and filepath to the map

    return 0;
}

int getFiles()
{
    string tag;

    cin >> tag;

    // Check if tag is present in map, if not give error, else fetch the files and return them

    return 0;
}

int addFilestoTag()
{
    string tagName;
    cin >> tagName;
    // Check if tag exists, if not, ask to create one first else proceed

    // Currently we are accepting only one file at a time, later will scale to many at a time

    string fileName, filePath;

    cin >> fileName;
    cin >> filePath;

    // map.get(tag).add(new Pair{fileName,filePath});

    return 0;
}

int deleteTag()
{
    string tagName;
    cin >> tagName;

    // map.remove(tagName);
    return 0;
}

int removeTagFromFile()
{
    string fileName;
    cin >> fileName;

    string tagName;
    cin >> tagName;

    /* This is incomplete
     */

    // if (map.contains(tagName))
    //     if (map.get(tagName))
}
