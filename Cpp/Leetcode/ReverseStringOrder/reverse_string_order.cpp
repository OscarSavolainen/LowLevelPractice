// WIP
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Include the <sstream> header for stringstream
#include <numeric> // for std::accumulate

std::vector<std::string> splitByWhiteSpace(const std::string& s) {
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
    if (nb_tokens <= 2) {
        if (nb_tokens == 2) {
            std::vector<std::string> vec;
            vec.push_back(inputs[1]);
            vec.push_back(inputs[0]);
            return vec;
        } else {  // only one value, it's already sorted
            return inputs;
        }

    } else {
        // We split the input by mid, and recurse
        //std::cout << "Here 2" << std::endl;
        std::vector<std::string> left_side(inputs.begin(), inputs.begin() + nb_tokens/2);
        std::vector<std::string> right_side(inputs.begin() + nb_tokens/2, inputs.end());
        
        std::vector<std::string> left_sorted_vec = splitByMid(left_side);
        std::vector<std::string> right_sorted_vec = splitByMid(right_side);

        //std::cout << "Here" << std::endl;
        
        // Concatenate
        right_sorted_vec.insert(right_sorted_vec.end(), left_sorted_vec.begin(), left_sorted_vec.end());

        //for (int i=0; i < right_sorted_vec.size(); i++) {
            //std::cout << right_sorted_vec[i] << " ";
        //}
        //std::cout << std::endl;
        return right_sorted_vec;

    }
    

}

std::string concatenateWithSpaces(const std::vector<std::string>& vec) {
    // Use std::accumulate to concatenate all strings with spaces in between
    return std::accumulate(vec.begin(), vec.end(), std::string(),
                           [](const std::string& a, const std::string& b) {
                               return a.empty() ? b : a + " " + b;
                           });
}

std::string reverseWords(std::string s) {
    std::vector<std::string>  tokens = splitByWhiteSpace(s);
    
    std::vector<std::string> vec = splitByMid(tokens);
    std::string result = concatenateWithSpaces(vec);
    return result;
    
}

int main() {
    std::string input = "The sky is blue and yellow and green";

    std::string res = reverseWords(input);
    std::cout << res << std::endl;
    return 0;
}
