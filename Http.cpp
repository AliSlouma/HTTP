#include "iostream"
#include <bits/stdc++.h>
#include <cstring>
#include "fstream"
#include "direct.h"
#include "parser.cpp"
class Http{
public:
    Parser parser;
    string message="";

    Http(string s) {
        parser.parse_message(s);

        if(parser.getOpening() == Parser::GET)
            get_request(parser.getDirectory());
        else if (parser.getOpening() == Parser::POST)
            post_request(parser.getDirectory() , parser.getBody());
    }

    void get_request(string directory){
        std::ifstream file(directory, std::ios::in | std::ios::binary);
        if (!file.is_open()) {
            not_found_response();
            return;
        }
        file.seekg(0, std::ios::end);
        std::size_t length = file.tellg();
        file.seekg(0, std::ios::beg);
        if (file.fail()) {
            not_found_response();
            return;
        }
        std::string data(length, '\0');
        if (!file.read(&data[0], length)) {
            not_found_response();
            return;
        }
        ok_response(data);

    }

    void post_request(string directory, string body){
        string delim = "/";
        auto start = 0U;
        auto end = directory.find(delim);
        int j=0;
        string store="";
        while (end != std::string::npos)
        {
            string tmp =directory.substr(start, end - start);
            store+=tmp;
            char direct[store.size()];
            strcpy(direct,store.c_str());
            int c = mkdir( direct);
            start = end + delim.length();
            end = directory.find(delim, start);
            store+="/";
        }

        ofstream MyFile(directory,ios::binary);
        if(!MyFile.is_open()){
            not_found_response();
            return;
        }
        MyFile << body;
        if(!MyFile){
            not_found_response();
            return;
        }

        MyFile.close();
        ok_response("");
    }
    void ok_response(string data){
        string ok_msg = "HTTP/1.1 200 OK\r\n";
        string head = "";
//                    head+="Content-Type:text/html\r\n";
//                    head+=to_string(myText.size());
        head+="\r\n";
        this->message+=ok_msg;
        this->message += head;
        this->message+=data;
    }
    void not_found_response(){
        cout << "failed to open the file\n";
        string not_found = "HTTP/1.1 404 Not Found\r\n\r\n";
        this->message = not_found;
    }


};