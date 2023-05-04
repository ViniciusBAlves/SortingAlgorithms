#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int hash_code(string s,int M);
void print_table(vector<string> arr[], int M,ofstream& arq_sai, ifstream& arq_ent);
void insert_hash_table(vector<string> arr[],string key,int M);
int search_hash_table(vector<string> arr[],int M,string search);
