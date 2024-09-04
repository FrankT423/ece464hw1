#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;
int main(){
    ifstream it;
    string line;
    set<string> input;
    set <string> output;
    string var1;
    string gate;
    set<vector<string>> gater;
    vector<string> middle;
    string temp;
    //opens the text file
    it.open("bench.txt");
    if(!it.is_open()){
        cout<<"failed to open";
        return 0;
    }
    //reads each line in the text file, stores it in line
    while (getline(it,line)){
        size_t inputPos = line.find("INPUT");//looks for input then groups it as a input node 
        if(inputPos!=string::npos){
            size_t start = line.find('(', inputPos);
            size_t end = line.find(')', start);
            input.emplace(line.substr(start+1,end-start-1));      
        }
        else if( line.find("OUTPUT")!=string::npos){ //looks for output, then groupsit as an node
            size_t start = line.find('(', line.find("OUTPUT"));
            size_t end = line.find(')', start);
            output.emplace(line.substr(start+1,end-start-1));
        }
        else if( line.find("=")!=string::npos){//groups it as a gate, and determiens the parameters 
            stringstream s(line);//treats the string line as a text input
            s>>var1; 
            // gater.emplace(var1);
            size_t pos= line.find("=");//finds the start of the parameters
            size_t ended =line.find("(");
            gate= line.substr(pos+1,ended-pos-1);//extracts the paremeters
            temp=line.substr(ended);
            middle.push_back(var1);//a middle man vector to contain the gate info
            middle.push_back(gate);
            middle.push_back(temp);
            gater.emplace(middle);
            middle.clear();

        }

    }
    cout<<"here are all inputs:\n";
    for( string str: input){
        cout<<str<<endl;
    }
    cout<<endl;
    cout<<"here are all outputs:\n";
    for( string str: output){
        cout<<str<<endl;
    }
    cout<<endl;    
    cout<<"here are all gates and their input wires:\n";
    for( auto str: gater){
        cout<<str[0]<<" is the output node of a"<<str[1]<<" gate, with the input wire(s) being: "<< str[2]<<endl;
    }

    return 0;
}   