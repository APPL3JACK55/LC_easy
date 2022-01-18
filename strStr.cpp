#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    if(needle.size() == 0) return 0;
    
    //iterate through string
    //look for first char if first char found the start for loop looking for rest of needle
    for(int i=0; i<haystack.size(); i++){
        if(haystack[i] == needle[0]){
            int j;
            for(j=0; j<needle.size(); j++){
                if(haystack.size()<i+needle.size()) break;
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == needle.size()) return i;
        }
    }
    return -1;
}

int main(void){
    string haystack = "hello";
    string needle = "ll";
    strStr(haystack, needle);
    return 0;
}