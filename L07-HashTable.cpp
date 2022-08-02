//Lab 7
//Thuy Uyen My Tran

#include <iostream>
#include <fstream> // file
#include <string>
#define HASHSIZE 4001
std::ifstream myfile;
std::string word;

//Function to calculate ascii value
int hashKey(std::string str) {
    int key = 0;
    for (int i = 0; i < str.length(); i++) {
        char x = str.at(i);
        key = key + int(x);
    }
    return key;
}

//Create a hasharray class
class HashArray {
private:
    int num, size, probe;
public:
    struct Entry {
        std::string word;
        int freq; //frequency
    };
    Entry hashArr[HASHSIZE];
    int updates[HASHSIZE];
    int cost[HASHSIZE];

    HashArray() {
        size = 0;
        probe = 0;
        num = 0;
        for (int i = 0; i < HASHSIZE; i++) {
            hashArr[i].freq = 0;
            updates[i] = 0;
            cost[i] = 0;
        }
    };

    ~HashArray() {}

    //Function to store word in the hashtable
    void update(std::string s1) {

        int key = hashKey(s1);
        probe = 0;
        num = 0;
        if (hashArr[key].freq == 0) {
            hashArr[key].word = s1;
            hashArr[key].freq = 1;
            size++;
            probe++;
            num++;
        }
      
        else if (hashArr[key].word == s1) {
            hashArr[key].freq++;
            probe++;
        }
       
        else {
            //linear probbing
            while (hashArr[key].freq != 0 && hashArr[key].word != s1) {
                key++;
                probe++;
                if (key > 4000)
                    key = 0;
            }

            if (hashArr[key].word == s1) {
                hashArr[key].freq++;
                probe++;
            }
            else {
                hashArr[key].word = s1;
                hashArr[key].freq++;
                size++;
                probe++;
                num++;
            }
        }
        cost[size] = probe;
        updates[size] = num;
    }

    void hashSize() {
        std::cout << "Number of unique words: " << size << std::endl;
    }
    void probes() {
        std::cout << "Number of probes: " << probe << std::endl;
    }

    void ratios() {
        for (int i = 0; i < size ; i++) {
            if (updates[i] != 0 ) {
                float ratio = (float)cost[i] / updates[i];
                std::cout << cost[i] << ":" << updates[i] << " ";
                std::cout << "cost|" << i << "| /updates|" << i << "] =" << (float)ratio /100<< " , " << std::endl;
            }
        }
    }
};

int main() {
    std::cout << ">";
    HashArray h_array;
    myfile.open("RomeoAndJuliet.txt"); //XCode IDE

    if (myfile.is_open()) {
        while (!myfile.eof()) {
            myfile >> word;
            h_array.update(word);

        }
        h_array.hashSize();
        h_array.ratios();
    }

    myfile.close();
    return 0;
}
