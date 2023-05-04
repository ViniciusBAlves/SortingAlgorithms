#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "header.hpp"

using namespace std;

int R = 256;

int charAT(string a,int d){
    if(d < a.size())
        return a.at(d);
    else
        return -1;
}

void MSD_sort(vector<string> &a, vector<string> &aux, int lo, int hi, int d){
    if(hi<=lo)
        return;
    int count[R+2] = {0};
    for(int i = lo;i <= hi; i++)
        count[charAT(a[i],d) + 2]++;
    for(int r = 0; r < R+1;r++)
        count[r+1] += count[r];
    for(int i = lo;i <= hi; i++){
        aux[count[charAT(a[i],d) + 1]++] = a[i];
    }
    for(int i = lo;i <= hi; i++){
        a[i] = aux[i-lo];
    }
    for(int r = 0; r < R;r++)
        MSD_sort(a,aux,lo+count[r],lo+count[r+1] - 1,d+1);
}

vector<string> MSD_start(vector<string> &a){
    int n = a.size();
    vector<string> aux(n);
    MSD_sort(a,aux,0,n-1,0);
    return a;
}

void operation(string ent, string out){
	vector<string> words;
	string str;
	int tam = 0,count = 1;
	ifstream arq_ent;
	ofstream arq_sai;

	arq_ent.open(ent);
	if(arq_ent.is_open()){
		while(arq_ent >> str){
			if(str.length()>=4){
				words.push_back(str);
				tam++;
			}
		}
	}
	else{
		cout << "Nao foi possivel abrir o arquivo" << endl;
	}
	arq_ent.close();
	words = MSD_start(words);
	arq_sai.open(out);
	for(int i = 0; i < tam-1;i++){
		if(words[i] == words[i+1])
			count++;
		else{
			arq_sai << words[i] << "\t" << count << endl;
			count = 1;
		}
	}
	arq_sai.close();
}