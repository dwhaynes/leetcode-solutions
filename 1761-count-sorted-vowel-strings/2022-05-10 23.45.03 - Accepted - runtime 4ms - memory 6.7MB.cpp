class Solution {
    map<pair<int,int>,int> counts;
    int countVowels(int n, int vowels){
        if(n == 1) return vowels;
        if(vowels == 1) return 1;
        if(counts.find({n,vowels}) != counts.end()) return counts[{n,vowels}];
        counts[{n,vowels}] = countVowels(n-1,vowels) + countVowels(n,vowels-1);
        return counts[{n,vowels}];
    }
public:
    int countVowelStrings(int n) {
        return countVowels(n,5);
    }
};