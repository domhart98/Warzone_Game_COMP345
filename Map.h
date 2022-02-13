
#include <vector>
#include <iostream>
#include <list>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
//#include "Player.h"
using namespace std;


class Territory {
public:
    string name;
    int territoryNumber;
    int armyNumber;
    vector<Territory*> adjacentTerritories;
    //Player* owner;

    Territory();
    Territory(string name, int territoryNum, int armyNum);
    Territory(const Territory& territory);
    Territory& operator=(const Territory& territory);
    friend ostream& operator<<(ostream& out, const Territory& territory);
    ~Territory();
};

class Continent {
public:
    std::string name;
    int bonusPts;
    vector<Territory*> territories;

    Continent();
    Continent(std::string name, int bonusPts);
    Continent(const Continent& continent);
    Continent& operator=(const Continent& continent);
    friend ostream& operator<<(ostream& out, const Continent& continent);
    ~Continent();
};

class Edge {
public:
    Territory* start;
    Territory* stop;

    Edge();
    Edge(Territory* start, Territory* stop);
    Edge(const Edge& edge);
    Edge& operator=(const Edge& edge);
    friend ostream& operator<<(ostream& out, const Edge& edge);
    ~Edge();
};

class Map {
public:
    vector<Territory*> territories;
    vector<Continent*> continents;
    vector<Edge*> edges;

    Map();
    ~Map();
    Map(const Map& m);
    Map& operator=(const Map& m);
    void deepCopy(const Map& m);
    friend ostream& operator<<(ostream& out, const Map& m);

    vector<pair<Territory*, bool>>* getNeighbourList(Territory* t);
    void addTerritory(Territory* t, bool setStartingTerritory = false);
    void addContinent(Continent* continent);
    Continent* findContinent(Continent continent);
    Territory* findTerritory(int territoryNum);
    void addPath(Territory* start, Territory* stop, bool land);
    void displayMap();
    void searchGraph(unordered_set<string>& names, const Territory* territory);
    void searchSubGraph(unordered_set<string>& nameset, const Continent* continent, const Territory* territory);
    bool isValid();
    int isAdjacent(Territory* start, Territory* stop);
    bool areTerritoriesConnected();
    bool areContinentsConnected();
    bool eachRegionBelongsToOneContinent();
    bool validate();
};

class MapLoader {
public:
    Map* map;

    MapLoader();
    MapLoader(const MapLoader& ml);

    MapLoader& operator=(const MapLoader& ml);
    friend ostream& operator<<(ostream& out, const MapLoader& ml);
    Map* loadMap(std::string& file);
};
