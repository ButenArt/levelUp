#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <ctime>
#include <stdio.h>
#include <windows.h>

std::string conv_word (const std::string& word);
std::unordered_map<std::string, int> take_map(const char* file_name);
/*******************************************************************/
#include <cstdlib>
using namespace std;
void menu();
void read();
void mainMenu();
void optionsMenu();
void options();
int choice1 = 0;
int choice2 = 3;
char put[255] ,*p,*o;
char wty[255];
/*********************************************************************/

int main()
{
    auto clock_1 = std::clock();
    menu();
    //char put[255] ,*p;
    //fgets(put, sizeof(put), stdin);
    //if ( p = strrchr(put, '\n') )
    //*p = '\0';
    //auto count_map = take_map(put);
    auto clock_2 = std::clock();
    std::cout << "Time: " <<1000000 * (clock_2 - clock_1) / CLOCKS_PER_SEC << "us" << std::endl;
    return 0;
}
void menu()
{
    mainMenu();
        do
    {
        choice2 = 0;
        char choice1;
        choice1 = getchar();
        switch(choice1) {
            case '1':
                cout << "Enter put file: ";
                fgets(put, sizeof(put), stdin);
                if ( p == strrchr(put, '\n') )
                *p = '\0';
                //read();
                break;
            case '2':
                cout << "Enter word: ";
                read();
                break;
            case '4':
                choice2 = 3;
                break;
        }
    } while(choice2 != 3);
}

void read()
{
    auto count_map = take_map(put);
}

void mainMenu(void) {
    cout << "Main Menu\n";
    cout << "1 - Put FILE    ";
    cout << "2 - WORD    ";
    cout << "3 - EXIT\n";
    //cout << " ";
    //        cin >> choice1;
}

std::string conv_word (const std::string& word)
{
    std::string new_word;
    for (const char& ch: word)
    {
        if (std::isalpha(ch) || std::isdigit(ch))
            new_word += std::toupper(ch);
    }
    return new_word;
}

std::unordered_map<std::string, int> take_map(const char* file_name)
{
    std::unordered_map<std::string, int> count_map;

    std::ifstream file(file_name);
    std::string word;
    //char wty[255] ,*o;
    fgets(wty, sizeof(wty), stdin);
    if ( o == strrchr(wty, '\n') )
    *o = '\0';
    int kol = 0;
    while(file)
    {
        file >> word;
        std::string new_word = conv_word(word);
        if (!new_word.empty() && (new_word == wty))
        {
            ++count_map[new_word];
            ++kol;
        }
    }

    /*for (const std::pair<std::string,int>& value: count_map)
    {
         std::cout << value.first << ":" <<value.second << std::endl;
    }*/
    std::cout <</* wty <<*/ " : " <<kol << std::endl;
}
