#include <iostream>
#include <string>
#include <fstream> 
#include <stdexcept>
using namespace std;

void menu() {
    cout << "Menu: " << "\n" << "1 - Display text on the screen." << "\n" << "2 - Counts the number of characters in the text." << "\n" << "3 - Search for a given word - display statistics (how many times it occurs and in what positions)." << "\n" << "4 - Replace a word with a new word - display statistics on the replacement (how many times it was replaced and at what positions)." << "\n" << "5 - Word deletion - displays statistics on word deletion (how many times it was deleted and on which positions)." << "\n" << "6 - Flip the contents of the file." << "\n" << "7 - Exit" << "\n";
}

string concat_with_space(string str1, string str2) {
    return str1 + " " + str2;
}

class file_utils {
public:
    static string read_file_to_string(const string& file_path) {
        ifstream file_stream(file_path);

        if (!file_stream.is_open()) {
            throw runtime_error("Не вдалося відкрити файл для читання: " + file_path);
        }

        return string((istreambuf_iterator<char>(file_stream)),
            istreambuf_iterator<char>());
    }
    static void write_string_to_file(const string& file_path, const string& content) {
        ofstream file_stream(file_path);

        if (!file_stream.is_open()) {
            throw runtime_error("Не вдалося відкрити файл для запису: " + file_path);
        }

        file_stream << content;
    }
};

int main() {
 
    /*string s1;
    string s2 = "hello";
    string s3(s2);
    string s4(100, '*');

    cout << s4;*/

    //string str1 = "Hello";
    //string str2 = "world!!";

    ///*string str3 = str1 + " " + str2;*/

    //string str3 = concat_with_space(str1, str2);

    //cout << str3;

    /*string str1 = "Hello";
    string str2 = "world!!";

    str1 += str2;

    cout << str1 << "\n";
    cout << str2;*/

    /*string str1 = "Hello";
    string str2;

    str2 = str1;

    cout << str1 << "\n";
    cout << str2 << "\n";*/


    /*string str = "Hello";

    cout << str[4] << "\n";
    str[4] = 'a';

    cout << str;*/


    //string str1 = "hello";
    //string str2 = "hello";

    ///*if (str1 == str2) cout << "Equals";
    //else cout << "Not Equals";*/
    //    
    //if (str1 > str2) cout << "First is bigger";
    //else if (str1 < str2) cout << "Second is bigger";
    //else cout << "Equals";



    // Методи string: 
    // 1) insert - вставляє підстрічку в стрічку 

    /*string str = "Hello world!!";

    str.insert(6, "all ");
    cout << str;*/

    // 2) erase - щоб видалити з потрібної позиції потрібну кількість елементів
    
    /*string str = "Hello world!!";

    str.erase(2, 3);

    cout << str;*/

    // 3) replace - для заміни елементів

    /*string str = "Hello world!!";

    str.replace(6, 5, "all");

    cout << str;*/

    // 4) lenght - довжина стрічки

    /*string str = "Hello world!!";

    cout << str.length();*/

    // 5) find - щоб найти позицію підстрічки в стрічці, якщо її не знайдено повертає значення типу size_t

    /*string str = "Hello all world!!";

    cout << str.find("all") << "\n";
    cout << str.find("str");*/

    /*string str = "hello all world all hello all hi";

    string search = "all";
    int pos = str.find(search);

    if (pos == -1) {
        cout << "not found!!!";
    }
    else {
        while (pos != -1) {
            cout << pos << " ";
            str.erase(pos, search.length() + 1);
            pos = str.find(search, pos + 1);
        }
        cout << "\n";
    }

    cout << str;*/

    // 6) substr - повертає підстрічку починаючи з потрібної позицію, з потрібною кількістю символів 

    /*string str = "Hello all world!!";
    
    string res = str.substr(6, 3);

    cout << res;*/

    // 7) empty - перевіряє пуста стрічка чи ні, повертає True або False
    
    /*string str = "Hello world!!";

    if (str.empty()) cout << "string empty!";
    else cout << str;*/

    // getline - Щоб ввести стрічку з клавіатури

    // Щоб ввести стрічку без пробілів
    /*string str;
    cin >> str;
    cout << str;*/

    // Щоб вести стрічку з пробілами
    /*string str;
    getline(cin, str);
    cout << str;*/


    // Завдання 1: 
    //string str = "Helzlo alzl worlzd!!!";

    //cout << str << "\n";

    //string search = "z";

    //int pos = str.find(search);

    //if (pos == -1)
    //{
    //    cout << "Not found" << "\n";
    //}
    //else {
    //    while (pos != -1) {
    //        str.erase(pos, search.length());
    //        pos = str.find(search, pos);
    //    }
    //}

    //cout << str << "\n";

    //int a = str.length() / 2;
    //str.insert(a, " ABC");

    //cout << str << "\n";

    // Завдання 2: 
    string file_path = "data.txt";
    string text = file_utils::read_file_to_string(file_path);

    string word_to_found;
    char a;
    int num;
    int pos;
    int count{};

    menu();
    cout << "Type your number: ";
    cin >> num;
    if (1 < num > 7)
    {
        cout << "Error!!";
    }
    else {
        do {
            switch (num) {
            case 1:
                cout << text << "\n";
                cout << "Press ane button to continue....";
                cin.ignore();
                a = getchar();
                system("cls");
                break;
            case 2:
                cout << "Number of characters in the text: " << text.length() << "\n";
                cout << "Press ane button to continue....";
                cin.ignore();
                a = getchar();
                system("cls");
                break;
            case 3:
                cin.ignore();
                count;
                cout << "Type word for found: ";
                getline(cin, word_to_found);
                pos = text.find(word_to_found);
                if (pos == 1) {
                    cout << "Word not found!!" << "\n";
                    break;
                }
                else {
                    while (pos != -1) {
                        count++;
                        cout << "Your word found on position: " << pos << "\n";
                        pos = text.find(word_to_found, pos + 1);
                    }
                }
                cout << "I found this word: " << count << " times" << "\n";
                cout << "Press ane button to continue....";
                a = getchar();
                system("cls");
                break;
            case 4:
                cin.ignore();
                cout << "Type word for change: ";
                string word_to_change;
                getline(cin, word_to_change);
                cout << "Type new word: ";
                string new_word;
                getline(cin, new_word);
                pos = text.find(word_to_change);
                if (pos == -1)
                {
                    cout << "Word not found!!" << "\n";
                    break;
                }
                else {
                    text.erase(pos, word_to_change.length());
                    text.insert(pos, new_word);
                }
                cout << "Word: " << word_to_change << " replaced with: " << new_word << "\n";
                cout << "Press ane button to continue....";
                a = getchar();
                system("cls");
                break;
            }
            menu();
            cout << "Type your number: ";
            cin >> num;
        } while (num != 7);
    }


    return 0;
}