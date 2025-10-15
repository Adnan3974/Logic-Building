#include <iostream>
#include<cstdlib>
#include<ctime>
#include <string>

using namespace std;

class WordMazeGame {
private:
    char** maze;
    char** dictionary;
    bool** wordFound;  // Track which positions have been found for each word
    int** wordOccurrences; // Track occurrences of each word in maze
    int mazeSize;
    int dictSize;
    int totalAttempts;
    bool hintUsed;
    time_t startTime;
   
    // Helper function to convert string to lowercase
    string toLowerCase(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }
   
    // Helper function to convert string to uppercase
    string toUpperCase(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
        return str;
    }
   
    // Generate random letter
    char getRandomLetter() {
        char ch;
        ch = 'a' + (rand() % 26);
        return ch;
    }
   
    // Check if position is valid
    bool isValidPosition(int row, int col) {
        bool pos;
        if(row >= 0 && row < mazeSize && col >= 0 && col < mazeSize)
        pos=true;
        else
        pos=false;
        return pos;
    }
   
    // Direction vectors for 8 directions
    int BackForth[8] = {-1,-1,-1,0,0,1,1,1};
    int UpDown[8] = {-1,0,1,-1,1,-1,0,1};

    void placeWordInMaze(string word, int wordIndex) {
    word = toLowerCase(word);
    int attempts = 0;
    bool placed = false;
   
    while (!placed && attempts < 1000) {
        int row = rand() % mazeSize;
        int col = rand() % mazeSize;
        int direction = rand() % 8;
       
        bool canPlace = true;
        // Check if word fits in this direction
        for (int i = 0; i < word.length(); i++) {
            int newRow = row + i * BackForth[direction];
            int newCol = col + i * UpDown[direction];
           
            if (!isValidPosition(newRow, newCol)) {
                canPlace = false;
                break;
            }
        }
       
        if (canPlace) {
            // Place the word (overwrite whatever was there)
            for (int i = 0; i < word.length(); i++) {
                int x = row + i * BackForth[direction];
                int y = col + i * UpDown[direction];
                maze[x][y] = word[i];
            }
            placed = true;
        }
        attempts++;
    }
   
    if (!placed) {
        cout << "Warning: Could not place word '" << word << "' after 1000 attempts!" << endl;
    }
}

    // Search for word from given position in all directions
    bool searchWord(string word, int startRow, int startCol, int& foundDir) {
        word = toLowerCase(word);
       
        for (int direction = 0; direction < 8; direction++) {
        bool found = true;
        for (int j = 0; j < word.length(); j++) {
            int newRow = startRow + j * BackForth[direction];
            int newCol = startCol + j * UpDown[direction];
           
            if (!isValidPosition(newRow, newCol) ||
                toLowerCase(string(1, maze[newRow][newCol])) != string(1, word[j])) {
                found = false;
                break;
            }
        }
           
            if (found) {
                foundDir = direction;
                return true;
            }
        }
        return false;
    }

    void countWordOccurrences() {
    for (int w = 0; w < dictSize; w++) {
        string word = toLowerCase(string(dictionary[w]));
        int count = 0;
       
        // Check ALL positions in the maze
        for (int i = 0; i < mazeSize; i++) {
            for (int j = 0; j < mazeSize; j++) {
                int dir;
                if (searchWord(word, i, j, dir)) {
                    count++;
                }
            }
        }
       
        wordOccurrences[w] = new int[count + 1];
        wordOccurrences[w][0] = count; // Store total count at index 0
        for (int i = 1; i <= count; i++) {
            wordOccurrences[w][i] = 0; // 0 = not found, 1 = found
        }
    }
}
    // Check if word is in dictionary
    int findWordInDictionary(string word) {
        word = toLowerCase(word);
        for (int i = 0; i < dictSize; i++) {
            if (toLowerCase(string(dictionary[i])) == word) {
                return i;
            }
        }
        return -1;
    }
   
