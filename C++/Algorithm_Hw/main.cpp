#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <chrono>

using namespace std;

struct LinkedList {                                         //Linked list bu
   string data;                                             //Linked listin i�eri�i
   struct LinkedList *next;
};

struct LinkedList* head = NULL;                             //Linkedlistin en �stteki node'u

void save(string new_data) {                                //Linkedlist e yeni veri girilmesini sa�lar
   struct LinkedList* new_node = new LinkedList;            //Olu�turulacak yeni veri i�in haf�zada yer a��l�r
   new_node->data = new_data;                               //Haf�zada a��lan yeni yerin i�eri�i doldurulur
   new_node->next = head;                                   //yeni en �st art�k bu node oldu
   head = new_node;
}

bool compare(string name) {                                 // g�nderilen name parametresinin linked listde olup olmad���na bakar varsa true g�nderir yoksa false
   struct LinkedList* ptr;
   ptr = head;
   while (ptr != NULL) {
      if(name == ptr->data){
        return true;
      };
      ptr = ptr->next;
   }
   return false;
}

int main()
{
    auto start = chrono::steady_clock::now( );                          // Kodun ba�lang�� zaman�
    ifstream inp1;                                                      // Input file stream bir dosyadan veri bu parametreyle al�n�r
    map<string, int> list1;                                             // Hash map 1. input dosyas� buna kaydeddiliyor
    string line;


    inp1.open("Input1.txt");
    for(int i = 1; getline(inp1, line); i++){                           // A��lan dosyadaki sat�rlar� s�ra s�ra line parametresiyle e�ler
        list1[line] = i;                                                // Line parametresini hashmap map "i" de�erli key olarak ekler
    }
    inp1.close();

    inp1.open("Input2.txt");
    while(getline(inp1, line)){
        save(line);                                                     //Linkedlist olu�turup line parametresini save fonksiyonuna g�nderir "yukar�daki save fonksiyonuna bak"
    }
    inp1.close();

    for(map<string, int>::iterator it = list1.begin(); it != list1.end(); ++it){            //Hashmaple linked list kar��la�t�r�l�r bu d�ng�de
        string key = it->first;
        int value  = it->second ;
        if(!(compare(key))){                                            // yukar�daki compare fonksiyonuna bak
            cout << key << " in first file at line " << value << " is missing in second file!" << endl;
        }
    }
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now( ) - start );
    cout << elapsed.count() << " ms" << endl;

    system("Pause");
    return 0;
}
