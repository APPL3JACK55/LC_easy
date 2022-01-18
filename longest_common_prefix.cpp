#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs.at(0);
    string strCompare = "";
    int firstInstance;
    
    
    for(int i=1; i<strs.size(); i++){
        if(prefix.size() == 0) break;
        
        strCompare = strs.at(i);
        if(strCompare.length() < prefix.length()){
            prefix = strCompare;
            continue;
        }
        
        //if if last instance of is not found then take away one character from prefix
        //if last instance is found then make sure its at the beginning of string
        //if prefix size is not 0 then keep going
        while(prefix.size() != 0){
            firstInstance = strCompare.find(prefix);
            if(firstInstance == 0){
                break;
            }
            prefix.erase(prefix.size()-1, 1);    
        }
    }
    
    return prefix;
}

int main(void){
    vector<string> input = {"flower","flow","flight"};

    longestCommonPrefix(input);

    return 0;
}