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

//Modify the IP to have the same length
string configStr(string IP){ // 14
    int second3 = 3;
    int first2, second2 = 2;
    int dot = 0;

    if(IP.length() < 18){
        for(int i = IP.length()-5; i >= 0; i--){
            if (IP[i] == '.') dot++;
            else if (dot == 0) second2--;
            else if (dot == 1) second3--;
            else if (dot == 2) first2--;
            if (second2 != 0 && dot == 1) IP.insert(i,"0");
            else if (second3 != 0 && dot == 2) IP.insert(i,"0");
            else if (first2 != 0 && dot == 3) IP.insert(i,"0");
        }
    }
    return IP;
}

//Delete "." and ":" from the IP to sort it as an integer
int getNumberIP(string IP){
    for(int i = 0; i < IP.length(); i++){
        if(IP[i] == '.' || IP[i] == ':') IP.erase(i);
    }
    return stoi(IP);
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
    string IP;
    string number;
    string startIP, endIP;
    ifstream MyReadFile("test.txt");
    while(getline(MyReadFile, record)){
        info.push_back(record);
    }
    MyReadFile.close();
    configStr(getIP(record));
    number = getNumberIP(IP);
    cout << number << endl;
    
    //sort(info.begin() + 6, info.end());
    
    return 0;
}