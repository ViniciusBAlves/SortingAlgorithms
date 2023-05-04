#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "header.hpp"

using namespace std;

int hash_code(string s, int M){
    int h = 0, index = 0;
    for (int i = 0; i < s.length(); i++){
        h += s.at(i);
    }
    index = h % M;
    return index;
}

void print_table(vector<string> arr[], int M, ofstream& arq_sai, ifstream& arq_ent){
    arq_sai << "PARTE1: ESTATISTICAS DA TABELA HASH" << endl;
    int non_used = 0, maior = 0, menor = arr[0].max_size(), somalista = 0, l = 0, media_list, k, j = 0, count = 0, max = 0, media, a = 0, b = 0,y;
    float used = 0,taxa;
    string line;
    for(int i = 0; i < M; i++){
        if(arr[i].empty())
            non_used++;
        else{
            used++;
            somalista += arr[i].size();
            l++;
            if(arr[i].size() > maior)
               maior = arr[i].size();
            if(arr[i].size() < menor)
                menor = arr[i].size();
        }
    }
    media_list = somalista/l;
    taxa = (used/M) * 100;
    y = maior;
    arq_sai << "NUMERO DE ENTRADAS DA TABELA USADAS #" << used << endl;
    arq_sai << "NUMERO DE ENTRADAS DA TABELA VAZIAS #" << non_used << endl;
    arq_sai << "TAXA DE OCUPACAO #"<< fixed << setprecision(2) << taxa << endl;
    arq_sai << "MINIMO TAMANHO DE LISTA #" << menor << endl;
    arq_sai << "MAXIMO TAMANHO DE LISTA #" << maior << endl;
    arq_sai << "MEDIO TAMANHO DE LISTA #" << media_list << endl;
    arq_sai << endl;
    arq_sai << "PARTE 2: ESTATISTICAS DAS CONSULTAS" << endl;
    if(arq_ent.is_open()){
        while(getline(arq_ent,line)){
            k = search_hash_table(arr,M,line);
            j++;
            count += k;
            if (k != -1){
                arq_sai << line << " HIT #" << k << endl;
                a++;
                b += k;
                if (k > max)
                    max = k;
                if(k < y)
                 y = k;
            }
            else
                arq_sai << line << " MISS" << endl;
        }
        media = count/j;
        arq_sai << "MINIMO NUMERO DE TESTES POR NOME ENCONTRADO #" << y << endl;
        arq_sai << "MAXIMO NUMERO DE TESTES POR NOME ENCONTRADO #" << max << endl;
        arq_sai << "MEDIA NUMERO DE TESTES NOME ENCONTRADO #" << (b/a) << endl;
        arq_sai << "MEDIA #" << media << endl;
    }
}

void insert_hash_table(vector<string> arr[],string key,int M){
    int index = hash_code(key,M);
    arr[index].push_back(key);
}

int search_hash_table(vector<string> arr[],int M,string search){
    int count = 0;
    int index = hash_code(search,M);
    for(int i = 0;i < arr[index].size();i++){
        count++;
        if(arr[index][i] == search){
            return count;
        }
    }
    return -1;
}