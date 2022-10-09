///Act 2.3 - Integral activity linear data structure (Proficiency Evidence)
/// Author: Juan Jose Salazar Cortes
/// Author: Mariana Esquivel Hernandez
/// date: 10/11/2022

/*#include <bits/stdc++.h>*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

string getIP(string record){
    int contEsp = 0;
    int indexBeg;
    int indexEnd;
    for(int i = 0; i < record.length(); i++){
        if(record[i] == ' ') contEsp ++;
        if(contEsp == 3) indexBeg = i + 1;
        if(contEsp == 4) indexEnd = i - 1;
    }
    return record.substr(indexBeg, indexEnd); // "112.12.122.12.1111"
} // Time Complexity O(n)

string configStr(string IP){ // 14
    int first3 = 3;
    int first2 = 2;
    int second3 = 3;
    int second2 = 2;

    int cont = 0;

    if(IP.length() < 14){
        for(int i = 0; i < IP.length(); i++){
        
        }
    }
}

int getNumberIP(string IP){
    string IP = getIP(IP);
    for(int i = 0; i < IP.length(); i++){
        if(IP[i] == '.')
    }
}

int getDate(string record){
    return stoi(record.substr(4, 6));
} // Time Complexity O(1)

string getDayAndMonth(string record){
    if(record[5] == ' ') return record.substr(0, 5);
    else return record.substr(0, 6);
} // Time Complexity O(1)

// -------------- Sequential Search -----------------

int sequentialSearch(vector<string> &info, string date){
    for(int i = 0; i < info.size(); i++){
        if(getDayAndMonth(info[i]) == date){
            return i;
        }
    }
    return -1;
} // Time Complexity O(n)

int inverseSequentialSearch(vector<string> &info, string date){
    for(int i = info.size(); i > 0; i--){
        if(getDayAndMonth(info[i]) == date){
            return i;
        }
    }
    return -1;
} // Time Complexity O(n)

// -------------- Store the sorting result -----------------
void showSelectedRange(vector<string> info, int start, int end){
    // newBitacora.txt
    ofstream myfile;
    myfile.open ("newBitacora.txt"); 
    for(int i = start; i < end; i++){
        myfile << info[i] << endl; 
    }
    myfile.close();
} // Time Complexity O(1)

int main(){
    fflush(stdin);
    vector<string> info;
    string record;
    string startIP, endIP;
    ifstream MyReadFile("bitacora.txt");
    while(getline(MyReadFile, record)){
        info.push_back(record);
    }
    MyReadFile.close();
    sort(info.begin() + 6, info.end());
    cout << "\nIngresa la IP de Inicio de Búsqueda en el Siguiente Formato: " << endl;
    cout << "Example: 450.25.888.72:5978: ";
    getline(cin, startIP);
    cout << "Ingresa la IP de Final de Búsqueda en el Siguiente Formato: " << endl;
    cout << "Example: 110.17.289.74:5362: ";
    getline(cin, endIP);
    
    showSelectedRange(info, sequentialSearch(info, startIP), inverseSequentialSearch(info, endIP));
    cout << "\nRango Seleccionado Enviado a La Base de Datos" << endl;
    return 0;
}