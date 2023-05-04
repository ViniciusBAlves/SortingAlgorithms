#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "header.hpp"

using namespace std;

int main(){
    int sizes[4] = {503,2503,5003,7507};
        ifstream arq_ent;
        ofstream arq_sai;
    for(int i = 0; i < 4; i++){
        vector<string> arr[sizes[i]];
        string line, sai = "experimento";
        arq_ent.open("nomes_10000.txt");
        if(arq_ent.is_open()){
            while(getline(arq_ent,line)){
                insert_hash_table(arr,line,sizes[i]);
            }
        }
        arq_ent.close();
        arq_ent.open("consultas.txt");
        arq_sai.open(sai.append(to_string(sizes[i])+".txt"));
        print_table(arr,sizes[i], arq_sai, arq_ent);
        arq_ent.close();
        arq_sai.close();
    }
    return 0;
}