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
    bool aux = true;
    bool aux2 = true;
    for(int i = 0; i < record.length(); i++){
        if(record[i] == ' ') contEsp ++;
        if(contEsp == 3 && aux) indexBeg = i + 1 , aux = false;
        if(contEsp == 4 && aux2) indexEnd = i - indexBeg , aux2 = false;
    }
    return record.substr(indexBeg, indexEnd); // "112.12.122.12.1111"
} // Time Complexity O(n)

//Modify the IP to have the same length
string configStr(string IP){ // 14
    int consts = 0;
    int constt = 0;
    int constf = 0;
    int dot = 0;

    
    for(int i = IP.length()-6; i >= 0; i--){ // 14 - 5 = 9, 8
        //cout << IP[i] << endl;
        if (IP[i] == '.') dot++; // dot = 1
        else if (dot == 0) consts++; // second2 = 1
        else if (dot == 1) constt++; // second3 = 2
        else if (dot == 2) constf++;
        if (consts < 2 && dot == 1){
            IP[i] = '0';
            consts++;
        }
        else if (constt < 3 && dot == 2){
            IP[i] = '0';
            constt++;
            if(constt < 3) IP.insert(i,"0");
        }
        else if (constf < 2 && dot == 3){
            IP[i] = '0';
            constf++;
        }
    }
    
    return IP;
}

//Delete "." and ":" from the IP to sort it as an integer
long int getNumberIP(string IP){
    string newStr;
    for(int i = 0; i < IP.length(); i++){
        if(IP[i] != ':' && IP[i] != '.'){
            newStr += IP[i];
        } else{
            continue;
        }
    }
    return stol(newStr);
}

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
    ifstream MyReadFile("test.txt");
    while(getline(MyReadFile, record)){
        info.push_back(record);
    }
    MyReadFile.close();
    
    cout << info[0] << endl;
    cout << getNumberIP(configStr(getIP(info[0]))) << endl;
    return 0;
}