//
//  httpclient.hpp
//  CrawlIpCn
//
//

#ifndef httpclient_hpp
#define httpclient_hpp

#include <stdio.h>
#include <iostream>


class HttpClient {
    
public:
    HttpClient() {
        
    }
    ~HttpClient(){
        
    }
    std::string get(std::string & url, std::vector<std::string> & header);

    static size_t OnWriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid);

};

#endif /* httpclient_hpp */
