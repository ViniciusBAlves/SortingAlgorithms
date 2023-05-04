#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include "trab_final.hpp"


using namespace std;


int hash_code_string(string s, int M){
    int h = 0, index = 0;
    for (int i = 0; i < s.length(); i++){
        h += s.at(i);
    }
    index = h % M;
    return index;
}

vector<string> tokenize(string s, string sep){
    int start, end = -1*sep.size();
    vector<string> p;
    do{
        start = end + sep.size();
        end = s.find(sep, start);
        p.push_back(s.substr(start, end - start));
    }while (end != -1);
    return p;
}

int hash_code(int p, int M){
    int index = p % M;
    return index;
}

void insert_name_hash_sfid(vector<vector<PLAYER_NAME>> &n, string nam,int sofifa_id,int M,string pos){
    PLAYER_NAME jog;
    jog.name = nam;
    jog.sofifa_id = sofifa_id;
    jog.position = pos;
    int index = hash_code(sofifa_id,M);
    n[index].push_back(jog);
}

void insert_rating(int sofifa_id,vector<vector<PLAYER_AV>> &arr,float rating,int M){
    PLAYER_AV p;
    p.sofifa_id = sofifa_id;
    int index = hash_code(p.sofifa_id,M),x=0;
    if(arr[index].empty()){
        arr[index].push_back(p);
        arr[index][0].rating.push_back(rating);
        arr[index][0].count = arr[index][0].count + 1;
        arr[index][0].rate = arr[index][0].rate + rating;
    }
    else{
        while(x < arr[index].size() && p.sofifa_id != arr[index][x].sofifa_id)
            x++;
        if(p.sofifa_id != arr[index][x].sofifa_id)
            arr[index].push_back(p);
        arr[index][x].rating.push_back(rating);
        arr[index][x].count = arr[index][x].count + 1;
        arr[index][x].rate = arr[index][x].rate + rating;
    }
}

void insert_rate_user(int user_id, vector<vector<USER>> &u, int sofifa_id, int N,float rates){
    USER us;
    us.user = user_id;
    int index = hash_code(us.user,N),x=0;
    AV rating;
    rating.rate = rates;
    rating.sofifa_id = sofifa_id;
    if(u[index].empty()){
        u[index].push_back(us);
        u[index][0].rate_user.push_back(rating);
    }
    else{
        while(x < u[index].size() && us.user != u[index][x].user)
            x++;
        if(x == u[index].size())
            u[index].push_back(us);
        u[index][x].rate_user.push_back(rating);
    }
    
}

void insert_carac(int sofifa_id, vector<vector<CARAC>> &c,string caracter, int M,int N,vector<vector<PLAYER_NAME>> &arr){
    int index = hash_code_string(caracter,M),x = 0,y=0,found = 0;
    int index2 = hash_code(sofifa_id,N);
    CARAC r;
    r.caract = caracter;
    
    if(c[index].empty()){
        c[index].push_back(r);
        c[index][0].sofifa_id.push_back(sofifa_id);
    }
    else{
        while(x < c[index].size() && caracter != c[index][x].caract)
                x++;    
        if(caracter != (c[index][x].caract))
            c[index].push_back(r);
        if(c[index][x].sofifa_id.empty())
            c[index][x].sofifa_id.push_back(sofifa_id);
        else{
            for(auto& k: c[index][x].sofifa_id){
                if(sofifa_id == k)
                    found = 1;
            }
            if(found != 1)
                c[index][x].sofifa_id.push_back(sofifa_id);
        }
    }
    while(sofifa_id != arr[index2][y].sofifa_id)
        y++;
    arr[index2][y].carac.push_back(caracter);
}

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = -1;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
void insert(struct TrieNode *root, string key, int sofifa_id)
{
    struct TrieNode *pCrawl = root;
    int index;
    int n = key.length();
    for (int i = 0; i < n; i++)
    {   
        if(key[i] <= 90 && key[i] >= 65)
            index = key[i] - 38;
        else if(key[i]==32)
            index = 26;
        else if(key[i] == 46)
            index = 53;
        else if(key[i] == 39)
            index = 54;
        else if(key[i] == '-')
            index = 55;
        else
            index = key[i] - 'a';
        if(index >= 0 && index < 56){
            if (!pCrawl->children[index]){
                pCrawl->children[index] = getNode();
            }
            pCrawl = pCrawl->children[index];
        }
    }
    pCrawl->isEndOfWord = sofifa_id;
}

bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

void search_name(string n, int M,vector<vector<PLAYER_NAME>> &arr,vector<vector<PLAYER_AV>> &arr2, int lastword){
    int index = hash_code(lastword,M);
    int x=0,y=0;
    while(arr[index][y].name != n){
        y++;
    }
    cout <<left<< setw(15)<<  arr[index][y].sofifa_id <<left<< setw(60) << arr[index][y].name <<left<< setw(20)<< arr[index][y].position;
    x = 0;
    if(!arr2[index].empty()){
        while(arr2[index][x].sofifa_id != lastword && x < arr2[index].size()){
            x++;
        }
        if(x == arr2[index].size())
            cout <<left<< setw(10)<< 0 << left<< setw(10) << 0 << endl;
        else{
            cout <<left<< setw(10)<< arr2[index][x].rate <<left<< setw(10) << arr2[index][x].count << "\n";
        }
    }
    else
        cout <<left<< setw(10) << 0 <<left<< setw(10) << 0 << endl;
}
void suggestionsRec(struct TrieNode* root, string currPrefix, int M,vector<vector<PLAYER_NAME>> &arr,vector<vector<PLAYER_AV>> &arr2)
{
    char child;
    if (root->isEndOfWord != -1)
        search_name(currPrefix,M,arr,arr2,root->isEndOfWord);
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            if(i == 26)
                child = 32;
            else if(i == 53)
                child = 46;
            else if(i == 54)
                child = 39;
            else if (i==55)
                child = 45;
            else if(i>26 && i < 53)
                child = 38+i;
            else
                child = 'a'+i;
            suggestionsRec(root->children[i],currPrefix + child,M,arr,arr2);
        }
}

int printAutoSuggestions(TrieNode* root, const string query, int M,vector<vector<PLAYER_NAME>> &arr,vector<vector<PLAYER_AV>> &arr2)
{
    int index;
    struct TrieNode* pCrawl = root;
    for (int i = 0; i < query.length(); i++) {
        if(query[i] <= 90 && query[i] >= 65)
            index = query[i] - 38;
        else if(query[i]==32)
            index = 26;
        else if(query[i] == 46)
            index = 53;
        else if (query[i] == 39)
            index = 54;
        else if(query[i] == 45)
            index = 55;
        else
            index = query[i] - 'a';
        if(index >= 0 && index < 56){
            if (!pCrawl->children[index]){
                return 0;
            }
            pCrawl = pCrawl->children[index];
        }
    }
    if (isLastNode(pCrawl)) {
        cout << query << endl;
        return -1;
    }
    cout <<left<< setw(15)<<  "sofifa_id" <<left<< setw(60) << "name" <<left<< setw(20)<< "player_positions"<<left<< setw(10)<<"rating"<<left<< setw(10)<<"count"<<endl;
    suggestionsRec(pCrawl, query,M,arr,arr2);
    return 1;
}

int partition_hoare(vector<AV> &av, int left, int right){
    AV chave = av.at(left);
    int i, j;
    i = left;
    j = right;
    while (i<j) {
        while(av.at(j).rate <= chave.rate && i < j) j--;
        av.at(i) = av.at(j);
        while(av.at(i).rate > chave.rate && i < j) i++ ;
        av.at(j) = av.at(i);
    }
    av.at(j) = chave;
    return i;
}

void quicksort(vector<AV> &av, int i, int f){
    int k;
    if(f>i){
        k = partition_hoare(av,i,f);
        quicksort(av, i, k-1);
        quicksort(av, k+1, f);
    }
}

