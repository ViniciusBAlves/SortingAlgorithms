#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <algorithm>
#include "trab_final.hpp"
#include "parser.hpp"

#define M 15161 //0,76
#define N 138493 //1,00
#define O 11    //0,72
#define P 743   //0,70

using namespace std;

int main(){
    PLAYER_AV s;
    USER u;
    vector<vector<PLAYER_AV>> arr2(M);
    vector<vector<USER>> user(N);
    vector<vector<POSIT>> pos(O);
    vector<vector<CARAC>> c(P);
    vector<vector<PLAYER_NAME>> n(M);
    string delimiter = ", ",player,op,data;
    vector<string> tokens;
    int k = 0;
    float rate;
    struct TrieNode *root = getNode();
    auto start = std::chrono::high_resolution_clock::now();
    //-----------------------------------Fase de Construcao-----------------------------------------------//
    ifstream file_2("players.csv");
    aria::csv::CsvParser reader(file_2);
    for(auto& row: reader){
        if(reader.position() != 32){
            insert_name_hash_sfid(n,row[1],stoi(row[0]),M,row[2]); //hashing using sofifa_id as key, stores sofifa_id, name & positions
            insert(root,row[1],stoi(row[0])); //inserts information in the trie using the player's name as key
        }
    }
    ifstream file("rating.csv");
    aria::csv::CsvParser parser(file);
    for(auto& row: parser){
        if(parser.position() != 25){
            insert_rate_user(stoi(row[0]),user,stoi(row[1]),N,stof(row[2])); //hashing using user_id as key, stores user_id and rating 
            insert_rating(stoi(row[1]),arr2,stof(row[2]),M); //hashing using sofifa_id as key, stores total rate, rating and count
        }
    }
    ifstream file_3("tags.csv");
    aria::csv::CsvParser read(file_3);
    for(auto& row: read){
        if(read.position() != 22){
            insert_carac(stoi(row[1]),c,row[2],P,M,n); //hashing using tags as keys, stores sofifa_id
        }
    }
    put_rate(arr2,pos,M,O,n); //calculates average rating and stores it
    order_rate(user,N); //orders using quicksort
    order_pos(pos,O);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " seconds" << endl;
//-----------------------------------Modo Console-----------------------------------------------//
    while (op != "exit"){
        print_hashtag();
        cout << "|\t\t\t\t\t\tBEM VINDO A APLICACAO: "<<right<<setw(59) << "|" << endl;
        print_hashtag();
        cout << "| Para buscar players, digite \"player (nome do jogador) \""<<right<<setw(73) << "|" << endl;
        cout << "| Para buscar avaliacoes de um usuario, digite \"user (id do usuario) \""<<right<<setw(60) << "|" << endl;
        cout << "| Para buscar os n melhores jogadores de uma posicao, digite \"top<n> 'posicao desejada' \""<<right<<setw(41) << "|" << endl;
        cout << "| Para buscar os jogadores com uma determinada caracteristica, digite \"tags \'caracteristica1\' \'caracteristica2\' \'...\' \""<<right<<setw(11) << "|" << endl;
        cout << "| Para sair, digite \"exit\""<<right<<setw(104) << "|" << endl;
        print_hashtag();
        getline(cin,op);
        tokens = tokenize(op," ");
        if(tokens[0] == "player"){
            op.erase(0,op.find(" ")+1);
            printAutoSuggestions(root,op,M,n,arr2);
        }
        else if(tokens[0] == "user"){
            op.erase(0,op.find(" ")+1);
            print_user(user,N,stoi(op),arr2,M,n);
        }
        else if(op.find("top") == 0 &&  tokens[0][3] > 47 && tokens[0][3]<58){ 
            data = op.substr(3,op.find(" ")-3);
            op.erase(0,op.find(" ")+2);
            op.erase(op.end()-1, op.end());

            print_pos(pos,O,op,stoi(data));
        }
        else if(tokens[0] == "tags"){
            op.erase(0,op.find(" ")+1);
            print_carac(c,P,n,arr2,op,M);
        }
        else if(tokens[0] == "exit")
            cout << "Programa encerrado" << endl;
        else
            cout << "Comando invalido" << endl;
        if(tokens[0] != "exit"){
            do{
                cout << "Aperte enter para continuar" << endl;
            }while(cin.get() != '\n');
            system("cls");
        }
    }
    return 0;
}
