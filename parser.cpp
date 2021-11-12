#include "iostream"
#include <bits/stdc++.h>
#include <cstring>
#include "fstream"
#include "direct.h"
using namespace std;
class Parser
{
public:
    enum words {GET  , POST};



    const string &getBody() const {
        return body;
    }

    int content_length;
    vector<pair<string,string>> headers;

    words getOpening() const {
        return opening;
    }


    const string &getDirectory() const {
        return directory;
    }

    int getContentLength() const {
        return content_length;
    }


    void parse_message(string s){
        parse_lines(main_parse(s,"\r\n"));
    }

private:
    words opening;
    string directory;
    string body;

    void parse_lines(vector<string> res){
        // parse first line
        vector<string> vec = main_parse(res[0]," ");
        for(auto s2: vec){
            if(s2=="GET") opening = GET;
            else if(s2 == "POST") opening = POST;
            else {
                directory = s2;
                directory = directory.substr(1);

                break;
            }
        }
        int j =1 ;
        // parse the headers
        while (res[j] != ""){
            vec = main_parse(res[j],":");
            headers.emplace_back(vec[0],vec[1]);
            if(vec[0]== "Content_Length"){
                content_length =stoi(vec[1]);
            }
            j++;

        }
        if(opening== POST)
         this->body = res[j+1];


    }
    vector<string> main_parse(string s,string delim){
        vector<string> res_vec;
        auto start = 0U;
        auto end = s.find(delim);
        while (end != std::string::npos)
        {
            res_vec.push_back(s.substr(start, end - start));
            start = end + delim.length();
            end = s.find(delim, start);
        }
        res_vec.push_back( s.substr(start, end));
       return res_vec;
    }

};