#include <string>
#include <vector>

using namespace std;

int romanToInt(string s) {
    //convert string to numbers
    //use case of each letter for all s indexes
    vector<int> num;
    
    for(int i=0; i<s.size(); i++){
        if (s[i] == 'I') {
            num.push_back(1);
            continue;
        }
        else if(s[i] == 'V'){
            num.push_back(5);
            continue;
        }
        else if(s[i] == 'X'){
            num.push_back(10);
            continue;
        }
        else if(s[i] == 'L'){
            num.push_back(50);
            continue;
        }
        else if(s[i] == 'C'){
            num.push_back(100);
            continue;
        }
        else if(s[i] == 'D'){
            num.push_back(500);
            continue;
        }
        else if(s[i] == 'M'){
            num.push_back(1000);
            continue;
        }
    }
    
    //iterate through numbers and check for smaller numbers first
    //if next number is bigger then subtract next number with current number
    //if number is smaller or the same the just add to accumulator
    //add numbers to cummulator
    int sum = 0;
    for(int i = num.size()-1; i>=0; i--) {
        if(i == num.size()-1){
            sum += num.at(i);
            continue;
        }
        
        if(num.at(i) < num.at(i+1)){
            sum -= num.at(i);
        }
        else{
            sum += num.at(i);
        }
    }
    
    return sum;
}

int main(void){
    string input = "III";
    romanToInt(input);

    return 0;
}