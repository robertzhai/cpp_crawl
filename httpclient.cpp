//
//  httpclient.cpp
//  CrawlIpCn
//
//

#include "httpclient.hpp"
#include <iostream>
#include <ostream>
#include <cstdio>
#include <curl/curl.h>
#include <vector>

#include "StrUtil.h"

size_t HttpClient::OnWriteData(void* buffer, size_t size, size_t nmemb,
		void* lpVoid) {
	std::string* str = dynamic_cast<std::string*>((std::string *) lpVoid);
	if ( NULL == str || NULL == buffer) {
		return -1;
	}
	char* pData = (char*) buffer;
	str->append(pData, size * nmemb);
	return nmemb;
}

std::string HttpClient::get(std::string & url, std::vector<std::string> & header) {

	CURL *curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	std::string apiRes = "";
	curl = curl_easy_init();
	struct curl_slist *headerList = NULL;
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void * )&apiRes);
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);
		curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
		if (StrUtil::isHttps(url)) {
			std::cout<<" req type https\n";
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		}

		if(header.size() > 0) {

			for(auto head: header) {
				headerList = curl_slist_append(headerList, head.c_str());
			}
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
		}

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));

		/* always cleanup */
		if(headerList != NULL) {
			 curl_slist_free_all(headerList);
			 headerList = NULL;
		}
		curl_easy_cleanup(curl);
	}
	return apiRes;
}