void order_rate(vector<vector<USER>> &u,int N){
    for(int k = 0; k < N;k++){
        for(auto& n: u[k]){
            quicksort(n.rate_user,0,n.rate_user.size()-1);
        }
    }
}

int partition_hoare_pos(vector<POSIT_INFO> &av, int left, int right){
    POSIT_INFO chave = av.at(left);
    int i, j;
    i = left;
    j = right;
    while (i<j) {
        while(av.at(j).rate <= chave.rate && i < j) j--;
        av.at(i) = av.at(j);
        while(av.at(i).rate > chave.rate && i < j) i++ ;
        av.at(j) = av.at(i);
    }
    av.at(j) = chave;
    return i;
}

void quicksort_pos(vector<POSIT_INFO> &av, int i, int f){
    int k;
    if(f>i){
        k = partition_hoare_pos(av,i,f);
        quicksort_pos(av, i, k-1);
        quicksort_pos(av, k+1, f);
    }
}

void put_rate(vector<vector<PLAYER_AV>> &arr2, vector<vector<POSIT>> &pos, int M, int O, vector<vector<PLAYER_NAME>> &n){
    for(int i=0;i<M;i++){
        for(auto& p: arr2[i]){
            p.rate = p.rate/p.rating.size();
            put_rate_in_pos(pos,p,M,O,n);
        }
    }
}

void order_pos(vector<vector<POSIT>> &pos, int M){
    for(int k = 0; k < M; k++){
        for(auto& n: pos[k]){
            quicksort_pos(n.info,0,n.info.size()-1);
        }
    }
}
void put_rate_in_pos(vector<vector<POSIT>> &pos,PLAYER_AV &a,int M, int O, vector<vector<PLAYER_NAME>> &arr){
    if(a.count < 1000){
        return;
    }
    else{
        int index = hash_code(a.sofifa_id,M),x=0,y;
        vector<string> tokens;
        while(arr[index][x].sofifa_id != a.sofifa_id && x < arr[index].size())
            x++;
        POSIT p;
        POSIT_INFO i;
        i.count = a.count;
        i.name = arr[index][x].name;
        i.rate = a.rate;
        i.sofifa_id = a.sofifa_id;
        i.pos = arr[index][x].position;
        tokens = tokenize(arr[index][x].position,", ");
        for(auto& s: tokens){
            p.position = s;
            int index2 = hash_code_string(p.position,O);
            if(pos[index2].empty()){
                pos[index2].push_back(p);
                pos[index2][0].info.push_back(i);
            }
            else{
                y=0;
                while(y < pos[index2].size() && pos[index2][y].position != s)
                    y++;
                if(pos[index2].size() == y)
                    pos[index2].push_back(p);
                pos[index2][y].info.push_back(i);
            }
        }
    }
}


void print_user(vector<vector<USER>> &u, int N, int us, vector<vector<PLAYER_AV>> &arr, int M,vector<vector<PLAYER_NAME>> &n){
    int x = 0, index = hash_code(us,N),y,t,p=0;
    while(!u[index].empty() && us != u[index][x].user && x < u[index].size())
            x++;
    if(x == u[index].size())
        cout << "USUARIO NAO ENCONTRADO" << endl;
    else{
        cout <<left<< setw(15)<<"sofifa_id"<<left<< setw(60)<< "name" <<left<< setw(20)<< "global_rating" <<left<< setw(10)<<"count"<<left<< setw(10)<<"rating"<<endl;
        for(auto& k: u[index][x].rate_user){
            if(p<20){
                int index2 = hash_code(k.sofifa_id,M);
                y = 0;
                while(y < arr[index2].size() && k.sofifa_id != arr[index2][y].sofifa_id)
                    y++;
                t = 0;
                while(t < n[index2].size() && k.sofifa_id != n[index2][t].sofifa_id )
                    t++;
                cout << setprecision(3);
                cout <<left<< setw(15)<< k.sofifa_id <<left<< setw(60)<< n[index2][t].name <<left<< setw(20)<< arr[index2][y].rate  <<left<< setw(10)<< arr[index2][y].count <<left<< setw(10)<< k.rate << endl;
                p++;
            }
            else{
                return;
            }
        }
    }
}

