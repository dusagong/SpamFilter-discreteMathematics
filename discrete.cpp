#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ifstream testh;
    ifstream tests;
    ifstream trainh;
    ifstream trains;
    testh.open("csv/test/dataset_ham_test20.csv");
    tests.open("csv/test/dataset_spam_test20.csv");
    trainh.open("csv/train/dataset_ham_train100.csv");
    trains.open("csv/train/dataset_spam_train100.csv");
    
    vector<vector<string>> ateh;
    vector<string> teh;
    vector<vector<string>> ates;
    vector<string> tes;
    vector<vector<string>> atrh;
    vector<string> trh;
    vector<vector<string>> atrs;
    vector<string> trs;
    string chars = "'~!@#$%^&*()-<>?/.,:\"";
    string s;
    string t;
    while(getline(testh,s)){
        for (char c: chars) {
            s.erase(std::remove(s.begin(), s.end(), c), s.end());
        }
        istringstream ss(s);
        while (getline(ss, t, ' ')){
            if(t == "")continue;
            
            for(int i=0; i<t.length(); i++){
                if(t.find("Subject") == -1){
                    break;
                }else if(t.find("Subject",i)<=i){
                    ateh.push_back(teh);
                    teh.clear();
                }
            }



            teh.push_back(t);   
        }
    


    }
    while(getline(tests,s)){
        for (char c: chars) {
            s.erase(std::remove(s.begin(), s.end(), c), s.end());
        }
        istringstream ss(s);
        while (getline(ss, t, ' ')){
            if(t == "")continue;

            for(int i=0; i<t.length(); i++){
                if(t.find("Subject") == -1){
                    break;
                }else if(t.find("Subject",i)<=i){
                    ates.push_back(tes);
                    tes.clear();
                }
            }
            tes.push_back(t);
        }
     
    }
    while(getline(trainh,s)){
        for (char c: chars) {
            s.erase(std::remove(s.begin(), s.end(), c), s.end());
        }
        istringstream ss(s);
        while (getline(ss, t, ' ')){
            if(t == "")continue;
            trh.push_back(t);
        }
        atrh.push_back(trh);
        trh.clear();
    }
    while(getline(trains,s)){
        for (char c: chars) {
            s.erase(std::remove(s.begin(), s.end(), c), s.end());
        }
        istringstream ss(s);
        while (getline(ss, t, ' ')){
            if(t == "")continue;
            trs.push_back(t);
        }
        atrs.push_back(trs);
        trs.clear();
    }
    int bunja = 0;
    int bunmo = 1;
    float per1;
    float per2;
    float temp;
    float k = 1;
    for(int i = 0; i < ateh.size(); i++){
        for(int j = 0; j < ateh[i].size(); j++){

            for(int a = 0; a < atrs.size(); a++){
                for(int b = 0; b < atrs[a].size(); b++){
                        if(ateh[i][j] == atrs[a][b]){
                            bunja ++;
                        }
                    bunmo ++;


                }
            }
            per1 = (float)bunja / (float)bunmo;
            bunja = 0;
            bunmo = 1;
            for(int a = 0; a < atrh.size(); a++){
                for(int b = 0; b < atrh[a].size(); b++){
                        if(ateh[i][j] == atrh[a][b]){
                            bunja ++;
                        }
                    bunmo ++;


                }
            }
            per2 = (float)bunja / (float)bunmo;
            temp = per1 + per2;
            if(temp == 0)temp = 1;
            if(per1/temp == 0){
                continue;
            }
            k *= (per1/temp);

        }
        cout << "Probability for r" << i<<" = "<<k << "\n";
        cout << "------Finding Probability Start-----\n------Finding Probability End-------\n";

        k = 1;

    }
    bunja = 0;
            bunmo = 1;
    for(int i = 0; i < ates.size(); i++){
        for(int j = 0; j < ates[i].size(); j++){

            for(int a = 0; a < atrs.size(); a++){
                for(int b = 0; b < atrs[a].size(); b++){
                        if(ates[i][j] == atrs[a][b]){
                            bunja ++;
                        }
                    bunmo ++;


                }
            }
            per1 = (float)bunja / (float)bunmo;
            bunja = 0;
            bunmo = 1;
            for(int a = 0; a < atrh.size(); a++){
                for(int b = 0; b < atrh[a].size(); b++){
                        if(ates[i][j] == atrh[a][b]){
                            bunja ++;
                        }
                    bunmo ++;


                }
            }
            per2 = (float)bunja / (float)bunmo;
            temp = per1 + per2;
            if(temp == 0)temp = 1;
            if(per1/temp == 0){
                continue;
            }
            k *= (per1/temp);

        }
        cout << "Probability for r" << i<<" = "<<k << "\n";
        cout << "------Finding Probability Start-----\n------Finding Probability End-------\n";

        k = 1;

    }

}