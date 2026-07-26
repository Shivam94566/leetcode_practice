class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::vector<std::string> morse = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        };
        
        std::unordered_set<std::string> uniqueTransformations;
        
        for (const std::string& word : words) {
            std::string transformation = "";
            for (char c : word) {
                transformation += morse[c - 'a'];
            }
            uniqueTransformations.insert(transformation);
        }
        
        return uniqueTransformations.size();
    }
};