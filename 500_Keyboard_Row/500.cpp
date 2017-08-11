class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rows[] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> res;
        for(int i=0;i<words.size();i++){
            string cur_str=words[i] ;

            int first_row=0;
            for(;first_row<3;first_row++){
                 std::size_t found=rows[first_row].find(cur_str[0]);
                 if (found!=std::string::npos)
                    break;
            }

            int j=0;
            for (j=1;j<cur_str.length();j++){
                 std::size_t found=rows[first_row].find(cur_str[j]);
                 if (found==std::string::npos)
                    break;
            }

            if(j==cur_str.length())
                res.push_back(cur_str);
        }

        return res;

    }
};