void print_pos(vector<vector<POSIT>> &pos,int O,string posi,int num){
    int index = hash_code_string(posi,O),x=0,cnt=0;
    while(!pos[index].empty() && pos[index][x].position != posi && x < pos[index].size())
        x++;
    if(x == pos[index].size()){
        cout << "POSICAO INVALIDA" << endl;
        return;
    }
    else{
    cout <<left<< setw(15)<<"sofifa_id"<<left<< setw(60)<< "name" <<left<< setw(20)<< "player_positions" <<left<< setw(10)<<"rating"<<left<< setw(10)<<"count"<<endl;
        for(auto& s: pos[index][x].info){
            if(cnt < num){
                cout <<left<< setw(15)<< s.sofifa_id <<left<< setw(60) << s.name <<left<< setw(20)<< s.pos <<left<< setw(10) << s.rate <<left<< setw(10) << s.count << endl;
                cnt++;
            }
            else
                return;
        }
    }
}

void print_carac(vector<vector<CARAC>> &arr, int N,vector<vector<PLAYER_NAME>> &arr2, vector<vector<PLAYER_AV>> &arr3,string tags, int M){
    vector<string> tokens;
    tokens = tokenize(tags,"' '");
    for(auto& f: tokens)
        f.erase(remove(f.begin(),f.end(),'\''),f.end());
    int found=0;
    int index = hash_code_string(tokens[0],N),x=0,y=0,z=0;
    while(!arr[index].empty() && arr[index][x].caract != tokens[0] && x < arr[index].size()){
        x++;
    }
    if(x == arr[index].size()){
        cout << "UMA OU MAIS DAS CARACTERISTICAS DIGITADAS SAO INVALIDAS" << endl;
        return;
    }
    else{
        cout <<left<< setw(15)<<"sofifa_id"<<left<< setw(60)<< "name" <<left<< setw(20)<< "player_positions" <<left<< setw(10)<<"rating"<<left<< setw(10)<<"count"<<endl;
        for(auto& k: arr[index][x].sofifa_id){
            int index2 = hash_code(k,M);
            y=0;
            while(arr2[index2][y].sofifa_id != k)
                y++;
            z = 0;
            while(z < arr3[index2].size() && arr3[index2][z].sofifa_id != k && !arr3[index2].empty())
                z++;
            if(tokens.size() == 1){
                cout <<left<< setw(15)<<k<<left<< setw(60)<< arr2[index2][y].name <<left<< setw(20)<< arr2[index2][y].position;
                if(z == arr3[index2].size())
                    cout<<left<< setw(10)<<0<<left<< setw(10)<<0<<endl;
                else
                    cout<<left<< setw(10)<<arr3[index2][z].rate<<left<< setw(10)<<arr3[index2][z].count<<endl;
            }
            else{
                for(int i = 1; i < tokens.size();i++){
                    int j = 0;
                    while(j <arr2[index2][y].carac.size() && arr2[index2][y].carac[j] != tokens[i])
                        j++;
                    if(j == arr2[index2][y].carac.size()){
                        found = 2;
                        break;
                    }
                    else if(arr2[index2][y].carac[j] == tokens[i])
                        found = 1;
                }
                if(found == 1){
                    cout <<left<< setw(15)<<k<<left<< setw(60)<< arr2[index2][y].name <<left<< setw(20)<< arr2[index2][y].position;
                    if(z != arr3[index2].size())
                        cout<<left<< setw(10)<<arr3[index2][z].rate<<left<< setw(10)<<arr3[index2][z].count<<endl;
                    else
                        cout<<left<< setw(10)<<0<<left<< setw(10)<<0<<endl;
                }
            }   
        }
    } 
}
void print_hashtag(){
    for(int i = 0; i < 130; i++)
        cout<< "_";
    cout << endl;
}