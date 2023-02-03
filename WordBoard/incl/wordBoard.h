#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>

class WordBoard
{
    public:
    
        //possible directions for words to be in board
        enum Direction
        {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            UPRIGHT,
            DOWNRIGHT,
            DOWNLEFT,
            UPLEFT,
            MAXSIZE
        };
        
        //constructor for class for brand new board 
        WordBoard(int height, int width);
        
        //constructor for class for using an existing board
        //WordBoard(std::vector<std::vector<char>> wordBoard_, std::unordered_map<std::string, Word>);

        //creates the board with previous constructed items
        void createBoard(std::vector<std::string> words);

        //checks to see if given word exists within the board
        bool checkWord(const std::string word, const std::pair<uint32_t,uint32_t> position, const Direction dir);

        //saves the board for future games
        void saveBoard();

        //prints the created board to screen
        void printBoard();


    private:

        //checks to see if random placement works with current board
        bool validPlacement(const std::string& word, std::pair<uint32_t,uint32_t> position, const Direction& dir);

        //insertes the word with random placement on board
        void placeWordOnBoard(const std::string& word, std::pair<uint32_t,uint32_t> position, const Direction& dir);

        //increments an x and/or y value depending on the given direction
        void incrementBoardPos(std::pair<uint32_t,uint32_t>& position, const Direction& dir);

        //fills spaces not taken by letters with random ones
        void fillRestOfBoard();

        //struct used for checking to see if word exists on board
        struct Word
        {
            Word(std::pair<uint32_t,uint32_t> position, Direction dir);
            std::pair<uint32_t,uint32_t> position;
            Direction dir;
        };

        //word List that fluctuates with the user finding words
        std::unordered_set<std::string> wordList_;
        
        //map of all words and there possitions on the board
        std::unordered_map<std::string, Word> wordsInBoard_;

        //the wordboard itself
        std::vector<std::vector<char>> wordBoard_;
};