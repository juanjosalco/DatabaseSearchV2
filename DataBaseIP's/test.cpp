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

struct Node{
    int val;
    Node *prev, *next;
};

Node* insertNodeEnd(Node *head, int val){
    Node *newNode = new Node();
    newNode->val = val;
    newNode->prev = newNode->next = NULL;
    Node *curr = head;
    if(!head){
        return newNode;
    }

    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    return head;
} // Time Complexity O(n)



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
    int first2 = 2,  second2 = 2, first3 = 3;
    int cont = 0;

    for(int i = IP.length()-6; i >= 0; i--){ // 14 - 6 = 8
        if(IP[i] != '.'){
            cont++;
        } else{
            if(cont == first2){
                continue;
            } else{
                IP[i] = '0';
                cont = 0;
            }
            if(cont <= first3){
                continue;
            } else{
                IP[i] = '0';
                cont = 0;
            }
        }
        cout << IP << endl;
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





createLinkedList







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
    struct Node *head = NULL;
    vector<string> info;
    string record;
    ifstream MyReadFile("test.txt");
    while(getline(MyReadFile, record)){
        info.push_back(record);
    }
    MyReadFile.close();
    
    cout << info[1] << endl;
    cout << getNumberIP(configStr(getIP(info[1]))) << endl;
    return 0;
}