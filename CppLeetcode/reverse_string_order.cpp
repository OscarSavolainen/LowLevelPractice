// WIP
std::vector<std::string> splitByWhiteSpace(const string& s) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(s);
    while (std::getline(ss, token, ' ')) {
        if (!token.empty()){
            tokens.push_back(token);
        }
    }
    return tokens;
}

std::vector<std::string> splitByMid(std::vector<std::string> inputs) {
    size_t nb_tokens = inputs.size();
    if (nb_tokens == 2) {
        std::vec<std::string> vec;
        vec.push_back(inputs[1])
        vec.push_back(inputs[0])
        return vec;
    } else {
        // We split the input by mid, and recurse
        splitByMid(inputs up to mid)

    }
    

}
class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string>  tokens = splitByWhiteSpace(s);
        
        return s;
        
    }
};