    // Check if all words are found
    bool allWordsFound() {
        for (int w = 0; w < dictSize; w++) {
            int totalOccurrences = wordOccurrences[w][0];
            for (int i = 1; i <= totalOccurrences; i++) {
                if (wordOccurrences[w][i] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    WordMazeGame() {
        maze = nullptr;
        dictionary = nullptr;
        wordFound = nullptr;
        wordOccurrences = nullptr;
        mazeSize = 7;
        dictSize = 0;
        totalAttempts = 0;
        hintUsed = false;
        startTime = time(0);
    }
   
    ~WordMazeGame() {
        cleanup();
    }
   
    void cleanup() {
        if (maze) {
            for (int i = 0; i < mazeSize; i++) {
                delete[] maze[i];
            }
            delete[] maze;
            maze = nullptr;
        }
       
        if (dictionary) {
            for (int i = 0; i < dictSize; i++) {
                delete[] dictionary[i];
            }
            delete[] dictionary;
            dictionary = nullptr;
        }
       
        if (wordFound) {
            for (int i = 0; i < dictSize; i++) {
                delete[] wordFound[i];
            }
            delete[] wordFound;
            wordFound = nullptr;
        }
       
        if (wordOccurrences) {
            for (int i = 0; i < dictSize; i++) {
                delete[] wordOccurrences[i];
            }
            delete[] wordOccurrences;
            wordOccurrences = nullptr;
        }
    }
   
    void initializeGame() {
    cout << "=== Welcome to the \"WORD MAZE SOLVER\" ===\n";
    cout << "Enter maze size (default 7): ";
    cin >> mazeSize;
    if (mazeSize <= 0) mazeSize = 7;
   
    cout << "Enter number of dictionary words: ";
    cin >> dictSize;
   
    if (dictSize <= 0) {
        dictSize = 5; // default
        cout << "Invalid number!\nUsing 5 default words." << endl;
    }
   
    // Initialize maze with random letters FIRST
    maze = new char*[mazeSize];
    for (int i = 0; i < mazeSize; i++) {
        maze[i] = new char[mazeSize];
        for (int j = 0; j < mazeSize; j++) {
            maze[i][j] = getRandomLetter();
        }
    }
   
    dictionary = new char*[dictSize];
    wordOccurrences = new int*[dictSize];
   
    cout << "Enter " << dictSize << " dictionary words:" << endl;
    for (int i = 0; i < dictSize; i++) {
        cout << "Word " << i + 1 << ": ";
        string word;
        cin.ignore();
        getline(cin, word);
        dictionary[i] = new char[word.length() + 1];
        for (int j = 0; j < word.length(); j++) {
            dictionary[i][j] = word[j];
        }
        dictionary[i][word.length()] = '\0';
        placeWordInMaze(word, i);
    }
   
    countWordOccurrences();
   
    startTime = time(0);
    cout << "\nGame initialized! Find all the words in the maze." << endl;
}

    void displayMaze() {
        cout << "\nWords puzzle:" << endl;
            for (int j = 0; j < mazeSize; j++){
                cout<<j+1<<" ";
            }
        cout << endl;
       
        for (int i = 0; i < mazeSize; i++) {
            cout << i+1 << ": ";
            for (int j = 0; j < mazeSize; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
   
    void displayProgress() {
        cout << "\nDictionary Progress:" << endl;
        for (int i = 0; i < dictSize; i++) {
            string word = string(dictionary[i]);
            int totalOccurrences = wordOccurrences[i][0];
            int foundCount = 0;
           
            for (int j = 1; j <= totalOccurrences; j++) {
                if (wordOccurrences[i][j] == 1) {
                    foundCount++;
                }
            }
           
            cout << word << ": " << foundCount << "/" << totalOccurrences;
            if (foundCount == totalOccurrences) {
                cout << "Game ended bro!";
            }
            cout << endl;
        }
    }
   
    void giveHint() {
    if (hintUsed) {
        cout << "Uh Huh! You've already used hint." << endl;
        return;
    }
   
    // Find a random unfound word occurrence
    for (int w = 0; w < dictSize; w++) {
        int totalOccurrences = wordOccurrences[w][0];
        for (int occ = 1; occ <= totalOccurrences; occ++) {
            if (wordOccurrences[w][occ] == 0) {
                // Find this occurrence in the maze
                string word = toLowerCase(string(dictionary[w]));
                int occurrenceCount = 0;
               
                for (int i = 0; i < mazeSize; i++) {
                    for (int j = 0; j < mazeSize; j++) {
                        int dir;
                        if (searchWord(word, i, j, dir)) {
                            occurrenceCount++;
                            if (occurrenceCount == occ) {
                                cout << "HINT: " << dictionary[w];
                                hintUsed = true;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
   
    cout << "Welldone! All words have been found! No hint needed." << endl;
}

    bool playTurn() {
        string word, posInput;
        int row, col;
       
        cout << "\nEnter word to search for: ";
        cin.ignore();
        getline(cin, word);
       
        if (word.empty()) {
            cout << "Please enter a valid word." << endl;
            return false;
        }
       
        cout << "Enter starting position (row col): ";
        getline(cin, posInput);
       
        // Parse position
        int spacePos = -1;
        for (int i = 0; i < posInput.length(); i++) {
            if (posInput[i] == ' ') {
                spacePos = i;
                break;
            }
        }
       
        if (spacePos == -1) {
            cout << "Invalid position format. Use 'row col' format." << endl;
            return false;
        }
       
        string rowStr = posInput.substr(0, spacePos);
        string colStr = posInput.substr(spacePos + 1);
       
        row = 0; col = 0;
        for (int i = 0; i < rowStr.length(); i++) {
            if (rowStr[i] >= '0' && rowStr[i] <= '9') {
                row = row * 10 + (rowStr[i] - '0');
            }
        }
        for (int i = 0; i < colStr.length(); i++) {
            if (colStr[i] >= '0' && colStr[i] <= '9') {
                col = col * 10 + (colStr[i] - '0');
            }
        }
       
        totalAttempts++;
       
        // Validate position
        if (!isValidPosition(row, col)) {
            cout << "Error: Position (" << row << ", " << col << ") is out of bounds!" << endl;
            return false;
        }
       
        // Check if word is in dictionary
        int wordIndex = findWordInDictionary(word);
        if (wordIndex == -1) {
            // Check for bonus word
            int dir;
            if (searchWord(word, row, col, dir)) {
                cout << "Amazing! You discovered a hidden word: " << word << endl;
               
            } else {
                cout << "Word '" << word << "' not found from position (" << row << ", " << col << ")" << endl;
            }
            return false;
        }
       
        int foundDir;
        if (searchWord(word, row, col, foundDir)) {
            string findWord = toLowerCase(word);
            int occurrenceCount = 0;
            bool alreadyFound = false;
           
            for (int i = 0; i < mazeSize; i++) {
                for (int j = 0; j < mazeSize; j++) {
                    int foundDir;
                    if (searchWord(findWord, i, j, foundDir)) {
                        occurrenceCount++;
                        if (i == row && j == col && foundDir == foundDir) {
                            if (wordOccurrences[wordIndex][occurrenceCount] == 1) {
                                alreadyFound = true;
                            } else {
                                wordOccurrences[wordIndex][occurrenceCount] = 1;
                            }
                            break;
                        }
                    }
                }
                if (occurrenceCount > 0 && (i == row || alreadyFound)) break;
            }
           
            if (alreadyFound) {
                cout << "This occurrence of '" << word << "' has already been found!" << endl;
            } else {
                cout << "Great! Found '" << word << "' at position (" << row << ", " << col << ")" << endl;
               
                // Check if all occurrences of this word are found
                int totalOcc = wordOccurrences[wordIndex][0];
                bool allFound = true;
                for (int i = 1; i <= totalOcc; i++) {
                    if (wordOccurrences[wordIndex][i] == 0) {
                        allFound = false;
                        break;
                    }
                }
               
                if (allFound) {
                    cout << "Congratulations! You found all occurrences of " << word <<endl;
                }
            }
        }
        else {
            cout << "Word '" << word << "' not found from position (" << row << ", " << col << ")" << endl;
        }
       
        return allWordsFound();
    }
   
    void displayFinalStats() {
        time_t endTime = time(0);
        int timeTaken = endTime - startTime;
       
        cout << "Cograts! Y've won the game" << endl;
        cout << "Final Statistics:" << endl;
        cout << "Time taken: " << timeTaken << " seconds" << endl;
        cout << "Total attempts: " << totalAttempts << endl;
        cout << "Hint used: " << (hintUsed ? "Yes" : "No") << endl;
       
        cout << "\nFinal Maze (Found words in UPPERCASE):" << endl;
        displayMaze();
    }
   
    void runGame() {
        initializeGame();
       
        bool gameWon = false;
        while (!gameWon) {
            cout << "\n=== WORD MAZE MENU ===" << endl;
            cout << "1. Play the game (enter a word and position)" << endl;
            cout << "2. Get a hint" << endl;
            cout << "3. Show current maze" << endl;
            cout << "4. Show dictionary progress" << endl;
            cout << "5. Exit game" << endl;
            cout << "Choose an option (1-5): ";
            int choice;
            cin>>choice;
            switch(choice){
            case 1:
                gameWon = playTurn();
                break;
            case 2:
                giveHint();
                break;
            case 3:
                displayMaze();
                break;
            case 4:
                displayProgress();
                break;
            case 5:
                cout << "Thanks for playing! Goodbye!" << endl;
                break;
            }
        }
        if (gameWon) {
            displayFinalStats();
        }
    }
};

int main() {
    WordMazeGame game;
    game.runGame();
    return 0;
}


