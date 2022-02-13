#include "Map.h"


int main() {
    MapLoader* ml = new MapLoader();
    Map* map = new Map();
    string filename = "europe.map";
    
    //load correct map, validate and display
    map = ml->loadMap(filename);
    map->validate();
    cout << *map;
    //load incorrect map, validate and display
    filename = "europe-incorrect.map";
    map = ml->loadMap(filename);
    map->validate();
    cout << *map;
    //load unrelated text file, show that code stilll runs
    filename = "test.txt";
    map = ml->loadMap(filename);
    map->validate();
    cout << *map;
}
