#include <iostream>
#include <string>

using namespace std;
// Constant variable used to keep track of the length of all arrays
const int NUM_OF_HEROES = 10;

// Function Prototypes
void toUpperCase(string& str);
void searchByName(const string& heroSearch, const string names[], const int NUM_OF_HEROES);
void findBySuperpower(const string& superpowerSearch, const string names[], const string superpowers[], const int NUM_OF_HEROES);
void sortAlphabetically(string names[], const int NUM_OF_HEROES);
void displayAll(const string names[], const int NUM_OF_HEROES, bool toUpper);

int main() {

    //Preloaded superhero data in parallel arrays
    string names[NUM_OF_HEROES] = { "Matter Eater Lad", "The Red Bee", "Spring-Heeled Jack", "Squirrel Girl", "Vibe", "Bouncing Boy", "Cypher", "Dazzler", "Color Kid", "Almighty Dollar"};
    string superpowers[NUM_OF_HEROES] = { "Consume any substance", "Controls Bees", "Leaps great distances", "Controls Squirrels", "Break dancing hero", "Transforms into bouncy ball", "Can decipher any language", 
    "Converts vibrations to energy", "Changes object's colors", "Shoots pocket change"};
    string weaknesses[NUM_OF_HEROES] = { "Invisibility", "Bug Spray", "Heights", "Time limits", "Silence", "Electricity", "Sleep", "Water", "Distance", "Fire"};
    
    // Multidimensional arrays
    int years[NUM_OF_HEROES][1] = {{1962}, {1940}, {2006}, {1991}, {1984}, {1961}, {1984}, {1980}, {1966}, {1992}};
    string universes[NUM_OF_HEROES][1] = {{"DC"}, {"DC"}, {"DC"}, {"Marvel"}, {"DC"}, {"DC"}, {"Marvel"}, {"Marvel"}, {"DC"}, {"Marvel"}};

    // Variable used to store hero to search
    string heroSearch;
    // Prompt user for heroSearch    
    cout << "Enter Superhero name to search: ";
    // Store input in heroSearch
    getline(cin, heroSearch);
    cout << endl;

    // Function call to search the names array for inputted hero
    searchByName(heroSearch, names, NUM_OF_HEROES);

    // Variable used to store superpower to search
    string superpowerSearch;
    // Prompt user for superpowerSearch
    cout << "Enter Superpower to search: ";
    // To ignore the newline character left in the input buffer
    cin.ignore();
    // Store input in superpowerSearch 
    getline(cin, superpowerSearch);
    cout << endl;

    // Function call to search the names array for inputted superpower
    findBySuperpower(superpowerSearch, names, superpowers, NUM_OF_HEROES);

    cout << "\nSuperheroes sorted alphabetically:\n";
    // Function call to display superheroes in alphabetical order
    sortAlphabetically(names, NUM_OF_HEROES);
    // Function call to display all values in names array
    displayAll(names, NUM_OF_HEROES, false);

    cout << "\nSuperheroes in uppercase:\n";
    // Function call to display all values in names array in uppercase format
    displayAll(names, NUM_OF_HEROES, true);

    return 0;
}

// Function Definitions

// Function used in displayAll function to format strings to uppercase
void toUpperCase(string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}

// Function performs a case-insensitive search in the names array for a given superhero
void searchByName(const string& heroSearch, const string names[], const int NUM_OF_HEROES) {

    // Converts given superhero to lowercase to ensure search is case-insensitive
    string lowerHeroSearch = heroSearch;
    for (char& c : lowerHeroSearch) {
        c = tolower(c);
    }

    // Boolean used to determine if a match was found or not
    bool found = false;

    // Iterates through the names array and converts each name to lowercase at each iteration
    for (int i = 0; i < NUM_OF_HEROES; ++i) {
        string lowerName = names[i];
        for (char& c : lowerName) {
            c = tolower(c);
        }

        // Compares the current converted lowercase array element with the lowercase converted given superhero
        if (lowerName == lowerHeroSearch) {
            // If a match is found it displays it
            cout << "Found: " << names[i] << endl;
            found = true;
            break;
        }
    }
    // If no matches were found, a message is displayed accordingly
    if (!found) {
        cout << "Superhero not found." << endl;
    }
}

// Function performs a case-insensitive search in the names and superpowers array to find a superhero with the related given superpower
void findBySuperpower(const string& superpowerSearch, const string names[], const string superpowers[], const int NUM_OF_HEROES) {
    // Converts given superpower to lowercase to ensure search is case-insensitive
    string lowerSuperpowerSearch = superpowerSearch;
    for (char& c : lowerSuperpowerSearch) {
        c = tolower(c);
    }

    // Boolean used to determine if a match was found or not
    bool found = false;

    // Iterates through the superpowers array and converts each superpower to lowercase at each iteration
    for (int i = 0; i < NUM_OF_HEROES; ++i) {
        string lowerSuperpower = superpowers[i];
        for (char& c : lowerSuperpower) {
            c = tolower(c);
        }

        // Checks if the lowercase version of the current superpower contains the lowercase search term as a substring
        if (lowerSuperpower.find(lowerSuperpowerSearch) != string::npos) {
            // If a match is found, original superpower and corresponding superhero are displayed
            cout << "Superhero with superpower '" << superpowers[i] << "': " << names[i] << endl;
            found = true;
        }
    }
    // If no matches were found, a message is displayed accordingly
    if (!found) {
        cout << "No superheroes found with the superpower '" << superpowerSearch << "'." << endl;
    }
}

// Function sorts the names array in alphabetical order
void sortAlphabetically(string names[], const int NUM_OF_HEROES) {
    for (int i = 0; i < NUM_OF_HEROES - 1; ++i) {
        for (int j = 0; j < NUM_OF_HEROES - i - 1; ++j) {
            if (names[j] > names[j + 1]) {
                // Swap names[j] and names[j + 1]
                string temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

// Function prints all superhero names in the names array with a boolean option to format them to all uppercase characters
void displayAll(const string names[], const int NUM_OF_HEROES, bool toUpper) {
    for (int i = 0; i < NUM_OF_HEROES; ++i) {
        string name = names[i];
        // Function call to toUpperCase if boolean option is set to true
        if (toUpper) {
            toUpperCase(name);
        }
        cout << name << endl;
    }
}
   