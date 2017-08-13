class Solution {
public:
    string reverseWords(string s) {

        int start=0,end=0;
        string res=s;//初始化的时候不能设置为res="";
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==' '){
                //遇到空格则更新刚刚遍历过的上一个单词，倒序输出到res中
               end=i-1;//当前单词的end
               while(start<i)
                 res[start++]=s[end--];
               start=i+1;//更新下一个单词的start
            }

        }

        //处理最后一个单词
        end=s.size()-1;
        while(start<s.size())
            res[start++]=s[end--];

        return res;
    }
};
