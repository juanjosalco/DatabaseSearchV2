#include <bits/stdc++.h>

using namespace std;

int monthToInt(string month){
    vector<string> months = {"Jun", "Jul", "Aug", "Sep", "Oct"};
    for(int i = 0; i < months.size(); i++){
        if(months[i] == month){
            return i;
        }
    }
    return 0;
}

string getMonth(string record){
    return record.substr(0,3);
}

int getDate(string record){
    return stoi(record.substr(4, 6));
}

string getDayAndMonth(string record){
    if(record[5] == ' ') return record.substr(0, 5);
    else return record.substr(0, 6);
}

// ----- Part of mergeSort Function --------
void merge(vector<string> &data, int inicio, int mid, int final){
    int numIzq = mid - inicio + 1;
    int numDer = final - mid;

    vector<string> vecIzq;
    vector<string> vecDer;

    for(int i = 0; i < numIzq; i++){
        vecIzq.push_back(data[inicio + i]);
    }
    for(int i = 0; i < numDer; i++){
        vecDer.push_back(data[mid + 1 + i]);
    }

    int i = 0;
    int j = 0; 
    int k = inicio;


    while(i < numIzq && j < numDer){
        if(monthToInt(getMonth(vecIzq[i])) < monthToInt(getMonth(vecDer[j]))){
            data[k] = vecIzq[i];
            i++;
        } 
        else if(monthToInt(getMonth(vecIzq[i])) == monthToInt(getMonth(vecDer[j]))){
            if (getDate(vecIzq[i]) <= getDate(vecDer[j])){
                data[k] = vecIzq[i];
                i++;
            }
            else{
                data[k] = vecDer[j];
                j++;
            } 
        }
        else{
            data[k] = vecDer[j];
            j++;
        }
        k++;
    }

    while(j < numDer){
        data[k] = vecDer[j];
        j++;
        k++;
    }
    while(i < numIzq){
        data[k] = vecIzq[i];
        i++;
        k++;
    }
} // Time Complexity O(n)

void mergeSort(vector<string> &data, int inicio, int final){
    if(inicio < final){
        int mid = inicio + (final - inicio) / 2;
        mergeSort(data, inicio, mid);
        mergeSort(data, mid + 1, final);
        merge(data, inicio, mid, final);

    } // Final Time Complexity O(n log n)
}

// -------------- Binary Search -----------------

int sequentialSearch(vector<string> &info, string date){
    for(int i = 0; i < info.size(); i++){
        if(getDayAndMonth(info[i]) == date){
            return i;
        }
    }
    return -1;
}
int inverseSequentialSearch(vector<string> &info, string date){
    for(int i = info.size(); i > 0; i--){
        if(getDayAndMonth(info[i]) == date){
            return i;
        }
    }
    return -1;
}

void showSelectedRange(vector<string> info, int start, int end){
    for(int i = start; i < end; i++){
        cout << info[i] << endl;
    }
}

void showVector(vector<string> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    cout << endl;
}

int main(){
    vector<string> info;
    string record;
    string startDate, endDate;
    ifstream MyReadFile("bitacora.txt");
    while(getline(MyReadFile, record)){
        info.push_back(record);
    }
    MyReadFile.close();
    sort(info.begin() + 6, info.end());
    mergeSort(info, 0, info.size()-1);
    cout << "Ingresa la Fecha de Inicio de Búsqueda en el Siguiente Formato: " << endl;
    cout << "Example: Jun 1: ";
    getline(cin, startDate);
    cout << "Ingresa la Fecha de Final de Búsqueda en el Siguiente Formato: " << endl;
    cout << "Example: Jun 1: ";
    getline(cin, endDate);
    
    showSelectedRange(info, sequentialSearch(info, startDate), inverseSequentialSearch(info, endDate));
    
    return 0;
}